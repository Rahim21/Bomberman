#ifndef BOWMAN_H
#define BOWMAN_H

#include "Mob.h"

/**
 * \class Bowman
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Bowman : public Mob
{
protected:
public:
    /**
     * @brief Construct a new Bowman object
     *
     * @param i
     * @param j
     * @param symbole
     */
    Bowman(const int i, const int j, const std::string symbole = "B");

    /**
     * @brief damege the player
     *
     * @param p
     */
    void damager(Player &p);
};

#endif

// peut attaquer notre Bomberman à distance, mais pas à travers les murs