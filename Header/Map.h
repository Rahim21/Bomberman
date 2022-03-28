#ifndef MAP_H
#define MAP_H

#include "Position.h"

#include "Item.h"
#include "MoreLife.h"
#include "MoreBomb.h"
#include "PowerUp.h"
#include "SpeedUp.h"
#include "ScaleUp.h"

#include "Tile.h"
#include "Grass.h"
#include "Wall.h"
#include "Dirt.h"
#include "Arrow.h"
#include "Mob.h"
#include "Monster.h"
#include "Ghost.h"
#include "Bowman.h"
#include "Objectif.h"

#include <vector>

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
    Position *positionObject[mapLigne][mapColonne];
    std::vector<Player *> joueur;
    std::vector<Mob *> mob;
    std::vector<Arrow *> arrow;

public:
    friend std::ostream &operator<<(std::ostream &os, const Map &m);
    void createMap(Map &m);
    char verificationID(const char id, const int i, const int j);
    void convertObjectByID(const char id, const int i, const int j);
    void deleteAllObject();
    void deleteMap(Map &m);
    void detectDestroyedObject();
};

#endif