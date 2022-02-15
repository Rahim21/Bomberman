#ifndef POWERUP_H
#define POWERUP_H

#include "Item.h"
#include "Bomb.h"

/**
 * \class PowerUp
 * \author HAYAT Rahim / MTARFI Souhail
 */
class PowerUp : public Item
{
protected:
public:
    void addPower(Bomb &b);
    void afficherItem();
};

#endif