#ifndef MONSTER_H
#define MONSTER_H

#include "Mob.h"
#include "Position.h"

/**
 * \class Monster
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Monster : public Mob
{
protected:
public:
    /**
     * @brief Construct a new Monster object
     *
     * @param i
     * @param j
     * @param symbole
     */
    Monster(const int i, const int j, const std::string symbole = "M");

    /**
     * @brief the monster damage the player
     *
     * @param p
     */
    void damager(Player &p);

    /**
     * @brief the monster receive damage from the bomb
     *
     * @param degat
     */
    void receiveBombDamage(int degat);
};

#endif

// ne peut pas traverser les murs ni les bombes
