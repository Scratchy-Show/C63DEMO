//#pragma once

#ifndef CUSTOMMACRO_H
#define CUSTOMMACRO_H

// D�finition des constantes
#define NATURAL_NUMBER 2.73f
#define FIBONNACCI_NUMBER 1.618f

// D�finition initiale de WIERD_NUMBER (sans protection par parenth�ses)
#define WIERD_NUMBER(NATURAL_NUMBER, FIBONNACCI_NUMBER) NATURAL_NUMBER + FIBONNACCI_NUMBER

// D�truit la macro initiale
#undef WIERD_NUMBER

// Red�finition correcte avec des parenth�ses pour respecter l'ordre des op�rations
#define WIERD_NUMBER(a, b) ((a) + (b))

#define WIERD_NUMBER(NATURAL_NUMBER, FIBONNACCI_NUMBER) NATURAL_NUMBER + FIBONNACCI_NUMBER
#define WIERD_NUMBER(NATURAL_NUMBER, FIBONNACCI_NUMBER) ((NATURAL_NUMBER) + (FIBONNACCI_NUMBER))

// D�finition de la macro LOG qui ajoute le nom du fichier et le num�ro de ligne au message
#define LOG(message) std::cout << "[ Fichier: " << __FILE__ << " Ligne: " << __LINE__ << "] " << message << std::endl

#endif // CUSTOMMACRO_H