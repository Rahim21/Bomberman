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
    friend std::ostream &operator<<(std::ostream &os, const Bowman &b);
};

#endif

// peut attaquer notre Bomberman à distance, mais pas à travers les murs