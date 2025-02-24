#include "raylib.h"
#include "raymath.h"
#include "Flee.h"
#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include <string>

using namespace std;


struct CollisionEvent
{
    weak_ptr<Flee> _LowerIndexFlee; // Puce avec l’index le plus bas
    weak_ptr<Flee> _HigherIndexFlee; // Puce avec l’index le plus haut
    Vector2 _Position; // Emplacement de la collision
    float _TimeOfImpact; // Enregistre le moment de la collision

    CollisionEvent(weak_ptr<Flee> InLowerIndexFlee, weak_ptr<Flee> InHigherIndexFlee, float InTimeOfImpact)
        : _LowerIndexFlee(InLowerIndexFlee)
        , _HigherIndexFlee(InHigherIndexFlee)
        , _TimeOfImpact(InTimeOfImpact)
    {
        //Constructeur ici

        // tempShared est un shared_ptr<Flee> valide
        if (auto tempShared = InLowerIndexFlee.lock())
        {
            _Position = tempShared->GetPosition();
        }
        else
        {
            _Position = { 0,0 };
        }
    }
};

int main(void)
{
    constexpr int screenWidth = 1000;
    constexpr int screenHeight = 1000;
    constexpr int borderMargin = 50;
    constexpr int nbFlee = 25;

    constexpr Vector2 borderMin = Vector2{ borderMargin ,borderMargin };
    constexpr Vector2 borderMax = Vector2{ screenWidth - borderMargin , screenHeight - borderMargin };
    InitWindow(screenWidth, screenHeight, "Flee bonanza!");

    //1) Créer une structure de donnée pour contenir des smart pointeur de puce (Flee) sans la remplir
    vector<shared_ptr<Flee>> puces;


    //2) Dans une boucle, créez des puces et placez-les au hasard à l'intérieur de border min et border max
    //Indice: regardez la fonction raylib  GetRandomValue
    //Soyez explicite si des données changes de type.
    for (int i = 0; i < nbFlee; i++)
    {
        // static_cast est un opérateur de conversion
        float posX = static_cast<float>(GetRandomValue(borderMin.x, borderMax.x)); // Conversion en float
        float posY = static_cast<float>(GetRandomValue(borderMin.y, borderMax.y));
        Vector2 pos = { posX, posY };

        float vitesse = 100.0f;

        // make_shared est une fonction utilitaire qui crée et initialise un objet, puis retourne un std::shared_ptr qui gère cet objet. Il s'agit d'une manière sûre et efficace de créer des objets partagés
        shared_ptr<Flee> ptrSharedFlee = make_shared<Flee>(pos, vitesse, borderMin, borderMax);

        // push_back est une fonction membre du conteneur std::vector qui permet d'ajouter un nouvel élément à la fin du vecteur
        puces.push_back(ptrSharedFlee);

    }


    //3) Allez voir plus haut ce que fait la structure et prenez le temps de la comprendre. Initialiser toutes les valeurs de la struct.
    //Pour l'attribut _Position, prenez la position de la puce avec le plus petit index (InLowerIndexFlee)
    //?SAVIEZ_VOUS? En c++, struct et classe sont très similaires et on peut mettre des méthodes (incluant des constructeurs/destructeurs) aux struct
    

    //4) Créer une structure de données pour contenir des smart pointer d'évènement de collision.
    vector<shared_ptr<CollisionEvent>> collisions;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        const float deltaTime = GetFrameTime();
        const float totalTime = GetTime();
        BeginDrawing();
            ClearBackground(BLUE);
            DrawLine(borderMin.x, borderMin.y, borderMin.x, borderMax.y, PURPLE);
            DrawLine(borderMin.x, borderMin.y, borderMax.x, borderMin.y, PURPLE);
            DrawLine(borderMax.x, borderMin.y, borderMax.x, borderMax.y, PURPLE);
            DrawLine(borderMin.x, borderMax.y, borderMax.x, borderMax.y, PURPLE);
            //5) Dans raylib, trouvez une manière de dessiner le nombre d'images par secondes en haut à gauche, communément abrévié FPS en anglais
            DrawFPS(10, 10);


            //6) En haut dans le milieu, écrivez le nombre total de puces en noir
            string textePuces = "Nombre de puces : " + to_string(puces.size());
            // MeasureText() calcule la largeur (en pixels) d?une chaîne de caractères pour une taille de police donnée
            // c_str() d'un objet std::string renvoie un pointeur vers un tableau de caractères de type const char* qui représente la chaîne de caractères sous une forme "C-style" (c'est-à-dire terminée par un caractère nul '\0')
            int textWidth = MeasureText(textePuces.c_str(), 20);
            // screenWidth / 2 place le centre de l'écran
            // Soustrait textWidth / 2 pour décaler le texte de manière à ce que son milieu coïncide avec le centre de l'écran
            // Position en y est fixée à 10 (en haut de l'écran) avec une taille de police de 20 et en couleur noire
            DrawText(textePuces.c_str(), screenWidth / 2 - textWidth / 2, 10, 20, BLACK);


            //7) En haut à droite, écrivez le nombre total de collisions
            string texteCollisions = "Collisions : " + to_string(collisions.size());
            int textWidthColl = MeasureText(texteCollisions.c_str(), 20);
            DrawText(texteCollisions.c_str(), screenWidth - textWidthColl - 10, 10, 20, BLACK);


            //8)Pour chaque puce, faites-la avancer (méthode Move) et dessinez-la (méthode Draw).

            // auto& déclare une référence à chaque élément (shared_ptr<Flee>) du vecteur puces. Ce qui évite de faire une copie inutile du pointeur
            for (auto& puce : puces)
            {
                puce->Move(deltaTime);
                puce->Draw();
            }


            //9) À l'intérieur de la boucle précédente, trouvez une solution pour tester la collision (méthode CollideWith) entre toutes les paires de puces possible
            //Chaque paire devrait être testée une seule fois! Si une collision est détectée, créez et ajoutez un évènement de collision.
            
            // Parcours l'ensemble des puces - size_t est un type entier non signé, adapté pour représenter des tailles (ici, la taille du vecteur).
            for (size_t i = 0; i < puces.size(); i++) {
                // Pour chaque puce à l'indice i, parcourt toutes les puces dont l'indice est supérieur à i. (j = i + 1) Garantit que chaque paire est testée une seule fois
                for (size_t j = i + 1; j < puces.size(); j++) {
                    // Vérifie si les deux puces sont en collision - Appelle la méthode CollideWith() et si elle renvoie true, collision détectée
                    if (puces[i]->CollideWith(puces[j])) {
                        // Crée un nouvel objet CollisionEvent
                        collisions.push_back(make_shared<CollisionEvent>(puces[i], puces[j], totalTime));
                    }
                }
            }


            //11) Dans une nouvelle boucle, pour chaque évènement de collision...
            //11.1) Dessinez un carré blanc transparent de 5 par 5 à chaque position qu'il y a eu une collision
            //11.2) Dessinez une ligne noire transparente entre chaque puce qui a subit une collision
            //Suggestion de couleur: Color{ 25, 25, 25, 25 } et Color{ 255, 255, 255, 25 }

            // auto& déclare une référence à chaque évènement (shared_ptr<CollisionEvent>) du vecteur collisions. Ce qui évite de faire une copie inutile du pointeur
            for (auto& event : collisions)
            {
                // Dessine le carré (transparence gérée par le canal alpha, ici 25 sur 255)
                // static_cast<int>(event->_Position.x) et static_cast<int>(event->_Position.y) : Convertissent les coordonnées en float de la position de l'événement en entiers, car DrawRectangle attend des positions en pixels (entiers).
                DrawRectangle(static_cast<int>(event->_Position.x), static_cast<int>(event->_Position.y), 5, 5, Color{ 255, 255, 255, 25 });

                // Récupére les positions des puces en vérifiant que le weak_ptr est valide
                if (auto puce1 = event->_LowerIndexFlee.lock())
                {
                    if (auto puce2 = event->_HigherIndexFlee.lock())
                    {
                        Vector2 pos1 = puce1->GetPosition();
                        Vector2 pos2 = puce2->GetPosition();
                        // Trace une ligne épaisse de 2 pixels
                        DrawLineEx(pos1, pos2, 2.0f, Color{ 25, 25, 25, 25 });
                    }
                }
            }


            //12) À chaque dois qu'on pèse sur espace, une puce doit être supprimez. Votre programme ne devrait pas crasher si vous l'avez fait correctement!
            if (IsKeyPressed(KEY_SPACE))
            {
                // Supprime la dernière puce du vector si le vector n'est pas vide
                if (!puces.empty())
                {
                    puces.pop_back();
                }
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}