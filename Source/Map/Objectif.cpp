#include <iostream>
#include "Objectif.h" // linked with makefile

// Méthodes de notre classe Objectif

Objectif::Objectif(const int i, const int j, std::string symbole) : Tile{i, j, symbole}
{
    this->i = i;
    this->j = j;
    this->symbole = symbole;
}

void Objectif::displayObject()
{
    if (exploded)
    {
        symbole = char(176);
        exploded = false;
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
        else if (tileHP < 1)
        {
            symbole = "X";
        }
    }
    std::cout << "  " + symbole + "  ";
}

void Objectif::receiveBombDamage(int degat)
{
    tileHP -= 1 * degat;
}