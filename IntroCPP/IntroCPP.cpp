//Par défaut, <> signifient d'importer de la librarie standard (ISO)
//ou libraries systèmes (Windows, Linux, MacOS,etc).
// Avec <> se sont des librairies standards, avec des "" ces mes fichiers
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    //////////////////
    //Entiers
    //////////////////
    int unEntier = 0;
    __int64 unEntierSur8Octets = 0xFFFFFFFFFF; //Possible d'assigner en notation hexadécimale
    unsigned int unEntierPositif = 0b0001101;  //Possible d'assigner en notation binaire

    //////////////////
    //Points flottants
    //////////////////
    float hp = 0.f; //Le f signifie float
    double magic = 0.; //rien signifie double

    //////////////////
    //Caractères
    //////////////////
    char unCaractere = 'b';
    char maPhrase[20] = "Bonjour!\0";

    //////////////////
    //Booléen
    //////////////////
    bool porteOuverte = true;

    //////////////////
    //auto
    //////////////////
    //Généralement peu utilisé, sauf dans des cas spécifique avec des itérateurs dont les noms sont très longs.
    auto devineMonType = 0.f;

    //////////////////
    //enum
    //////////////////
    enum NiveauEtudiant
    {
        eMeh = 0,
        eOk, // sera = 1
        eBien, //sera 2
        eSuper, //sera 3
        eExcellent, //sera 4

        eMax, //sera 5 pratique, vous devez toujours le faire.
    };
    NiveauEtudiant niveauC63 = NiveauEtudiant::eBien;
    bool estMeilleur = (int)NiveauEtudiant::eBien > (int)NiveauEtudiant::eExcellent;

    //////////////////
    //std::string
    //#include <string>
    //////////////////
    string maPhraseEnString = "Bonjour!!";
    const char* maPhraseEnChar = maPhraseEnString.c_str();
    // c_str() retourne un string en C

    //////////////////
    //std::cout
    //#include<iostream>
    //////////////////
    std::cout << "Hello World!\n";

    //////////////////
    //Conversions implicites
    //////////////////

    //int en float
    float nbPatate = 0;

    //double en float
    float nbSante = 0.01;

    //int en char
    char status = 3;

    //////////////////
    //Conversions génériques explicites
    // Essaie en ordre:
    // statique : pendant la compilation
    // dynamique : si les classes ont un ancètre commun ou une fonction de conversion
    // reinterpret : peu être n'importe quoi.
    //////////////////
    char power = (char)3;
    std::string message = std::string("oups");

    //////////////////
    //Écrire dans un stream
    //////////////////
    std::cout << "Un message dans la console!\n";

    ofstream myfile("example.txt");
    if (myfile.is_open())
    {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
    }
    //JAMAIS omettre ses {} même si cpp le permet
    else
    {
        cout << "Unable to open file";
    }

    //////////////////
    //Pointeurs
    //////////////////
    //Alloue de la mémoire sur la pile (mémoire "stack" qui est mieux optimisé mais moins flexible).
    //Appelé objet automatique.
    int stackInt = 5;

    //Alloue de la mémoire dynamique (flexible) dans la mémoire "heap".
    // new = scan la ram est trouve une place disponible pour mettre du data dedans.
    int* ptrInt = nullptr; // Déclare un pointeur vers un entier (int) et l'initialise à nullptr, ce qui signifie qu'il ne pointe actuellement vers aucune adresse mémoire valide.
    ptrInt = new int(5); // Alloue dynamiquement de la mémoire pour un entier (int) et initialise cette zone mémoire avec la valeur 5. `ptrInt` contient maintenant l'adresse de cet entier.
    *ptrInt = 3; // Accède à la valeur stockée à l'adresse pointée par `ptrInt` et la remplace par 3. L'entier qui était initialisé à 5 devient maintenant 3.
    cout << "Mon pointeur de int: " << *ptrInt << endl;
    //Quand on utilise new, toujours appeler delete pour éviter les fuites mémoires.
    delete ptrInt;
    // Toujours remettre le pointeur à nul
    ptrInt = nullptr;
    //Validation de pointeur - toujours à faire avant d'utiliser un pointeur.
    if (ptrInt != nullptr)
    {
        cout << "Crash!" << *ptrInt << endl;
    }
}