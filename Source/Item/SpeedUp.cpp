#include <iostream>
#include "SpeedUp.h" // linked with makefile

// Méthodes de notre classe SpeedUp [augmente la vitesse du Bomberman]
void SpeedUp::addSpeed(Player &p)
{
    if (p.speed < 3)
    {
        p.speed += 1;
    }
}

void SpeedUp::afficherItem()
{
    std::cout << "SP" << std::endl;
}