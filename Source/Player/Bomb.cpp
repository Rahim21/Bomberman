#include <iostream>
#include "Bomb.h" // linked with makefile

// Méthodes de notre classe Bomb
// Bomb::Bomb() : Position{i, j} {}

Bomb::Bomb(const int i, const int j) : Position{i, j}
{
    this->i = i;
    this->j = j;
}

void Bomb::infligerDegat()
{
    /* Inflige des dégâts aux Players, Mobs, Dirt, Bomb? qui explose à son tour*/
}

void Bomb::afficherExplosion()
{
    std::cout << "@" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bomb &b)
{
    os << "O" << std::endl;
    return os;
}