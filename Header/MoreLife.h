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
    MoreLife(const int i, const int j);
    void addLife(Player &p);
    friend std::ostream &operator<<(std::ostream &os, const MoreLife &ML);
};

#endif