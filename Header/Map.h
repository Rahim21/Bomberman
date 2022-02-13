#ifndef MAP_H
#define MAP_H

#include "Tile.h"

/**
 * \class Map
 * \author HAYAT Rahim
 */
class Map
{
protected:
    static constexpr int mapColonne{14};
    static constexpr int mapLigne{6};
    // objectif ?
    Tile map[mapColonne * mapLigne];

public:
    void afficherMap();
};

#endif