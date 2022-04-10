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
    /**
     * @brief Construct a new More Bomb object
     *
     * @param i
     * @param j
     * @param symbole
     */
    MoreBomb(const int i, const int j, const std::string symbole = "!");

    /**
     * @brief add more bomb for the player
     *
     * @param p
     */
    void addBomb(Player &p);
};

#endif