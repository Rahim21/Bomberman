#ifndef MOREBOMB_H
#define MOREBOMB_H

#include "Item.h"

/**
 * \class MoreBomb
 * \author HAYAT Rahim / MTARFI Souhail
 */
class MoreBomb : public Item
{
protected:
public:
    void addBomb(Player &p);
    friend std::ostream &operator<<(std::ostream &os, const MoreBomb &MB);
};

#endif