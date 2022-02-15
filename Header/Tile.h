#ifndef TILE_H
#define TILE_H

#include "Position.h"

/**
 * \class Tile
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Tile
{
public:
    int tileHP{2};
    bool murPresent{true};
    Position positionTile{0.f, 0.f};

public:
    virtual void afficherTile();
};

#endif