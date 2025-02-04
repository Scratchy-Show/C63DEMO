#include <iostream>
#include "raylib.h"

int main()
{
    // Initialisation
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Exercice dessin");

    // Positions
    Vector2 center = { (GetScreenWidth() - 300) / 2.0f, GetScreenHeight() / 2.0f };
    float outerRadius = 180.0f;
    float startAngle = 34.0f;
    float endAngle = 315;
    float segments = 100.0f;

    Vector2 ballWallpaperPosition = { 10, 0};
    Vector2 ballPosition1 = { (float)screenWidth / 2, (float)screenHeight / 2 };
    Vector2 ballPosition2 = { (float)screenWidth / 2 + 150, (float)screenHeight / 2 };
    Vector2 ballPosition3 = { (float)screenWidth / 2 + 300, (float)screenHeight / 2 };

    // Alterne entre les dessins
    bool isPacmanDisplayed = true;

    // Set our game to run at 60 frames-per-second
    SetTargetFPS(60);

    // Boucle principale du jeu
    while (!WindowShouldClose()) // Détection de la fermeture de la fenêtre
    {
        if (IsKeyPressed(KEY_SPACE))
        {
            // Inverse l'affichage
            isPacmanDisplayed = !isPacmanDisplayed;
        }

        BeginDrawing();

        if (isPacmanDisplayed)
        {
			ClearBackground(BLACK);
            DrawCircleSector(center, outerRadius, startAngle, endAngle, (int)segments, YELLOW);

            DrawCircleV(ballPosition1, 30, GRAY);
            DrawCircleV(ballPosition2, 40, GRAY);
            DrawCircleV(ballPosition3, 50, GRAY);

            DrawText("Waka waka !!!!!!", 150, 700, 50, RED);
        }
        else
        {
            ClearBackground(DARKPURPLE);

            // Répète sur toute la largeur
            for (int posX = 0; posX < GetScreenWidth(); posX += 50)
            {
                int posY = 0;
                DrawCircle(posX, posY, 5, GRAY);
                DrawRectangle(posX+=5, posY+=50, 10, 10, GRAY);
                // !
                DrawLine(posX+=5, posY+=50, posX, posY + 15, GRAY);
                DrawCircle(posX, posY+20, 2, GRAY);
            }

            DrawText("Loading...", screenWidth / 3, screenHeight / 2, 100, ORANGE);
        }

        EndDrawing();
    }
    CloseWindow();
}