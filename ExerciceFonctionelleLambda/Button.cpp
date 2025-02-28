/*
 * Button.cpp
 *
 * Ce fichier contient l'implémentation de la classe Button, telle qu'elle est déclarée dans Button.h.
 *
 * Il définit concrètement :
 *  - Le constructeur, qui initialise la position, la taille, le texte, l'action associée,
 *    ainsi que les couleurs par défaut et les états du bouton.
 *  - Le destructeur, qui ne réalise aucune opération particulière ici.
 *  - La méthode SetColors, permettant de modifier les couleurs du bouton pour ses différents états (normal, survolé, pressé).
 *  - La méthode DrawAndUpdate, qui gère l'affichage du bouton, détecte l'interaction avec la souris (survol et clic),
 *    et exécute l'action associée lorsque le bouton est cliqué.
 *
 * L'objectif est de séparer l'interface et l'implémentation :
 * - L'interface (déclarée dans Button.h) définit les méthodes et les attributs
 *   que la classe offre, c'est-à-dire le "quoi" (ce que la classe fait).
 *
 * - L'implémentation (dans ce fichier .cpp) détaille le "comment" (la façon dont
 *   ces fonctionnalités sont réalisées).
 *
 * Cette séparation facilite :
 * - La maintenance du code : vous pouvez modifier l'implémentation sans affecter
 *   les fichiers qui utilisent la classe, tant que l'interface reste inchangée.
 *
 * - En cachant les détails complexes derrière une
 *   interface simple et lisible, le code devient plus modulaire et plus facile à
 *   appréhender.
 */

#include "Button.h"

using namespace std;

// Constructeur de la classe Button
// Initialise l'objet Button avec sa position, sa taille, le texte affiché et l'action à effectuer lors d'un clic.
Button::Button(int InPositionX, int InPositionY, int InLargeur, int InHauteur, const string& InText, function<void()> InActionToDo)
    : _PositionX(InPositionX), _PositionY(InPositionY), _Largeur(InLargeur), _Hauteur(InHauteur),
    _Text(InText), _ActionToDo(InActionToDo),
    _IsHovered(false), _IsPressed(false)
{
    // Rien à faire ici car tous les attributs sont initialisés dans la liste d'initialisation.
}

// Destructeur de la classe Button
Button::~Button()
{
    // Rien
}

// Méthode pour définir les couleurs du bouton selon différents états
// InColorNeutral : couleur par défaut du bouton
// InHoverNeutral : couleur lorsque la souris survole le bouton
// InPressedNeutral : couleur lorsque le bouton est pressé
void Button::SetColors(const Color& InColorNeutral, const Color& InHoverNeutral, const Color& InPressedNeutral) {
    _ColorNeutral = InColorNeutral;
    _ColorHover = InHoverNeutral;
    _ColorPressed = InPressedNeutral;
}

// Méthode qui dessine le bouton à l'écran et met à jour son état en fonction des interactions avec la souris
void Button::DrawAndUpdate() {
    // Récupère la position actuelle de la souris
    Vector2 mousePosition = GetMousePosition();

    // Détermine le rectangle correspondant au bouton (position et taille)
    Rectangle buttonRect = { (float)_PositionX, (float)_PositionY, (float)_Largeur, (float)_Hauteur };

    // Vérifie si la souris se trouve dans le rectangle du bouton
    _IsHovered = CheckCollisionPointRec(mousePosition, buttonRect);

    // Détermine si le bouton est pressé : la souris est dessus et le bouton gauche est enfoncé
    _IsPressed = _IsHovered && IsMouseButtonDown(0);

    // Choisit la couleur par défaut
    Color currentColor = _ColorNeutral;

    // Si la souris survole le bouton, on change la couleur
    if (_IsHovered) {
        currentColor = _ColorHover;

        // Si le bouton gauche de la souris est appuyé, on change à nouveau la couleur
        // et on exécute l'action associée au bouton
        if (IsMouseButtonDown(0)) {
            currentColor = _ColorPressed;
            _ActionToDo();  // Exécute l'action définie lors de la création du bouton (fonction lambda)
        }
    }

    // Dessine le rectangle du bouton avec la couleur choisie
    DrawRectangleRec(buttonRect, currentColor);

    // Affiche le texte du bouton à l'intérieur du rectangle //

    // _Text.c_str() convertit la string en tableau de caractères (c-string)    DrawRectangleRec(buttonRect, currentColor);
    //DrawText(_Text.c_str(), _PositionX + 10, _PositionY + 25, 20, BLACK);

    // Mesurer la largeur du texte pour la taille de police 20
    int textWidth = MeasureText(_Text.c_str(), 20);

    // Calculer la position x pour centrer horizontalement le texte
    int textX = _PositionX + (_Largeur - textWidth) / 2;

    // Calculer la position y pour centrer verticalement le texte
    // Ici, on suppose que la hauteur du texte est approximativement égale à la taille de la police (20)
    int textY = _PositionY + (_Hauteur - 20) / 2;

    // Dessiner le texte centré dans le bouton
    DrawText(_Text.c_str(), textX, textY, 20, BLACK);
}