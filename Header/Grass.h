#ifndef GRASS_H
#define GRASS_H

#include "Tile.h"

/**
 * \class Grass
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Grass : public Tile
{
protected:
public:
    /**
     * @brief Construct a new Grass object
     *
     * @param i
     * @param j
     * @param symbole
     */
    Grass(const int i, const int j, const std::string symbole = " ");
};

#endif