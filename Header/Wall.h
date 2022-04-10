#ifndef WALL_H
#define WALL_H

#include "Tile.h"

/**
 * \class Wall
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Wall : public Tile
{
protected:
public:
    /**
     * @brief Construct a new Wall object
     *
     * @param i
     * @param j
     * @param symbole
     */
    Wall(const int i, const int j, const std::string symbole = "I");
};

#endif