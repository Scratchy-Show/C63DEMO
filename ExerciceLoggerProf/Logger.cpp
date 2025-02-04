#include <iostream>  // Pour afficher des messages dans la console
#include <fstream>   // Pour gérer l'écriture dans un fichier
#include "Logger.h"  // Inclusion du fichier d'en-tête contenant la classe Logger
#include <cassert>   // Pour utiliser assert() afin de vérifier des conditions

using namespace LoopEngine;  // Utilisation du namespace LoopEngine

// Constructeur de la classe Logger
// Initialise le niveau de log et active/désactive la journalisation dans la console et dans un fichier
LoopEngine::Logger::Logger(const TLevel InLoggingLevel, bool InConsoleTraceActive, bool InFileTraceActive)
    : _LoggingLevel(InLoggingLevel)  // Initialise le niveau de log minimal
{
    this->ActivateFileTrace(InFileTraceActive);  // Active/désactive l'écriture dans un fichier
    this->ActivateConsoleTrace(InConsoleTraceActive);  // Active/désactive l'affichage des logs dans la console
}

// Destructeur : ferme le fichier de log et libère la mémoire
Logger::~Logger()
{
    if (_ptrFileStream != nullptr)  // Vérifie si un fichier de log est ouvert
    {
        this->TryCloseFile();  // Ferme proprement le fichier
    }
}

// Active ou désactive la journalisation dans un fichier avec un fichier spécifique
void LoopEngine::Logger::ActivateFileTrace(bool InIsActive, const string& InFileName)
{
    if (InIsActive != _IsFileTraceActive)  // Vérifie si l'état change
    {
        this->SetFileTraceName(InFileName);  // Définit le nom du fichier de log
        this->ActivateFileTrace(InIsActive); // Active/désactive l'écriture dans le fichier
    }
}

// Active ou désactive la journalisation dans un fichier
void LoopEngine::Logger::ActivateFileTrace(bool InIsActive)
{
    if (InIsActive != _IsFileTraceActive)  // Vérifie si un changement d'état est nécessaire
    {
        _IsFileTraceActive = InIsActive;
        _IsFileTraceActive ? this->TryOpenFile() : this->TryCloseFile();  // Ouvre ou ferme le fichier
    }
}

// Définit le nom du fichier où seront stockés les logs
void LoopEngine::Logger::SetFileTraceName(const string InFileTraceName)
{
    // Vérifie si la journalisation dans un fichier est active avant de modifier le nom
    if (_IsFileTraceActive || _ptrFileStream != nullptr)
    {
        this->Log("Impossible de changer le nom du fichier de trace tant que la trace est active. Opération annulée.", TLevel::eERROR);
        return;
    }

    // Vérifie que le nom du fichier n'est pas vide
    if (_TraceFileName.empty())
    {
        this->Log("Le nom du fichier de trace ne peut pas être vide.", TLevel::eERROR);
        return;
    }

    _TraceFileName = InFileTraceName;  // Met à jour le nom du fichier de journalisation
}

// Active ou désactive l'affichage des logs dans la console
void LoopEngine::Logger::ActivateConsoleTrace(bool InIsActive)
{
    _IsConsoleTraceActive = InIsActive;
}

// Modifie le niveau minimal de log pour qu'un message soit affiché ou enregistré
void Logger::SetLoggingLevel(const TLevel InLoggingLevel)
{
    _LoggingLevel = InLoggingLevel;
}

// Définit le niveau de gravité à partir duquel le programme doit être interrompu
void LoopEngine::Logger::SetAbortLevel(const TLevel InAbortLevel)
{
    _AbortLevel = InAbortLevel;
}

// Enregistre un message dans la console et/ou un fichier si le niveau est suffisant
void Logger::Log(string msg, const TLevel InLoggingLevel) const
{
    // Vérifie si le niveau du message est supérieur ou égal au niveau minimal défini
    if (InLoggingLevel >= _LoggingLevel)
    {
        // Affiche le message dans la console si activé
        if (_IsConsoleTraceActive)
        {
            std::cout << msg << std::endl;
        }

        // Écrit le message dans un fichier si activé
        if (_IsFileTraceActive && _ptrFileStream != nullptr)
        {
            *_ptrFileStream << msg << std::endl;
        }
    }

    // Vérifie si le niveau de gravité dépasse le seuil d'interruption et stoppe le programme si nécessaire
    assert(InLoggingLevel < _AbortLevel);
}

// Tente d'ouvrir le fichier de journalisation
bool LoopEngine::Logger::TryOpenFile()
{
    // Vérifie si un fichier est déjà ouvert
    if (_ptrFileStream != nullptr)
    {
        this->Log("Impossible d'ouvrir à nouveau le fichier de journalisation.", TLevel::eERROR);
        return false;
    }

    // Crée un flux de fichier et ouvre le fichier spécifié
    _ptrFileStream = new std::ofstream(_TraceFileName);
    if (_ptrFileStream->is_open())  // Vérifie si le fichier est bien ouvert
    {
        this->Log("Fichier de journalisation ouvert", TLevel::eINFO);
    }
    else  // Gestion des erreurs en cas d'échec d'ouverture
    {
        this->Log("Le fichier de journalisation n'a pas pu être ouvert.", TLevel::eERROR);
        delete _ptrFileStream;
        _ptrFileStream = nullptr;
        return false;
    }
    return true;
}

// Tente de fermer le fichier de journalisation proprement
bool LoopEngine::Logger::TryCloseFile()
{
    if (_ptrFileStream == nullptr || !_ptrFileStream->is_open())  // Vérifie si le fichier est déjà fermé
    {
        this->Log("Impossible de fermer le fichier de journalisation.", TLevel::eERROR);
        return false;
    }

    _ptrFileStream->close();  // Ferme le fichier
    delete _ptrFileStream;  // Libère la mémoire allouée
    _ptrFileStream = nullptr;

    this->Log("Fichier de journalisation fermé.", TLevel::eINFO);
    return true;
}
