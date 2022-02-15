#ifndef MOB_H
#define MOB_H

#include "Position.h"

/**
 * \class Mob
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Mob
{
protected:
    int hp;
    int damage;
    float speed;
    Position mobPosition;

public:
    Mob();
    void deplacement();
    virtual void afficherMob();
};

#endif