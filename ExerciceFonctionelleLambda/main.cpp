/*
 * main.cpp
 *
 * Ce fichier constitue le point d'entrée de l'application.
 *
 * Il a pour but de :
 * - Initialiser la fenêtre graphique avec Raylib.
 * - Créer et configurer des boutons interactifs en utilisant la classe Button.
 * - Associer des actions aux boutons (ex. : changer la couleur de fond,
 *   afficher un message, quitter le programme) via des fonctions lambda.
 * - Gérer la boucle principale du programme pour dessiner l'interface et
 *   traiter les interactions de l'utilisateur.
 *
 * En résumé, ce fichier démontre comment assembler et utiliser la classe Button
 * pour créer une interface simple et interactive.
 */

#include <iostream>
#include <functional>
#include "raylib.h"
#include "Button.h"

using namespace std;

int main()
{
    // Initialisation de la fenêtre
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Fonction lambda");

    // Déclaration d'une variable statique pour la couleur de fond
    static Color currentBg = DARKPURPLE;

    // Création des boutons avec des lambdas
    Button bouton1(100, 100, 200, 80, "Changer couleur", []() {
        currentBg = Color{
            (unsigned char)GetRandomValue(0, 255),
            (unsigned char)GetRandomValue(0, 255),
            (unsigned char)GetRandomValue(0, 255),
            255
        };
        });
    Button bouton2(100, 250, 200, 80, "Dire Bonjour", []() {
        cout << "Bonjour, Raylib !" << std::endl;
        });
    Button bouton3(100, 400, 200, 80, "Quitter", []() {
        CloseWindow();
        });

    // Définition des couleurs pour chaque bouton
    bouton1.SetColors(RED, ORANGE, DARKBROWN);
    bouton2.SetColors(GREEN, WHITE, DARKGRAY);
    bouton3.SetColors(SKYBLUE, MAGENTA, DARKBLUE);

    // Définition du nombre de frames par seconde (FPS) pour une animation fluide
    SetTargetFPS(60);

    // Boucle principale du programme : s'exécute tant que la fenêtre n'est pas fermée
    while (!WindowShouldClose()) // Détection de la fermeture de la fenêtre
    {
        // Dessin
        BeginDrawing();

            // Efface l'écran en remplissant avec la couleur de fond currentBg
            ClearBackground(currentBg);

            // Mise à jour et affichage des boutons
            bouton1.DrawAndUpdate();
            bouton2.DrawAndUpdate();
            bouton3.DrawAndUpdate();

        EndDrawing();
    }
    // Fermeture de la fenêtre et libération des ressources allouées par Raylib
    CloseWindow();
    return 0;
}