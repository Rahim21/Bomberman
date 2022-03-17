#include <iostream>
#include "SpeedUp.h" // linked with makefile

// Méthodes de notre classe SpeedUp [augmente la vitesse du Bomberman]
SpeedUp::SpeedUp(const int i, const int j, std::string symbole) : Item{i,j,symbole}
{
    this->i = i;
    this->j = j;
    this->symbole = symbole;
}

void SpeedUp::addSpeed(Player &p)
{
    if (p.speed < 3)
    {
        p.speed += 1;
    }
}