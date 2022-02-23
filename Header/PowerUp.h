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
    PowerUp(const int i, const int j);
    void addPower(Bomb &b);
    friend std::ostream &operator<<(std::ostream &os, const PowerUp &PU);
};

#endif