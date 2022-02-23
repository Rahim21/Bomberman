#ifndef DIRT_H
#define DIRT_H

#include "Tile.h"

/**
 * \class Dirt
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Dirt : public Tile
{
public:
    Dirt(const int i, const int j);
    friend std::ostream &operator<<(std::ostream &os, const Dirt &d);
};

#endif