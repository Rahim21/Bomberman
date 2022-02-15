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

void PowerUp::afficherItem()
{
    std::cout << "PU" << std::endl;
}