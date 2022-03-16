#ifndef TILE_H
#define TILE_H

#include "Position.h"

/**
 * \class Tile
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Tile : public Position
{
public:
    Tile();
    int tileHP{2};
    bool murPresent{true};
};

#endif