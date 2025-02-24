#include <iostream>
#include <functional>

//En ordre...
//Functionnal
//Passage en paramètre
//Faire un mini système de commande?
// 
//Lambda (fonction anonyme)
//Capture
//Pointeur de fonction traditionnels - pour la postérité

//Exercice
//Toggle avec pointeur de fonction 

int Add(int a, int b)
{
    return a + b;
}

int Sub(int a, int b)
{
    return a - b;
}

int main()
{
    //Exemple canonique (ancien)
    int (*monPremierPointeurDeFonction)(int, int) = nullptr;
    //Moderne
    std::function<int(int, int)> monPremierFunctionnal = nullptr;

    monPremierPointeurDeFonction = Add;
    if (monPremierPointeurDeFonction != nullptr)
    {
        std::cout << monPremierPointeurDeFonction(3,4) << std::endl;
        monPremierPointeurDeFonction = Sub;
        std::cout << monPremierPointeurDeFonction(3,4) << std::endl;
    }

    //Lambda (fonction anonyme)
    constexpr int nTriche = 5;
    monPremierPointeurDeFonction = [](int a, int b) { return a * b; };
    monPremierFunctionnal = [=](int a, int b) { return a * b; };
}