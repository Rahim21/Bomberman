#ifndef POWERUP_H
#define POWERUP_H

#include "Item.h"

/**
 * \class PowerUp
 * \author HAYAT Rahim / MTARFI Souhail
 */
class PowerUp : public Item
{
protected:
public:
    void addPower(Bomb &b);
    friend std::ostream &operator<<(std::ostream &os, const PowerUp &PU);
};

#endif