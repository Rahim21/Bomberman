#include <iostream>
#include "SpeedUp.h" // linked with makefile

// Méthodes de notre classe SpeedUp [augmente la vitesse du Bomberman]
SpeedUp::SpeedUp(const int i, const int j) : Item{}
{
    this->i = i;
    this->j = j;
}

void SpeedUp::addSpeed(Player &p)
{
    if (p.speed < 3)
    {
        p.speed += 1;
    }
}
std::ostream &operator<<(std::ostream &os, const SpeedUp &SP)
{
    os << "SP" << std::endl;
    return os;
}