#include "Logger.h"

using namespace LoopEngine;

// Constructeur de la classe Logger
// Initialise le niveau de log et active/désactive la journalisation sur la console et dans un fichier
Logger::Logger(const TLevel InLoggingLevel, bool InConsoleTraceActive, bool InFileTraceActive)
{
    this->SetLoggingLevel(InLoggingLevel); // Définit le niveau de log minimum
    this->ActivateConsoleTrace(InConsoleTraceActive); // Active/désactive la console
    this->ActivateFileTrace(InFileTraceActive); // Active/désactive l'écriture dans un fichier
}

// Destructeur : ferme le fichier de log et libère la mémoire
Logger::~Logger()
{
    this->TryCloseFile(); // Ferme le fichier si nécessaire

    delete this->_ptrFileStream; // Libère la mémoire allouée pour le fichier
    this->_ptrFileStream = nullptr;
}

// Active ou désactive l'affichage des logs dans la console
void Logger::ActivateConsoleTrace(bool InIsActive)
{
	this->_IsConsoleTraceActive = InIsActive;
}

// Définit le niveau de log minimum pour afficher un message
void Logger::SetLoggingLevel(const TLevel InLoggingLevel)
{
	this->_LoggingLevel = InLoggingLevel;
}

// Enregistre un message dans la console et/ou dans un fichier si le niveau est suffisant
void Logger::Log(string msg, const TLevel InLoggingLevel) const
{
    // Vérifie si le niveau du message est supérieur ou égal au niveau minimal
	if (InLoggingLevel >= this->_LoggingLevel) 
	{
		std::string level = std::string();
		switch (InLoggingLevel) 
		{
			case 0: level = "Info"; break;
			case 1: level = "Warning"; break;
			case 2: level = "Debug"; break;
			case 3: level = "Error"; break;
			default: level = "Unknown"; break;
		}

        // Formate le message avec le niveau de log
        msg = level + ": " + msg + "\n";

        // Affiche le message dans la console si activé
        if (this->_IsConsoleTraceActive) 
        {
            std::cout << msg;
        }

        // Écrit le message dans un fichier si activé
        if (this->_IsFileTraceActive && this->_ptrFileStream != nullptr) 
        {
            *this->_ptrFileStream << msg;
        }

        // Vérifie si le programme doit être interrompu
        this->ExitLogger(InLoggingLevel);
	}
}

// Active/désactive la journalisation dans un fichier
void Logger::ActivateFileTrace(bool InIsActive)
{
	if (this->_IsFileTraceActive != InIsActive) 
	{
		this->_IsFileTraceActive = InIsActive;
		this->_IsFileTraceActive ? this->TryOpenFile() : this->TryCloseFile();
	}
}

// Active/désactive la journalisation et définit le fichier de sortie
void Logger::ActivateFileTrace(bool InIsActive, const string& InFileName)
{
	this->ActivateFileTrace(InIsActive);
	this->SetFileTraceName(InFileName);
}

// Définit le fichier où seront écrits les logs
void Logger::SetFileTraceName(const string InFileTraceName)
{
	if (!InFileTraceName.length()) 
	{
		// Log une erreur si le nom de fichier est vide
		this->Log("Le chemin du fichier ne peut pas être vide !", this->TLevel::eERROR);
		this->ExitLogger(this->TLevel::eERROR);
		return;
	}

	if (this->_IsFileTraceActive) 
	{
		// Log une erreur si on tente de changer le fichier alors que la journalisation est active
		this->Log("Impossible de changer le nom du fichier de journalisation tant que celui-ci est actif !", this->TLevel::eERROR);
		this->ExitLogger(this->TLevel::eERROR);
		return;
	}

	this->_TraceFileName = InFileTraceName;
}

// Définit le niveau à partir duquel l'application doit s'interrompre
void Logger::SetAbortLevel(const TLevel InAbortLevel)
{
	this->_AbortLevel = InAbortLevel;
}

// Tente d'ouvrir le fichier de journalisation
bool Logger::TryOpenFile()
{
	this->_ptrFileStream = new std::ofstream(this->_TraceFileName);

	return this->_ptrFileStream->is_open();
}

// Tente de fermer le fichier de journalisation
bool Logger::TryCloseFile()
{
	if (this->_ptrFileStream != nullptr) 
	{
		this->_ptrFileStream->close();
		return true;
	}
	return false;
}

// Vérifie si l'application doit être arrêtée en fonction du niveau du log
void Logger::ExitLogger(const TLevel InLoggingLevel) const
{
	assert(InLoggingLevel < this->_AbortLevel);
}