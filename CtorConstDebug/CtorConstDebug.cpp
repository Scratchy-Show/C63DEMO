#include <iostream>
#include <windows.h> //Pour SetConsoleOutputCP
#include "Goblin.h"

//D�claration de fonctions globales pour tant�t
void PresentationGoblinTresMalFait(Goblin InGoblin);
void PresentationGoblinMalFait(Goblin InGoblin);
void PresentationGoblinBienFait(Goblin InGoblin);

int main()
{
    //Pour voir les accents comme il faut.
    SetConsoleOutputCP(1252);

    // const
    //Utilisation de 'const' pour définir des valeurs immuables
    // const mécanisme de sécurité
    float const PI = 3.14;
    const float TWO_PI(2 * PI);

    // Référence
    // Une référence agit comme un alias d'une variable existante
    // Par défaut, les objets sont passés par référence
    // Pas pour les types primitif
    float a = 4.0f;
    float& refA = a; // Copie l'adresse
    refA += 10.0f;   // Modifier refA revient à modifier 'a'
    cout << refA << endl; // Affiche 14.0

    cout << endl << "Dur�e de vie d'un objet automatique" << endl;
    {
        // Ce qui n'est pas un pointeur est un objet automatique
        // Il se new et delete tout seul
        Goblin goblinAutomatique; //Construit ici
    } //Détruit ici

    cout << endl << "Dur�e de vie d'un objet automatique: dans un if" << endl;
    if (true)
    {
        //Construit ici
        Goblin goblinAutomatiqueDansUnIf("IffyGoblin");
    } //Détruit ici


    cout << endl << "Dur�e de vie d'un objet cr�� avec new" << endl;
    //Construit ici
    Goblin* ptrGoblin = new Goblin("PeterLeGoblin");
    const string& nomDeptrGoblin = ptrGoblin->GetName();
    cout << "Je suis " << nomDeptrGoblin << endl;
    //Détruit ici
    delete ptrGoblin;
    ptrGoblin = nullptr;

    cout << endl << "Passage par param�tre" << endl;

    Goblin goblinPresentateur("GoblinPresentateur");
    PresentationGoblinTresMalFait(goblinPresentateur);
    cout << endl;
    PresentationGoblinMalFait(goblinPresentateur);
    cout << endl;
    PresentationGoblinBienFait(goblinPresentateur);

}


//Implémentation
void PresentationGoblinTresMalFait(Goblin InGoblin)
{
    cout << "Pr�sentation tr�s mal faite du goblin " << InGoblin.GetName() << endl;
}

void PresentationGoblinMalFait(const Goblin InGoblin)
{
    cout << "Pr�sentation mal faite du goblin " << InGoblin.GetName() << endl;
}

void PresentationGoblinBienFait(const Goblin InGoblin)
{
    cout << "Pr�sentation bien fait du goblin " << InGoblin.GetName() << endl;
}