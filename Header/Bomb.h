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
    int puissance{2};
    int portee{1};
    int compteARebours{0}; // si 3 : 0 -> @ (la bombe explose)

public:
    // Bomb();
    Bomb(const int i, const int j, const std::string symbole = "O");
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