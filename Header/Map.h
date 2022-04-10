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
    int level{1};

    char map[mapLigne][mapColonne];
    Position *positionObject[mapLigne][mapColonne];
    std::vector<Player *> joueur;
    std::vector<Mob *> mob;
    std::vector<Arrow *> arrow;

public:
    /**
     * @brief display all the symbole
     *
     * @param os
     * @param m
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Map &m);

    /**
     * @brief Create a Map object
     *
     * @param m
     */
    void createMap(Map &m);

    /**
     * @brief checks if the character is in the list
     *
     * @param id
     * @param i
     * @param j
     * @return char
     */
    char verificationID(const char id, const int i, const int j);

    /**
     * @brief convert the char to object
     *
     * @param id
     * @param i
     * @param j
     */
    void convertObjectByID(const char id, const int i, const int j);

    /**
     * @brief delete all the object
     *
     */
    void deleteAllObject();

    /**
     * @brief delete the map
     *
     * @param m
     */
    void deleteMap(Map &m);

    /**
     * @brief if the object is destroyed in-game it destroy the object
     *
     */
    void detectDestroyedObject();

    /**
     * @brief pass to the next level -> indentation
     *
     */
    void newLevel();

    /**
     * @brief load the new level map
     *
     * @param level
     */
    void loadMap(const int level);

    /**
     * @brief color the symbole of each object
     *
     * @param symbole
     * @return int
     */
    int colorSymbole(std::string symbole) const;
};

#endif