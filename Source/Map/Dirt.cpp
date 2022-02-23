#include <iostream>
#include "Dirt.h" // linked with makefile

// Méthodes de notre classe Dirt
Dirt::Dirt(const int i, const int j) : Tile{}
{
    this->i = i;
    this->j = j;
}

std::ostream &operator<<(std::ostream &os, const Dirt &d)
{
    if (d.murPresent)
    {
        if (d.tileHP >= 2)
        {
            os << "W" << std::endl;
        }
        else if (d.tileHP == 1)
        {
            os << "w" << std::endl;
        }
        else
        {
            /*d.murPresent = false;
             - je peux pas modifier ça parceque d est const , et toi tu veux modifier un variable dans un affichage ??!!*/
        }
    }
    // changer le Dirt en Grass DANS LA METHODE Là où le mur est DETRUIT et enlever ce else
    else
    {
        os << "" << std::endl;
    }
    return os;
}

// void Dirt::afficherTile()
// {
//     if (murPresent)
//     {
//         if (tileHP >= 2)
//         {
//             std::cout << "W" << std::endl;
//         }
//         else if (tileHP == 1)
//         {
//             std::cout << "w" << std::endl;
//         }
//         else
//         {
//             murPresent = false;
//         }
//     }
//     // changer le Dirt en Grass DANS LA METHODE Là où le mur est DETRUIT et enlever ce else
//     else
//     {
//         std::cout << "" << std::endl;
//     }
// }