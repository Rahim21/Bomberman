#include <iostream>
#include "MoreLife.h" // linked with makefile

// Méthodes de notre classe MoreLife [augmente le nombre de points de vie de notre Bomberman]
MoreLife::MoreLife(const int i, const int j) : Item{}
{
    this->i = i;
    this->j = j;
}

void MoreLife::addLife(Player &p)
{
    if (p.heart < 5)
    {
        p.heart += 1;
    }
}

void MoreLife::displayObject()
{
    std::cout << "  L  ";
}