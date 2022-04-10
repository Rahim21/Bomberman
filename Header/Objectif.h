#ifndef OBJECTIF_H
#define OBJECTIF_H
#include "Tile.h"

/**
 * \class Objectif
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Objectif : public Tile
{
public:
    /**
     * @brief Construct a new Objectif object
     *
     * @param i
     * @param j
     * @param symbole
     */
    Objectif(const int i, const int j, const std::string symbole = "W");

    /**
     * @brief display the Objectif
     *
     */
    void displayObject();

    /**
     * @brief the Objectif wall will receive damage before become an objectif
     *
     * @param degat
     */
    void receiveBombDamage(int degat);
};

#endif