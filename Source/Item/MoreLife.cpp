#include <iostream>
#include "MoreLife.h" // linked with makefile

// Méthodes de notre classe MoreLife [augmente le nombre de points de vie de notre Bomberman]
void MoreLife::addLife(Player &p)
{
    if (p.heart < 5)
    {
        p.heart += 1;
    }
}
std::ostream& operator<<(std::ostream& os,const MoreLife& ML){
    os<<"ML"<<std::endl;
    return os;
}