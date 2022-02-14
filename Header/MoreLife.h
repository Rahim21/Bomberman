#ifndef MORELIFE_H
#define MORELIFE_H

#include "Item.h"
#include "Player.h"

/**
 * \class MoreLife
 * \author HAYAT Rahim / MTARFI Souhail
 */
class MoreLife : public Item
{
protected:
public:
    void addLife(Player p);
};

#endif