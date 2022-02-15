#include <iostream>
#include "PowerUp.h" // linked with makefile

// Méthodes de notre classe PowerUp [augmente la puissance des bombes]
void PowerUp::addPower(Bomb &b)
{
    if (b.puissance < 3)
    {
        b.puissance += 1;
    }
}

std::ostream& operator<<(std::ostream& os,const PowerUp& PU){
    os<<"PU"<<std::endl;
    return os;
}