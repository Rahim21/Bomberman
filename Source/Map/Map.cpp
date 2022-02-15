#include <iostream>
#include "Map.h" // linked with makefile

// Méthodes de notre classe Map
std::ostream& operator<<(std::ostream& os,const Map& m){
        /* Mauvaise méthode d'affichage : pas optimal pour la suite */
    os << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
    for (int i = 0; i < m.mapLigne; i++)
    {
        for (int tailleJ = 0; tailleJ < 3; tailleJ++)
        {
            for (int j = 0; j < m.mapColonne; j++)
            {
               os << "|     ";
            }
            os << "|" << std::endl;
        }
        os << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
    }
    return os;
}