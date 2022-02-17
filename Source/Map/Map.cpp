#include <iostream>
#include "Map.h" // linked with makefile
#include <fstream>
#include <vector>
#include <algorithm>

// Méthodes de notre classe Map
void Map::createMap(Map &m)
{
    char caractere;
    std::string filename("Source/Map/map.txt");
    std::ifstream fichier(filename, std::ios::in);
    if (fichier)
    {
        for (int i = 0; i < mapLigne; i++)
        {
            for (int j = 0; j < mapColonne; j++)
            {
                fichier.get(caractere);
                if (caractere == '\n')
                {
                    fichier.get(caractere);
                }
                map[i][j] = m.verificationID(caractere);
            }
        }
        fichier.close();
    }
    else
    {
        std::cerr << "Impossible d'ouvrir le fichier - '" << filename << "'" << std::endl;
        exit(1);
    }
}

std::ostream &operator<<(std::ostream &os, const Map &m)
{
    /* Mauvaise méthode d'affichage : pas optimal pour la suite */
    os << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
    for (int i = 0; i < m.mapLigne; i++)
    {
        for (int tailleJ = 0; tailleJ < 3; tailleJ++)
        {
            for (int j = 0; j < m.mapColonne; j++)
            {
                if (tailleJ == 1)
                {
                    os << "|  ";

                    // m.convertObjectByID(m.map[i][j]);
                    os << m.map[i][j];
                    // faire une surcharge d'opérateur pour afficher l'objet

                    os
                        << "  ";
                }
                else
                {
                    os << "|     ";
                }
            }
            os << "|" << std::endl;
        }
        os << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
    }
    return os;
}

char Map::verificationID(const char id)
{
    std::string charList = "PX,WwI0@MGBLU!Z#<>^|v";
    if (!(std::find(std::begin(charList), std::end(charList), id) != std::end(charList)))
    {
        std::cerr << "Erreur lors de la construction de la map" << std::endl;
        exit(1);
    }
    // méthode pour la création d'objet dynamique
    convertObjectByID(id);
    if (id == ',')
    {
        return ' ';
    }
    return id;
}

void Map::convertObjectByID(const char id)
{
    Player *p;
    switch (id)
    {
    case 'P':
        p = new Player("Player");
        p->infoPlayer();
        delete p;
        break;
    case 'X':
        // p = new Player("Player");
        break;
    case ',':
        // p = new Player("Player");
        break;
    case 'W':
        // p = new Player("Player");
        break;
    case 'w':
        // p = new Player("Player");
        break;
    case 'I':
        // p = new Player("Player");
        break;
    case '0':
        // p = new Player("Player");
        break;
    case '@':
        // p = new Player("Player");
        break;
    case 'M':
        // p = new Player("Player");
        break;
    case 'G':
        // p = new Player("Player");
        break;
    case 'B':
        // p = new Player("Player");
        break;
    case 'L':
        // p = new Player("Player");
        break;
    case 'U':
        // p = new Player("Player");
        break;
    case '!':
        // p = new Player("Player");
        break;
    case 'Z':
        // p = new Player("Player");
        break;
    case '#':
        // p = new Player("Player");
        break;
    case '<':
        // p = new Player("Player");
        break;
    case '>':
        // p = new Player("Player");
        break;
    case '^':
        // p = new Player("Player");
        break;
    case '|':
        // p = new Player("Player");
        break;
    case 'v':
        // p = new Player("Player");
        break;
    }
}

// méthode pour supprimer les objets en fin de jeu
// void Map::deleteObject(Map &m)
// {
// }