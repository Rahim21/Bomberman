#ifndef GRASS_H
#define GRASS_H

#include "Tile.h"

/**
 * \class Grass
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Grass : public Tile
{
protected:
public:
    Grass(const int i, const int j);
    friend std::ostream &operator<<(std::ostream &os, const Grass &g);
};

#endif