#ifndef MOREBOMB_H
#define MOREBOMB_H

#include "Item.h"
#include "Player.h"

/**
 * \class MoreBomb
 * \author HAYAT Rahim / MTARFI Souhail
 */
class MoreBomb : public Item
{
protected:
public:
    void addBomb(Player &p);
    void afficherItem();
};

#endif