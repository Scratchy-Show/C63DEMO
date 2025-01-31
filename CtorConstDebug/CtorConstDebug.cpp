#include <iostream>
#include <windows.h> //Pour SetConsoleOutputCP
#include "Goblin.h"

//Déclaration de fonctions globales pour tantôt
void PresentationGoblinTresMalFait(Goblin InGoblin);
void PresentationGoblinMalFait(Goblin InGoblin);
void PresentationGoblinBienFait(Goblin InGoblin);

int main()
{
    //Pour voir les accents comme il faut.
    SetConsoleOutputCP(1252);

    // const
    // const mécanisme de sécurité
    float const PI = 3.14;
    const float TWO_PI(2 * PI);

    // référence
    // Par defaut pour les objets
    // Pas pour les types primitif
    float a = 4.0f;
    float& refA = a; // Copie l'adresse
    refA += 10.0f;
    cout << refA << endl;

    cout << endl << "Durée de vie d'un objet automatique" << endl;
    {
        // Ce qui n'est pas un pointeur est un objet automatique
        // Il se new et delete tout seul
        Goblin goblinAutomatique; //Construit ici
    } //Détruit ici

    cout << endl << "Durée de vie d'un objet automatique: dans un if" << endl;
    if (true)
    {
        //Construit ici
        Goblin goblinAutomatiqueDansUnIf("IffyGoblin");
    } //Détruit ici


    cout << endl << "Durée de vie d'un objet créé avec new" << endl;
    //Construit ici
    Goblin* ptrGoblin = new Goblin("PeterLeGoblin");
    const string& nomDeptrGoblin = ptrGoblin->GetName();
    cout << "Je suis " << nomDeptrGoblin << endl;
    //Détruit ici
    delete ptrGoblin;
    ptrGoblin = nullptr;

    cout << endl << "Passage par paramètre" << endl;

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
    cout << "Présentation très mal faite du goblin " << InGoblin.GetName() << endl;
}

void PresentationGoblinMalFait(const Goblin InGoblin)
{
    cout << "Présentation mal faite du goblin " << InGoblin.GetName() << endl;
}

void PresentationGoblinBienFait(const Goblin InGoblin)
{
    cout << "Présentation bien fait du goblin " << InGoblin.GetName() << endl;
}