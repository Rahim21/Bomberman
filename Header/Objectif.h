#ifndef OBJECTIF_H
#define OBJECTIF_H
#include "Tile.h"

/**
 * \class Objectif
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Objectif : public Tile
{
public:
    Objectif(const int i, const int j, const std::string symbole = "W");
    void displayObject();
    void receiveBombDamage(int degat);
};

#endif