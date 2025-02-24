#include "Button.h"

Button::Button(int InPositionX, int InPositionY, int InLargeur, int InHauteur, const std::string& InText, std::function<void()> InActionToDo)
	:_PositionX(InPositionX)
	, _PositionY(InPositionY)
	, _Largeur(InLargeur)
	, _Hauteur(InHauteur)
{
}

// Destructeur
Button::~Button()
{
	//Rien
}



void SetColors(const Color& InColorNeutral, const Color& InHoverNeutral, const Color& InPressedNeutral) {

}

void DrawAndUpdate() {

}