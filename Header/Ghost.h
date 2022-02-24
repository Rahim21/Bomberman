#ifndef GHOST_H
#define GHOST_H

#include "Mob.h"

/**
 * \class Ghost
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Ghost : public Mob
{
protected:
public:
    Ghost(const int i, const int j);
    friend std::ostream &operator<<(std::ostream &os, const Ghost &g);
    int getMobI();
    int getMobJ();
    void setMobI(int _i);
    void setMobJ(int _j);
};

#endif

// peut traverser les murs sauf extérieurs et les bombes