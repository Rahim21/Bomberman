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
    Monster(const int i, const int j);
    void displayObject();
    int getMobI();
    int getMobJ();
    void setMobI(int _i);
    void setMobJ(int _j);
    void damager(Player &p);
};

#endif

// ne peut pas traverser les murs ni les bombes
