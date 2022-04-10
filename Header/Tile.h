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
    int tileHP{2};
    bool murPresent{true};
    /**
     * @brief Construct a new Tile object
     *
     * @param i
     * @param j
     * @param symbole
     */
    Tile(const int i, const int j, std::string symbole);
};

#endif