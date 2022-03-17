#include <iostream>
#include "MoreLife.h" // linked with makefile

// Méthodes de notre classe MoreLife [augmente le nombre de points de vie de notre Bomberman]
MoreLife::MoreLife(const int i, const int j, std::string symbole) : Item{i,j,symbole}
{
    this->i = i;
    this->j = j;
    this->symbole = symbole;
}

void MoreLife::addLife(Player &p)
{
    if (p.heart < 5)
    {
        p.heart += 1;
    }
}