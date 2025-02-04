#include <iostream>  // Pour afficher des messages dans la console
#include <fstream>   // Pour g�rer l'�criture dans un fichier
#include "Logger.h"  // Inclusion du fichier d'en-t�te contenant la classe Logger
#include <cassert>   // Pour utiliser assert() afin de v�rifier des conditions

using namespace LoopEngine;  // Utilisation du namespace LoopEngine

// Constructeur de la classe Logger
// Initialise le niveau de log et active/d�sactive la journalisation dans la console et dans un fichier
LoopEngine::Logger::Logger(const TLevel InLoggingLevel, bool InConsoleTraceActive, bool InFileTraceActive)
    : _LoggingLevel(InLoggingLevel)  // Initialise le niveau de log minimal
{
    this->ActivateFileTrace(InFileTraceActive);  // Active/d�sactive l'�criture dans un fichier
    this->ActivateConsoleTrace(InConsoleTraceActive);  // Active/d�sactive l'affichage des logs dans la console
}

// Destructeur : ferme le fichier de log et lib�re la m�moire
Logger::~Logger()
{
    if (_ptrFileStream != nullptr)  // V�rifie si un fichier de log est ouvert
    {
        this->TryCloseFile();  // Ferme proprement le fichier
    }
}

// Active ou d�sactive la journalisation dans un fichier avec un fichier sp�cifique
void LoopEngine::Logger::ActivateFileTrace(bool InIsActive, const string& InFileName)
{
    if (InIsActive != _IsFileTraceActive)  // V�rifie si l'�tat change
    {
        this->SetFileTraceName(InFileName);  // D�finit le nom du fichier de log
        this->ActivateFileTrace(InIsActive); // Active/d�sactive l'�criture dans le fichier
    }
}

// Active ou d�sactive la journalisation dans un fichier
void LoopEngine::Logger::ActivateFileTrace(bool InIsActive)
{
    if (InIsActive != _IsFileTraceActive)  // V�rifie si un changement d'�tat est n�cessaire
    {
        _IsFileTraceActive = InIsActive;
        _IsFileTraceActive ? this->TryOpenFile() : this->TryCloseFile();  // Ouvre ou ferme le fichier
    }
}

// D�finit le nom du fichier o� seront stock�s les logs
void LoopEngine::Logger::SetFileTraceName(const string InFileTraceName)
{
    // V�rifie si la journalisation dans un fichier est active avant de modifier le nom
    if (_IsFileTraceActive || _ptrFileStream != nullptr)
    {
        this->Log("Impossible de changer le nom du fichier de trace tant que la trace est active. Op�ration annul�e.", TLevel::eERROR);
        return;
    }

    // V�rifie que le nom du fichier n'est pas vide
    if (_TraceFileName.empty())
    {
        this->Log("Le nom du fichier de trace ne peut pas �tre vide.", TLevel::eERROR);
        return;
    }

    _TraceFileName = InFileTraceName;  // Met � jour le nom du fichier de journalisation
}

// Active ou d�sactive l'affichage des logs dans la console
void LoopEngine::Logger::ActivateConsoleTrace(bool InIsActive)
{
    _IsConsoleTraceActive = InIsActive;
}

// Modifie le niveau minimal de log pour qu'un message soit affich� ou enregistr�
void Logger::SetLoggingLevel(const TLevel InLoggingLevel)
{
    _LoggingLevel = InLoggingLevel;
}

// D�finit le niveau de gravit� � partir duquel le programme doit �tre interrompu
void LoopEngine::Logger::SetAbortLevel(const TLevel InAbortLevel)
{
    _AbortLevel = InAbortLevel;
}

// Enregistre un message dans la console et/ou un fichier si le niveau est suffisant
void Logger::Log(string msg, const TLevel InLoggingLevel) const
{
    // V�rifie si le niveau du message est sup�rieur ou �gal au niveau minimal d�fini
    if (InLoggingLevel >= _LoggingLevel)
    {
        // Affiche le message dans la console si activ�
        if (_IsConsoleTraceActive)
        {
            std::cout << msg << std::endl;
        }

        // �crit le message dans un fichier si activ�
        if (_IsFileTraceActive && _ptrFileStream != nullptr)
        {
            *_ptrFileStream << msg << std::endl;
        }
    }

    // V�rifie si le niveau de gravit� d�passe le seuil d'interruption et stoppe le programme si n�cessaire
    assert(InLoggingLevel < _AbortLevel);
}

// Tente d'ouvrir le fichier de journalisation
bool LoopEngine::Logger::TryOpenFile()
{
    // V�rifie si un fichier est d�j� ouvert
    if (_ptrFileStream != nullptr)
    {
        this->Log("Impossible d'ouvrir � nouveau le fichier de journalisation.", TLevel::eERROR);
        return false;
    }

    // Cr�e un flux de fichier et ouvre le fichier sp�cifi�
    _ptrFileStream = new std::ofstream(_TraceFileName);
    if (_ptrFileStream->is_open())  // V�rifie si le fichier est bien ouvert
    {
        this->Log("Fichier de journalisation ouvert", TLevel::eINFO);
    }
    else  // Gestion des erreurs en cas d'�chec d'ouverture
    {
        this->Log("Le fichier de journalisation n'a pas pu �tre ouvert.", TLevel::eERROR);
        delete _ptrFileStream;
        _ptrFileStream = nullptr;
        return false;
    }
    return true;
}

// Tente de fermer le fichier de journalisation proprement
bool LoopEngine::Logger::TryCloseFile()
{
    if (_ptrFileStream == nullptr || !_ptrFileStream->is_open())  // V�rifie si le fichier est d�j� ferm�
    {
        this->Log("Impossible de fermer le fichier de journalisation.", TLevel::eERROR);
        return false;
    }

    _ptrFileStream->close();  // Ferme le fichier
    delete _ptrFileStream;  // Lib�re la m�moire allou�e
    _ptrFileStream = nullptr;

    this->Log("Fichier de journalisation ferm�.", TLevel::eINFO);
    return true;
}
