#ifndef WALL_H
#define WALL_H

#include "Tile.h"

/**
 * \class Wall
 * \author HAYAT Rahim / MTARFI Souhail
 */
class Wall : public Tile
{
protected:
public:
    friend std::ostream& operator<<(std::ostream& os,const Wall& w);
};

#endif