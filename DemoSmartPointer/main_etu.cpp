#include <iostream>
#include <string>
#include "raylib.h"
#include "raymath.h"
#include "SimpleSquare.hpp"

//À inclure pour l'utilisation des pointeurs automatiques
#include <memory>

int main(void)
{
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 800;
    constexpr float buffer = 80.f;
    constexpr float delta = 100.f;

    InitWindow(screenWidth, screenHeight, "Demo pointeurs automatiques");

    Vector2 currentDrawPosition = Vector2{ buffer,buffer };
    Vector2 drawPositionDelta = Vector2{ delta,delta };

    //Objet automatique
    SimpleSquare hautGauche(currentDrawPosition,"Objet automatique",GREEN);


    //Pointeur normal - ne pas oublier de supprimer!
    currentDrawPosition = Vector2Add(currentDrawPosition, drawPositionDelta);
    SimpleSquare* ptrSimpleSquare = new SimpleSquare(currentDrawPosition, "Pointeur classique", RED);


    //Pointeur partagé
    currentDrawPosition = Vector2Add(currentDrawPosition, drawPositionDelta);
    std::shared_ptr<SimpleSquare> ptrSharedSimpleSquare = std::make_shared<SimpleSquare>(currentDrawPosition, "Pointeur partage", WHITE);
    std::shared_ptr<SimpleSquare> ptrSharedSimpleSquareCopy = ptrSharedSimpleSquare; // use_count++

    // Ouverture d'une portée
    {
        std::shared_ptr<SimpleSquare> ptrSharedSimpleSquareCopyCopy = ptrSharedSimpleSquare; // use_count++
    } // ptrSharedSimpleSquareCopyCopy ne peux plus être utilisé après la portée, donc use_count--
      // Si use_count = 0, le pointeur se DELETE
      // RESET force la suppression


    //Pointeur faible
    // Un weak ptr n'augmente pas de use_count, donc il ne fait pas de use_count++
    currentDrawPosition = Vector2Add(currentDrawPosition, drawPositionDelta);
    std::weak_ptr<SimpleSquare> ptrWeakSimpleSquare = ptrSharedSimpleSquare; // make_weak n'existe pas !!!!!!!


    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
            BeginDrawing();
                ClearBackground(ORANGE);
                hautGauche.Draw();

                //Pointeur normal
                if (ptrSimpleSquare != nullptr)
                {
                    (*ptrSimpleSquare).Draw(); // == ptrSimpleSquare->Draw(); 
                }

                //Pointeur partagé
                // On peut utiliser notre argument optionnel (InMessageExtended = "")
                if (ptrSharedSimpleSquare != nullptr)
                {
                    (*ptrSharedSimpleSquare).Draw(std::to_string(ptrSharedSimpleSquare.use_count())); // == ptrSharedSimpleSquare->Draw(); 
                }

                //Pointeur faible
                // Un weak_ptr ne possède pas directement l'objet.
                // Pout accéder à l'objet, il faut appeler la méthode lock() qui retourne un shared_ptr temporaire.
                if (auto tempShared = ptrWeakSimpleSquare.lock())
                {
                    // lock() protège le pointeur, cela garantie qu'il soit vivant
                    (*tempShared).Draw(std::to_string(ptrSharedSimpleSquare.use_count())); // == tempShared->Draw();
                }

            EndDrawing();
    }

    CloseWindow();

    if (ptrSimpleSquare != nullptr)
    {
        delete ptrSimpleSquare;
    }

    return 0;
} // use_count -- use_count-- donc use_count==0 donc DELETE effectué
