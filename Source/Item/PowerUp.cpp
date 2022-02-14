#include <iostream>
#include "PowerUp.h" // linked with makefile

// Méthodes de notre classe PowerUp [augmente la puissance des bombes]
void addPower(Bomb b)
{
    if (b.puissance<3)
    {
        b.puissance+=1;
    }
    
}