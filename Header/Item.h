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
public:
    Item(const int i, const int j, std::string symbole);
};

#endif