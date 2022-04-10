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
    /**
     * @brief Construct a new Item object
     *
     * @param i
     * @param j
     * @param symbole
     */
    Item(const int i, const int j, std::string symbole);
};

#endif