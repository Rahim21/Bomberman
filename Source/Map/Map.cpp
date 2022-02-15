#include <iostream>
#include "Map.h" // linked with makefile

// Méthodes de notre classe Map
void Map::afficherMap()
{
    /* Mauvaise méthode d'affichage : pas optimal pour la suite */
    std::cout << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
    for (int i = 0; i < mapLigne; i++)
    {
        for (int tailleJ = 0; tailleJ < 3; tailleJ++)
        {
            for (int j = 0; j < mapColonne; j++)
            {
                std::cout << "|     ";
            }
            std::cout << "|" << std::endl;
        }
        std::cout << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
    }
}