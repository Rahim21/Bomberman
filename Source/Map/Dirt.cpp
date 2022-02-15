#include <iostream>
#include "Dirt.h" // linked with makefile

// Méthodes de notre classe Dirt
void Dirt::afficherTile()
{
    if (murPresent)
    {
        if (tileHP >= 2)
        {
            std::cout << "W" << std::endl;
        }
        else if (tileHP == 1)
        {
            std::cout << "w" << std::endl;
        }
        else
        {
            murPresent = false;
        }
    }
    // changer le Dirt en Grass DANS LA METHODE Là où le mur est DETRUIT et enlever ce else
    else
    {
        std::cout << "" << std::endl;
    }
}