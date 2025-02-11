#include <iostream> // Inclut la bibliothèque standard pour l'entrée et la sortie (ex. cin, cout).
#include "Patate.h"
// On évite une erreure de compilation grâce au #pragma once
#include "Patate.h" // Inclut encore une fois "Patate.h", ce qui est redondant, mais #pragma once protège contre la duplication d'inclusion.

using namespace std; // Permet d'utiliser directement les symboles du namespace standard (comme cout, endl) sans devoir écrire std:: à chaque fois.

// #include copie-colle le contenu entier d'un fichier
// En pratique, sert à importer la déclaration de symboles
int main()
{
    // Utilisation d'une variable standard
    Patate p;  // Crée un objet de la classe "Patate"
    #include "NeFaisPasCa.h";  // Inclut un fichier "NeFaisPasCa.h" dans le code.
    std::cout << "Hello World!\n";
    std::cout << "PI: " << PI << endl;  // Affiche la valeur de la constante PI
    std::cout << "Circonference de 4.0f: " << FORMULE_CIRCONFERENCE(4.0f) << endl;  // Calcule et affiche la circonférence d'un cercle de rayon 4.0f en utilisant la macro/formule FORMULE_CIRCONFERENCE.
    //std::cout << "Circonference de Coucou!: " << FORMULE_CIRCONFERENCE("Coucou!") << endl;


    std::cout << "Fichier: " << __FILE__ << " Ligne: " << __LINE__ << std::endl;

    // Détruie la variable
    #undef GAME_RELEASE

    // Décide s'il met ou non ce code et ensuite il compile
    // Condition de compilation : ce bloc sera inclus seulement si "GAME_RELEASE" est défini.
    #ifdef GAME_RELEASE
        std::cout << "GAME RELEASE" << endl; // Affiche "GAME RELEASE" si "GAME_RELEASE" est défini.
    #else
        std::cout << "GAME DEBUG" << endl; // Affiche "GAME DEBUG" si "GAME_RELEASE" n'est pas défini.
    #endif

    // Décide s'il met ou non ce code et ensuite il compile
    // Condition de compilation : ce bloc sera inclus seulement si "STEAM_VERSION" n'est pas défini.
    #ifndef STEAM_VERSION
        std::cout << "N'est pas sur Steam" << endl; // Affiche "N'est pas sur Steam" si "STEAM_VERSION" n'est pas défini.
    #endif
}