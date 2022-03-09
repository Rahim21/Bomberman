#ifndef BOMB_H
#define BOMB_H

#include "Position.h"
#include <ostream>

/**
 * \class Bomb
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Bomb : public Position
{
public:
    int puissance;
    int portee;

public:
    // Bomb();
    Bomb(const int i, const int j);
    void infligerDegat();
    void afficherExplosion();
    void displayObject();
    void setBombIJ(int i, int j);
};

#endif

/*
Classe bombe
lorsqu'elle détruie un mur Dirt donc (0 tileHP)
dans la map avec les coordonnée on remplace la tuile par une tuile Grass
pour avoir les spécificités du Grass par la suite et non plus celle d'un mur.
*/