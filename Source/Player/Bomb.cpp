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

void Bomb::displayObject()
{
    std::cout << "  O  ";
}

void Bomb::setBombIJ(int i, int j)
{
    this->i = i;
    this->j = j;
}