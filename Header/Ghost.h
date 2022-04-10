#ifndef GHOST_H
#define GHOST_H

#include "Mob.h"

/**
 * \class Ghost
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Ghost : public Mob
{
public:
    // std::vector<Position *> inventory;

    /**
     * @brief the ghost has inventory with 2 slots
     *
     */
    Position *inventory[2] = {nullptr, nullptr};

    /**
     * @brief Construct a new Ghost object
     *
     * @param i
     * @param j
     * @param symbole
     */
    Ghost(const int i, const int j, const std::string symbole = "G");

    /**
     * @brief the ghost damage the player
     *
     * @param p
     */
    void damager(Player &p);
};

#endif

// peut traverser les murs sauf extérieurs et les bombes