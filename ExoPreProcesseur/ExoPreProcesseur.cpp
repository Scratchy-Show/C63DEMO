#include <iostream>

#include "custommacro.h"

using namespace std;

int main()
{
    // CALCUL

    std::cout << "Variable nombre naturel: " << NATURAL_NUMBER << endl; // = 2.73
    std::cout << "Variable Fibonnaci: " << FIBONNACCI_NUMBER << endl; // = 1.618
    std::cout << "Variable nombre bizarre: " << WIERD_NUMBER(NATURAL_NUMBER, FIBONNACCI_NUMBER) << endl; // = 4.348

    std::cout << "Calcul 1: " << 2.0f * NATURAL_NUMBER + WIERD_NUMBER(NATURAL_NUMBER, FIBONNACCI_NUMBER) << endl; // = 9.808 => 9.808
    std::cout << "Calcul 2: " << 2.0f * WIERD_NUMBER(NATURAL_NUMBER, FIBONNACCI_NUMBER) << endl; // = 8.696 => 7.078

    // LOGGER
    std::cout << "Fichier: " << __FILE__ << " Ligne: " << __LINE__ << std::endl;
}