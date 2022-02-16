#ifndef SPEEDUP_H
#define SPEEDUP_H

#include "Item.h"

/**
 * \class SpeedUp
 * \author HAYAT Rahim / MTARFI Souhail
 */
class SpeedUp : public Item
{
protected:
public:
    void addSpeed(Player &p);
    friend std::ostream &operator<<(std::ostream &os, const SpeedUp &SP);
};

#endif