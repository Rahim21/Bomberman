#ifndef SCALEUP_H
#define SCALEUP_H

#include "Item.h"

/**
 * \class ScaleUp
 * \author HAYAT Rahim / MTARFI Souhail
 */
class ScaleUp : public Item
{
protected:
public:
    ScaleUp(const int i, const int j, const std::string symbole = "#");
    void addScale(Bomb &b);
};

#endif