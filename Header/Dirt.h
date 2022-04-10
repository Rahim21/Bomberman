#ifndef DIRT_H
#define DIRT_H

#include "Tile.h"

/**
 * \class Dirt
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Dirt : public Tile
{
public:
    /**
     * @brief Construct a new Dirt object
     *
     * @param i
     * @param j
     * @param symbole
     */
    Dirt(const int i, const int j, const std::string symbole = "W");

    /**
     * @brief display the dirt
     *
     */
    void displayObject();

    /**
     * @brief dirt receive damage by the bomb
     *
     * @param degat
     */
    void receiveBombDamage(int degat);
};

#endif