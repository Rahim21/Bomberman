#ifndef MAP_H
#define MAP_H

#include "Tile.h"

/**
 * \class Map
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Map
{
protected:
    static constexpr int mapColonne{14};
    static constexpr int mapLigne{6};
    // objectif ?
    Tile map[mapLigne][mapColonne];

public:
    friend std::ostream& operator<<(std::ostream& os,const Map& m);
};

#endif