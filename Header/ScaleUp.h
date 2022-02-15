#ifndef SCALEUP_H
#define SCALEUP_H

#include "Item.h"
#include "Bomb.h"

/**
 * \class ScaleUp
 * \author HAYAT Rahim / MTARFI Souhail
 */
class ScaleUp : public Item
{
protected:
public:
    void addScale(Bomb &b);
    friend std::ostream& operator<<(std::ostream& os,const ScaleUp& SC);
};

#endif