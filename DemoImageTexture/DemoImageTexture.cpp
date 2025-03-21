/*******************************************************************************************
*
*   raylib [textures] example - Texture loading and drawing
*
*   Example complexity rating: [★☆☆☆] 1/4
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>
using namespace std;
const string imagePath = string(GetWorkingDirectory()) + "\\res\\TopViewPerson.png";
const string imageBrickPath = string(GetWorkingDirectory()) + "\\res\\bricksx64.png";

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - texture loading and drawing");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    Texture2D texture = LoadTexture(imagePath.c_str());
    Texture2D textureBrick = LoadTexture(imageBrickPath.c_str());

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        constexpr float XA = 100.f;
        constexpr float XB = 500.f;

        constexpr float YA = 100.f;
        constexpr float YB = 300.f;
        constexpr float YC = 500.f;
        constexpr float YD = 700.f;

        //Dessine la texture au complet dans un carré de 100x100
        DrawTexturePro(texture, { 0.f,0.f,(float)texture.width,(float)texture.height }, { XA,YA,100.f,100.f }, { 0.f,0.f }, 0.f, WHITE);

        //Dessine la texture au complet dans un carré de 100x50, donc étirée
        DrawTexturePro(texture, { 0.f,0.f,(float)texture.width,(float)texture.height }, { XB,YA,100.f,50.f }, { 0.f,0.f }, 0.f, WHITE);

        //Coupe de 100 pixels du haut de la texture. Affiche le résultat dans un carré 100x100, donce sera étiré
        DrawTexturePro(texture, { 0.f,100.f,(float)texture.width,(float)texture.height - 100.f }, { XA,YB,100.f,100.f }, { 0.f,0.f }, 0.f, WHITE);

        //Augmenter de 200 pixels de la droite la texture. Affiche le résultat dans un carré 100x200 donc ne sera pas étirée mais sera doublée.
        DrawTexturePro(texture, { 0.f,0.f,(float)texture.width + 200.0f,(float)texture.height }, { XB,YB,200.f,100.f }, { 0.f,0.f }, 0.f, WHITE);

        //Affiche 3 image tournées de 45 degrés
        DrawTexturePro(texture, { 0.f,0.f,(float)texture.width,(float)texture.height }, { XA,YC,50.f,50.f }, { 0.f,0.f }, 0.f, WHITE);
        DrawTexturePro(texture, { 0.f,0.f,(float)texture.width,(float)texture.height }, { XA + 100.f,YC,50.f,50.f }, { 0.f,0.f }, 45.f, WHITE);
        DrawTexturePro(texture, { 0.f,0.f,(float)texture.width,(float)texture.height }, { XA + 200.f,YC,50.f,50.f }, { 0.f,0.f }, 90.f, WHITE);
        //Dessin des pivots (point à partir duquel la rotation se fait)
        DrawCircle(XA, YC, 5.f, GRAY);
        DrawCircle(XA + 100.f, YC, 5.f, GRAY);
        DrawCircle(XA + 200.f, YC, 5.f, GRAY);
        {
            //Affiche 3 image tournées de 45 dégrés avec le pivot ajusté au centre
            constexpr float grMini = 50.f;
            const Vector2 origine = { 0.5f * grMini, 0.5f * grMini };
            DrawTexturePro(texture, { 0.f,0.f,(float)texture.width,(float)texture.height }, { XB,YC,grMini,grMini }, origine, 0.f, WHITE);
            DrawTexturePro(texture, { 0.f,0.f,(float)texture.width,(float)texture.height }, { XB + 100.f,YC,grMini,grMini }, origine, 45.f, WHITE);
            DrawTexturePro(texture, { 0.f,0.f,(float)texture.width,(float)texture.height }, { XB + 200.f,YC,grMini,grMini }, origine, 90.f, WHITE);
            //Dessin des pivots
            DrawCircle(XB, YC, 5.f, GRAY);
            DrawCircle(XB + 100.f, YC, 5.f, GRAY);
            DrawCircle(XB + 200.f, YC, 5.f, GRAY);

            //Calcul d'une boite mais décalée de l'origine.
            Rectangle box = { XB - origine.x,YC - origine.y, grMini,grMini };
            DrawRectangleLinesEx(box, 2.f, PURPLE);
        }

        {
            //Dessin d'une tuile de grosseur quelconque!
            Vector2 grosseurTuile{ 377.f,121.f };
            const Vector2 origine = { (float)grosseurTuile.x * 0.5f, (float)grosseurTuile.y };
            DrawTexturePro(textureBrick, { 0.f,0.f,grosseurTuile.x,grosseurTuile.y }, { screenWidth * 0.5f,YD,grosseurTuile.x,grosseurTuile.y }, origine, 0.f, WHITE);

            //Calcul d'une boite mais décalée de l'origine.
            Rectangle box = { screenWidth * 0.5f - origine.x,YD - origine.y, grosseurTuile.x,grosseurTuile.y };
            DrawRectangleLinesEx(box, 4.f, PURPLE);
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(texture);       // Texture unloading
    UnloadTexture(textureBrick);

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}