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
    friend std::ostream& operator<<(std::ostream& os,const Ghost& g);
};

#endif

// peut traverser les murs sauf extérieurs et les bombes