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
    PowerUp(const int i, const int j, const std::string symbole = "U");
    void addPower(Bomb &b);
};

#endif