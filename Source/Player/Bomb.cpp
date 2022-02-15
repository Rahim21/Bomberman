#include <iostream>
#include "Bomb.h" // linked with makefile

// Méthodes de notre classe Bomb
void Bomb::infligerDegat()
{
    /* Inflige des dégâts aux Players, Mobs, Dirt, Bomb? qui explose à son tour*/
}

void Bomb::afficherExplosion()
{
    std::cout << "@" << std::endl;
}

std::ostream& operator<<(std::ostream& os,const Bomb& b){
    os<<"O"<<std::endl;
    return os;
}