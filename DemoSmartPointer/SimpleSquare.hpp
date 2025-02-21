#pragma once
// Fichier .hpp pour les classes tr�s simples, sinon le temps de compilation peut �tre tr�s �lev�.

#include "raylib.h"

class SimpleSquare
{
	public:
		//////////////////
		//Attributss
		//////////////////
		Vector2 _Position = Vector2{ 0.f,0.f };
		float _Size = 10.0f;
		Color _Color = VIOLET;
		std::string _Message = "";

		//////////////////
		//Attributs de classe
		//////////////////
		// constexpr -> Optimise une valeur it�rable
		static constexpr int __TextOffsetY = 20;
		static constexpr int __TextFontSize = 32;

		//////////////////
		//M�thodes
		//////////////////
		SimpleSquare(const Vector2& InPosition, const std::string& InMessage,  Color InColor = VIOLET, float InSize = 10.0f )
			:_Position(InPosition)
			, _Size(InSize)
			,_Color(InColor)
			,_Message(InMessage)
		{}

		// Destructeur
		~SimpleSquare()
		{}
		
		void Draw(const std::string& InMessageExtended = "") // InMessageExtended = "" => Optionnel
		{
			const int x = (int)_Position.x;
			const int y = (int)_Position.y;
			const std::string totalMsg = _Message + " " + InMessageExtended;
			DrawText(totalMsg.c_str(), x, y + __TextOffsetY, __TextFontSize, _Color);
			DrawRectangle(x, y, _Size,_Size,_Color);
		}
};

