#include <iostream>
#include <functional>

int Add(int InA, int InB)
{
    return InA + InB;
}

int Sub(int InA, int InB)
{
    return InA - InB;
}

int main()
{
    std::cout << Add(5,4) << std::endl;
    
    std::function<int(int, int)> funcOperator = Add;
    std::cout << funcOperator(5, 4) << std::endl;
    
    funcOperator = Sub;
    std::cout << funcOperator(5, 4) << std::endl;

    funcOperator = [](int InA, int InB) { return InA * InB; };
    std::cout << funcOperator(5, 4) << std::endl;

    const int offset = 5;
    // [] = capture - Qui permet de tranmettre par copie des paramètres
    funcOperator = [offset](int InA, int InB) { return InA + InB + offset; };

    std::cout << funcOperator(5, 4) << std::endl;
}