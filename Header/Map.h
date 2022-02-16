#ifndef MAP_H
#define MAP_H

#include "Tile.h"

/**
 * \class Map
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Map
{
public:
    static constexpr int mapColonne{14};
    static constexpr int mapLigne{6};
    // objectif ?
    char map[mapLigne][mapColonne];

public:
    friend std::ostream &operator<<(std::ostream &os, const Map &m);
    void createMap(Map &m);
    char verificationID(const char id);
    void convertObjectByID(const char id);
    // void Map::deleteObject(Map &m);
};

#endif