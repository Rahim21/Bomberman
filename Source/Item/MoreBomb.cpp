#include <iostream>
#include "MoreBomb.h" // linked with makefile

// Méthodes de notre classe MoreBomb [augmente le nombre de bombes]
void MoreBomb::addBomb(Player &p)
{
    if (p.nbrBomb < 3)
    {
        p.nbrBomb += 1;
    }
}

std::ostream& operator<<(std::ostream& os,const MoreBomb& MB){
    os<<"MB"<<std::endl;
    return os;
}