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
            int px = 0;
            
            // Répète sur toute la largeur
            for (int posX = 0; posX < GetScreenWidth(); posX += 50)
            {
                // Répète sur toute la hauteur
                for (int posY = 0; posY < GetScreenHeight(); posY += 50)
                {
                    DrawCircle(px, posY, 5, GRAY);
                    DrawRectangle(px += 5, posY += 50, 10, 10, GRAY);
                    //  Dessin un !
                    DrawLine(px += 10, posY += 50, px, posY + 15, GRAY);
                    DrawCircle(px, posY + 20, 2, GRAY);
                }
            }
            
            /*
            // Répète sur toute la hauteur
            for (int y = 0; y < GetScreenHeight(); y += 50)
            {
                // Répète sur toute la largeur
                for (int x = 0; x < GetScreenWidth(); x += 50)
                {
                    // Décalage une ligne sur deux
                    int offsetX = (y / 50) % 2 == 0 ? 0 : 25;

                    // Une ligne sur trois : Cercles
                    if ((y / 50) % 3 == 0) 
                    {
                        DrawCircle(x + offsetX, y, 5, GRAY);
                    }
                    else if ((y / 50) % 3 == 1)  // Une autre ligne sur trois : Carrés
                    {
                        DrawRectangle(x + offsetX, y, 10, 10, GRAY);
                    }
                    else  // Une ligne sur trois : Point d'exclamation
                    {
                        DrawLine(x + offsetX, y, x + offsetX, y + 15, GRAY);  // Barre verticale
                        DrawCircle(x + offsetX, y + 20, 2, GRAY);  // Point en bas du "!"
                    }
                }
            }*/

            DrawText("Loading...", screenWidth / 3, screenHeight / 2, 100, ORANGE);
        }

        EndDrawing();
    }
    CloseWindow();
}