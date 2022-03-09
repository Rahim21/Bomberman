#ifndef ITEM_H
#define ITEM_H

#include "Position.h"
#include "Player.h"
#include "Bomb.h"

/**
 * \class Item
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Item : public Position
{
protected:
public:
    Item();
    void displayObject();
    // virtual void afficherItem();
};

#endif