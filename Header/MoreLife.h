#ifndef MORELIFE_H
#define MORELIFE_H

#include "Item.h"

/**
 * \class MoreLife
 * \author HAYAT Rahim / MTARFI Souhail
 */
class MoreLife : public Item
{
protected:
public:
    /**
     * @brief Construct a new More Life object
     *
     * @param i
     * @param j
     * @param symbole
     */
    MoreLife(const int i, const int j, const std::string symbole = "L");

    /**
     * @brief add more life for the player
     *
     * @param p
     */
    void addLife(Player &p);
};

#endif