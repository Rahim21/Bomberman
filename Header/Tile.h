#ifndef TILE_H
#define TILE_H

#include "Position.h"

/**
 * \class Tile
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Tile
{
protected:
    Position positionTile{0.f, 0.f};

public:
    void afficherTile();
};

#endif