#pragma once

#include "raylib.h"
using namespace std;

class Button
{
public:
    Button(int InPositionX, int InPositionY, int InLargeur, int InHauteur, const std::string& InText, std::function<void()> InActionToDo);

    ~Button();

    void SetColors(const Color& InColorNeutral, const Color& InHoverNeutral, const Color& InPressedNeutral);

    void DrawAndUpdate();
};
