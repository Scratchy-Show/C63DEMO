#include "Goblin.h"
#include <iostream>

using namespace std;

Goblin::Goblin()
// Préconstructeur (liste d'initialisation avec ":")
//1) Pour appeler un autre constructeur avec des paramètres
// Les constructeur peuvent s'appeler entre eux mais uniquement dans le préconstructeur
	:Goblin::Goblin("NoName")
{
	cout << "Goblin::Goblin() est appel�. " << "("<< _Name << ")" << endl;
}

Goblin::Goblin(const string& InName)
//Préconstructeur
//2) Pour initialiser une const
//3) Pour initialiser des valeurs (bonne pratique mais pas obligatoire)
	:_Name(InName),
	_Life(20)
{
	cout << "Goblin::Goblin(const string& InName) est appel�. " << "(" << _Name << ")" << endl;
}

Goblin::~Goblin()
{
	cout << "Goblin::~Goblin() est appel�. " << "(" << _Name << ")" << endl;
}

const string& Goblin::GetName() const
{
	//Interdit à cause que Goblin::GetName() const
	//_Name = "GlobinCoquin";
	return _Name; // return this->_Name;
}

int Goblin::GetLife() const
{

	//Interdit à cause que GetLife() const
	//_Life = 10;
	return _Life;
}

void Goblin::SetLife(int InLife)
{
	//Modification permise car aucun const
	_Life = InLife;
}
