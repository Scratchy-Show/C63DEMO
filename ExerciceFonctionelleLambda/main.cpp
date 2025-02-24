#include <iostream>
#include <functional>
#include "raylib.h"
#include "Button.h"

int main()
{
    // Initialisation
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Fonction lambda");

    // Boutons
    Button bouton1 = Button(100, 100, 200, 80, "Hover", []() {});


    Rectangle bouton2 = { 200, 200, 200, 80 };
    Rectangle bouton3 = { 300, 300, 200, 80 };

    // 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    int btnState = 0;

    Vector2 mousePosition = { 0.0f, 0.0f };

    // Set our game to run at 60 frames-per-second
    SetTargetFPS(60);

    // Boucle principale du jeu
    while (!WindowShouldClose()) // Détection de la fermeture de la fenêtre
    {
        mousePosition = GetMousePosition();

        if (CheckCollisionPointRec(mousePosition, bouton1))
        {
            btnState = 1;
        }
        else if (IsMouseButtonPressed)
        {
            btnState = 2;
        }

        // Dessin
        BeginDrawing();

            ClearBackground(DARKPURPLE);
            DrawRectangleRec(bouton1, BLUE);
            DrawRectangleRec(bouton2, WHITE);
            DrawRectangleRec(bouton3, RED);

            if (btnState == 1) {
                DrawRectangleRec(bouton1, RED);
                btnState = 0;
            }
            else if (btnState == 2) {
                DrawRectangleRec(bouton1, BLUE);
                btnState = 0;
            }

        EndDrawing();
    }
    CloseWindow();
}