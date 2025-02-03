#include <iostream>
#include <fstream>
#include "Logger.h"
#include <cassert>

using namespace LoopEngine;

LoopEngine::Logger::Logger(const TLevel InLoggingLevel, bool InConsoleTraceActive, bool InFileTraceActive)
	:_LoggingLevel(InLoggingLevel)
{
	ActivateFileTrace(InFileTraceActive);
	ActivateConsoleTrace(InConsoleTraceActive);
}

Logger::~Logger()
{
	if (_ptrFileStream != nullptr)
	{
		TryCloseFile();
	}
}

void LoopEngine::Logger::ActivateFileTrace(bool InIsActive, const string& InFileName)
{
	if (InIsActive != _IsFileTraceActive)
	{
		SetFileTraceName(InFileName);
		ActivateFileTrace(InIsActive);
	}
}

void LoopEngine::Logger::ActivateFileTrace(bool InIsActive)
{
	if (InIsActive != _IsFileTraceActive)
	{
		_IsFileTraceActive = InIsActive;
		_IsFileTraceActive ? TryOpenFile() : TryCloseFile();
	}
}

void LoopEngine::Logger::SetFileTraceName(const string InFileTraceName)
{
	if (_IsFileTraceActive || _ptrFileStream != nullptr)
	{
		Log("Impossible de changer le nom du fichier de trace tant que la trace est active. Opération annulée.", TLevel::eERROR);
		return;
	}

	if (_TraceFileName.empty())
	{
		Log("Le nom du fichier de trace ne peut pas être vide.", TLevel::eERROR);
		return;
	}
	_TraceFileName = InFileTraceName;
}

void LoopEngine::Logger::ActivateConsoleTrace(bool InIsActive)
{
	_IsConsoleTraceActive = InIsActive;
}

void Logger::SetLoggingLevel(const TLevel InLoggingLevel)
{
	_LoggingLevel = InLoggingLevel;
}

void LoopEngine::Logger::SetAbortLevel(const TLevel InAbortLevel)
{
	_AbortLevel = InAbortLevel;
}

void Logger::Log(string msg, const TLevel InLoggingLevel) const
{
	if (InLoggingLevel >= _LoggingLevel)
	{
		if (_IsConsoleTraceActive)
		{
			cout << msg << endl;
		}
		if (_IsFileTraceActive && _ptrFileStream != nullptr)
		{
			*_ptrFileStream << msg << endl;
		}
	}

	assert(InLoggingLevel < _AbortLevel);
}

bool LoopEngine::Logger::TryOpenFile()
{
	if (_ptrFileStream != nullptr)
	{
		this->Log("Impossible d'ouvrir à nouveau le fichier de journalisation.", TLevel::eERROR);
		return false;
	}

	_ptrFileStream = new ofstream(_TraceFileName);
	if (_ptrFileStream->is_open())
	{
		this->Log("Fichier de journalisation ouvert", TLevel::eINFO);
	}
	else
	{
		this->Log("Le fichier de journalisation n'a pas pu être ouvert.", TLevel::eERROR);
		delete _ptrFileStream;
		_ptrFileStream = nullptr;
		return false;
	}
	return true;
}

bool LoopEngine::Logger::TryCloseFile()
{
	if (_ptrFileStream == nullptr || !_ptrFileStream->is_open())
	{
		this->Log("Impossible de fermer le fichier de journalisation.", TLevel::eERROR);
		return false;
	}
	_ptrFileStream->close();
	delete _ptrFileStream;
	_ptrFileStream = nullptr;
	this->Log("Fichier de journalisation fermé.", TLevel::eINFO);
	return true;
}