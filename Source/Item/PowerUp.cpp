#include <iostream>
#include "PowerUp.h" // linked with makefile

// Méthodes de notre classe PowerUp [augmente la puissance des bombes]
PowerUp::PowerUp(const int i, const int j, std::string symbole) : Item{i,j,symbole}
{
    this->i = i;
    this->j = j;
    this->symbole = symbole;
}

void PowerUp::addPower(Bomb &b)
{
    if (b.puissance < 3)
    {
        b.puissance += 1;
    }
}