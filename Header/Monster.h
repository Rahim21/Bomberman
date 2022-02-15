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
    friend std::ostream& operator<<(std::ostream& os,const Monster& m);
};

#endif

// ne peut pas traverser les murs ni les bombes
