#pragma once

/*
 * Button.h
 *
 * Ce fichier d'en-tête déclare la classe Button, qui permet de créer
 * des boutons interactifs dans une application utilisant Raylib.
 *
 * La classe Button offre les fonctionnalités suivantes :
 * - Définir la position et la taille du bouton à l'écran.
 * - Afficher un texte sur le bouton.
 * - Spécifier une action (sous forme de fonction ou lambda) qui sera
 *   exécutée lorsqu'un clic sur le bouton est détecté.
 * - Gérer différents états du bouton (normal, survolé, pressé) grâce
 *   à des couleurs spécifiques pour chacun de ces états.
 *
 * En séparant l'interface (déclarations dans ce fichier) de l'implémentation
 * (dans Button.cpp), on facilite la réutilisation et la maintenance du code.
 */

#include "raylib.h"
#include <string>
#include <functional>

using namespace std;

class Button
{
public:
    // Constructeur du bouton
    // Paramètres :
    // - InPositionX, InPositionY : coordonnées de la position du bouton
    // - InLargeur, InHauteur : dimensions du bouton
    // - InText : texte affiché sur le bouton
    // - InActionToDo : fonction à exécuter lors d'un clic sur le bouton
    Button(int InPositionX, int InPositionY, int InLargeur, int InHauteur, const string& InText, function<void()> InActionToDo);

    // Destructeur du bouton (ici, aucune action particulière à réaliser)
    ~Button();

    // Méthode pour définir les couleurs du bouton selon ses états :
    // - InColorNeutral : couleur par défaut
    // - InHoverNeutral : couleur quand la souris survole le bouton
    // - InPressedNeutral : couleur quand le bouton est pressé
    void SetColors(const Color& InColorNeutral, const Color& InHoverNeutral, const Color& InPressedNeutral);

    // Méthode qui dessine le bouton à l'écran et met à jour son état (survol, pression, clic)
    void DrawAndUpdate();

private:
    // Attributs pour la position et la taille du bouton
    int _PositionX, _PositionY, _Largeur, _Hauteur;

    // Texte affiché sur le bouton
    string _Text;

    // Fonction à exécuter lors d'un clic sur le bouton
    function<void()> _ActionToDo;

    // Couleurs utilisées pour les différents états du bouton
    Color _ColorNeutral; // Couleur par défaut
    Color _ColorHover;   // Couleur quand la souris survole le bouton
    Color _ColorPressed; // Couleur quand le bouton est cliqué

    // États du bouton
    bool _IsHovered; // Indique si la souris survole le bouton
    bool _IsPressed; // Indique si le bouton est actuellement pressé
};