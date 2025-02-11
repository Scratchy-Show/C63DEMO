//#pragma once  // Cette ligne est commentée. #pragma once est une directive de préprocesseur qui garantit qu'un fichier d'en-tête n'est inclus qu'une seule fois dans chaque unité de traduction.


// Remplace #pragma once
//#ifndef __PATATE_H  // Début d'une directive conditionnelle. Si __PATATE_H n'est pas défini, le code entre #ifndef et #endif sera exécuté.
 //#define __PATATE_H  // Définit __PATATE_H pour indiquer que le fichier a été inclus, et que ce code ne doit plus être réinclus.
 //#endif  // Fin de la directive conditionnelle, en fait commentée ici mais elle est parfois utilisée pour éviter les inclusions multiples.

#ifndef __PATATE_H  // Vérifie si __PATATE_H n'a pas encore été défini.
#define __PATATE_H  // Définit __PATATE_H, ce qui signifie que ce fichier d'en-tête a déjà été inclus et qu'il ne sera pas réinclus.

// Define: Crée des variables pré-processeur (macros)
#define GAME_RELEASE  // Définit la macro GAME_RELEASE, cette ligne peut être utilisée plus tard pour conditionner le code selon l'état de compilation (version de production ou débogage).
// Copie colle la valeur
#define PI 3.1415f  // Définit la constante PI à 3.1415f (utilisé pour des calculs mathématiques, comme le calcul de la circonférence).

#define FORMULE_CIRCONFERENCE(r) 2.f*PI*r  // Définit une macro qui calcule la circonférence d'un cercle en fonction de son rayon 'r'. Utilise PI pour effectuer le calcul.
#define ADDITION(a,b) a+b  // Définit une macro qui effectue l'addition de deux valeurs 'a' et 'b'.

// Conneries
// #define true false  // (Commentée) Cela pourrait remplacer la valeur booléenne 'true' par 'false', ce qui rendrait tout programme utilisant 'true' se comporter de manière erronée.
// #define while while(true)  // (Commentée) Cela transformerait chaque boucle 'while' en une boucle infinie. C'est une "connerie" car elle causerait un comportement indésirable.

class Patate  // Déclaration de la classe "Patate". Elle est vide ici, mais pourrait être remplie avec des membres (variables, fonctions, etc.).
{

};

#endif  // Fin de la directive conditionnelle #ifndef __PATATE_H, ce qui marque la fin du bloc de code qui ne sera inclus qu'une seule fois.
