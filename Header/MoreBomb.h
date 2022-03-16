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
    MoreBomb(const int i, const int j, const std::string symbole = "!");
    void addBomb(Player &p);
};

#endif