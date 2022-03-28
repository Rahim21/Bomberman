#include <iostream>
#include "Dirt.h" // linked with makefile

// Méthodes de notre classe Dirt
Dirt::Dirt(const int i, const int j, std::string symbole) : Tile{i, j, symbole}
{
    this->i = i;
    this->j = j;
    this->symbole = symbole;
}

void Dirt::displayObject()
{
    if (exploded)
    {
        symbole = char(176);
        exploded = false;
        // std::cout << " " + symbole + "  ";
    }
    else
    {
        if (tileHP >= 2)
        {
            symbole = "W";
        }
        else if (tileHP == 1)
        {
            symbole = "w";
        }
    }
    std::cout << "  " + symbole + "  ";
}

void Dirt::receiveBombDamage(int degat)
{
    tileHP -= 1 * degat;
    if (tileHP <= 0)
    {
        destroyed = true;
    }
}