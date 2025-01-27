#include "Logger.h"

using namespace LoopEngine;

Logger::Logger(const TLevel InLoggingLevel, bool InConsoleTraceActive, bool InFileTraceActive)
{
	TLevel _InLoggingLevel = InLoggingLevel;
	bool _InConsoleTraceActive = InConsoleTraceActive;
	bool _InFileTraceActive = InFileTraceActive;
}

Logger::~Logger()
{
	if (_ptrFileStream != nullptr)
	{
		delete _ptrFileStream;
		_ptrFileStream = nullptr;
	}
}

void Logger::ActivateConsoleTrace(bool InIsActive)
{
	if (InIsActive != _IsConsoleTraceActive)
	{
		_IsConsoleTraceActive = InIsActive;
	}
}

void Logger::SetLoggingLevel(const TLevel InLoggingLevel)
{
	_LoggingLevel = InLoggingLevel;
}

void Logger::Log(string msg, const TLevel InLoggingLevel) const
{

}

void Logger::ActivateFileTrace(bool InIsActive)
{
	if (InIsActive != _IsFileTraceActive)
	{
		_IsFileTraceActive = InIsActive;
	}
}

void Logger::ActivateFileTrace(bool InIsActive, const string& InFileName)
{

}

void Logger::SetFileTraceName(const string InFileTraceName)
{
	_TraceFileName = InFileTraceName;
}

void Logger::SetAbortLevel(const TLevel InAbortLevel)
{
	_AbortLevel = InAbortLevel;
}

bool Logger::TryOpenFile()
{
	return false;
}

bool Logger::TryCloseFile()
{
	return false;
}
