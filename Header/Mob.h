#ifndef MOB_H
#define MOB_H

#include "Position.h"

/**
 * \class Mob
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Mob : public Position
{
protected:
    int hp;
    int damage;
    float speed;

public:
    Mob();
    void deplacement();
    // virtual void afficherMob();
};

#endif