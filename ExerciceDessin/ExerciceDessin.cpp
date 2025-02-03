#include <iostream>
#include "raylib.h"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Exercice dessin");

    Vector2 center = { (GetScreenWidth() - 300) / 2.0f, GetScreenHeight() / 2.0f };

    float outerRadius = 180.0f;
    float startAngle = 34.0f;
    float endAngle = 315;
    float segments = 100.0f;

    Vector2 ballWallpaperPosition = { 10, 0};
    Vector2 ballPosition1 = { (float)screenWidth / 2, (float)screenHeight / 2 };
    Vector2 ballPosition2 = { (float)screenWidth / 2 + 150, (float)screenHeight / 2 };
    Vector2 ballPosition3 = { (float)screenWidth / 2 + 300, (float)screenHeight / 2 };

    // Set our game to run at 60 frames-per-second
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    // Detect window close button or ESC key
    while (!WindowShouldClose())
    {
        // Draw
        //----------------------------------------------------------------------------------
       /* BeginDrawing();

            ClearBackground(BLACK);

            DrawCircleSector(center, outerRadius, startAngle, endAngle, (int)segments, YELLOW);

            DrawCircleV(ballPosition1, 30, GRAY);
            DrawCircleV(ballPosition2, 40, GRAY);
            DrawCircleV(ballPosition3, 50, GRAY);

            DrawText("Waka waka !!!!!!", 150, 700, 50, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
        */
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(DARKPURPLE);

            for (int i = 0; i < 45; i++)
            {
                DrawCircleLines(190 + 21 * i, 0, 20, GRAY);
            }

            DrawText("Loading...", screenWidth / 3, screenHeight / 2, 100, ORANGE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
}