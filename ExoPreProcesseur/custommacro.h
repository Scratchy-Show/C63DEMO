//#pragma once

#ifndef CUSTOMMACRO_H
#define CUSTOMMACRO_H

// Définition des constantes
#define NATURAL_NUMBER 2.73f
#define FIBONNACCI_NUMBER 1.618f

// Définition initiale de WIERD_NUMBER (sans protection par parenthèses)
#define WIERD_NUMBER(NATURAL_NUMBER, FIBONNACCI_NUMBER) NATURAL_NUMBER + FIBONNACCI_NUMBER

// Détruit la macro initiale
#undef WIERD_NUMBER

// Redéfinition correcte avec des parenthèses pour respecter l'ordre des opérations
#define WIERD_NUMBER(a, b) ((a) + (b))

#define WIERD_NUMBER(NATURAL_NUMBER, FIBONNACCI_NUMBER) NATURAL_NUMBER + FIBONNACCI_NUMBER
#define WIERD_NUMBER(NATURAL_NUMBER, FIBONNACCI_NUMBER) ((NATURAL_NUMBER) + (FIBONNACCI_NUMBER))

// Définition de la macro LOG qui ajoute le nom du fichier et le numéro de ligne au message
#define LOG(message) std::cout << "[ Fichier: " << __FILE__ << " Ligne: " << __LINE__ << "] " << message << std::endl

#endif // CUSTOMMACRO_H