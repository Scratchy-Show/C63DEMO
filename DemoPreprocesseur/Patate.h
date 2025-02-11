//#pragma once  // Cette ligne est comment�e. #pragma once est une directive de pr�processeur qui garantit qu'un fichier d'en-t�te n'est inclus qu'une seule fois dans chaque unit� de traduction.


// Remplace #pragma once
//#ifndef __PATATE_H  // D�but d'une directive conditionnelle. Si __PATATE_H n'est pas d�fini, le code entre #ifndef et #endif sera ex�cut�.
 //#define __PATATE_H  // D�finit __PATATE_H pour indiquer que le fichier a �t� inclus, et que ce code ne doit plus �tre r�inclus.
 //#endif  // Fin de la directive conditionnelle, en fait comment�e ici mais elle est parfois utilis�e pour �viter les inclusions multiples.

#ifndef __PATATE_H  // V�rifie si __PATATE_H n'a pas encore �t� d�fini.
#define __PATATE_H  // D�finit __PATATE_H, ce qui signifie que ce fichier d'en-t�te a d�j� �t� inclus et qu'il ne sera pas r�inclus.

// Define: Cr�e des variables pr�-processeur (macros)
#define GAME_RELEASE  // D�finit la macro GAME_RELEASE, cette ligne peut �tre utilis�e plus tard pour conditionner le code selon l'�tat de compilation (version de production ou d�bogage).
// Copie colle la valeur
#define PI 3.1415f  // D�finit la constante PI � 3.1415f (utilis� pour des calculs math�matiques, comme le calcul de la circonf�rence).

#define FORMULE_CIRCONFERENCE(r) 2.f*PI*r  // D�finit une macro qui calcule la circonf�rence d'un cercle en fonction de son rayon 'r'. Utilise PI pour effectuer le calcul.
#define ADDITION(a,b) a+b  // D�finit une macro qui effectue l'addition de deux valeurs 'a' et 'b'.

// Conneries
// #define true false  // (Comment�e) Cela pourrait remplacer la valeur bool�enne 'true' par 'false', ce qui rendrait tout programme utilisant 'true' se comporter de mani�re erron�e.
// #define while while(true)  // (Comment�e) Cela transformerait chaque boucle 'while' en une boucle infinie. C'est une "connerie" car elle causerait un comportement ind�sirable.

class Patate  // D�claration de la classe "Patate". Elle est vide ici, mais pourrait �tre remplie avec des membres (variables, fonctions, etc.).
{

};

#endif  // Fin de la directive conditionnelle #ifndef __PATATE_H, ce qui marque la fin du bloc de code qui ne sera inclus qu'une seule fois.
