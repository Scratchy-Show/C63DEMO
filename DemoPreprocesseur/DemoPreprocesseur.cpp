#include <iostream>
#include "Patate.h"
// On évite une erreure de compilation grâce au #pragma once
#include "Patate.h"

using namespace std;

// #include copie-colle le contenu entier d'un fichier
// En pratique, sert à importer la déclaration de symboles
int main()
{
    // Utilisation d'une variable standard
    Patate p;
    #include "NeFaisPasCa.h";
    std::cout << "Hello World!\n";
    std::cout << "PI: " << PI << endl;
    std::cout << "Circonference de 4.0f: " << FORMULE_CIRCONFERENCE(4.0f) << endl;
    //std::cout << "Circonference de Coucou!: " << FORMULE_CIRCONFERENCE("Coucou!") << endl;


    std::cout << "Fichier: " << __FILE__ << " Ligne: " << __LINE__ << std::endl;


// Détruie la variable
#undef GAME_RELEASE

// Décide s'il met ou non ce code et ensuite il compile
#ifdef GAME_RELEASE
    std::cout << "GAME RELEASE" << endl;
#else
    std::cout << "GAME DEBUG" << endl;
#endif

// Décide s'il met ou non ce code et ensuite il compile
#ifndef STEAM_VERSION
    std::cout << "N'est pas sur Steam" << endl;
#endif
}