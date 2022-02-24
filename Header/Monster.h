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
    friend std::ostream &operator<<(std::ostream &os, const Monster &m);
     int getMonsterI();
    int getMonsterJ();
    void setMonsterI(int _i);
    void setMonsterJ(int _j);
};

#endif

// ne peut pas traverser les murs ni les bombes
