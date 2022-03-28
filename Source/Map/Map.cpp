#include <iostream>
#include "Map.h" // linked with makefile
#include <fstream>
#include <vector>
#include <algorithm>

// Méthodes de notre classe Map
void Map::createMap(Map &m)
{
    char caractere;
    // ICI
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
                map[i][j] = m.verificationID(caractere, i, j);

                // exemple : vérification d'objet + utilisation de sa methode
                // l'opérande d'un dynamic_cast d'exécution doit avoir un type classe polymorphe : Position à donc un virtual
                // if (dynamic_cast<Player *>(positionObject[i][j]) != nullptr)
                // {
                //     static_cast<Player *>(positionObject[i][j])->infoPlayer();
                // }
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

void Map::deleteMap(Map &m)
{
    delete &m;
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
                    os << "|";
                    m.positionObject[i][j]->displayObject();
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

char Map::verificationID(const char id, const int i, const int j)
{
    std::string charList = "PX,WwI0@MGBLU!Z#<>^|v";
    if (!(std::find(std::begin(charList), std::end(charList), id) != std::end(charList)))
    {
        std::cerr << "Erreur lors de la construction de la map" << std::endl;
        exit(1);
    }
    // méthode pour la création d'objet dynamique
    convertObjectByID(id, i, j);
    if (id == ',')
    {
        return ' ';
    }
    return id;
}

void Map::convertObjectByID(const char id, const int i, const int j)
{
    switch (id)
    {
    case 'P':
        positionObject[i][j] = new Player(i, j);
        joueur.push_back(static_cast<Player *>(positionObject[i][j]));
        break;
     case 'X':
        positionObject[i][j] = new Objectif(i, j);
        break;
    case ',':
        positionObject[i][j] = new Grass(i, j);
        break;
    case 'W':
    case 'w':
        positionObject[i][j] = new Dirt(i, j);
        break;
    case 'I':
        positionObject[i][j] = new Wall(i, j);
        break;
    case '0':
        positionObject[i][j] = new Bomb(i, j);
        break;
    case 'M':
        positionObject[i][j] = new Monster(i, j);
        mob.push_back(static_cast<Mob *>(positionObject[i][j]));
        break;
    case 'G':
        positionObject[i][j] = new Ghost(i, j);
        mob.push_back(static_cast<Mob *>(positionObject[i][j]));
        break;
    case 'B':
        positionObject[i][j] = new Bowman(i, j);
        mob.push_back(static_cast<Mob *>(positionObject[i][j]));
        break;
    case 'L':
        positionObject[i][j] = new MoreLife(i, j);
        break;
    case 'U':
        positionObject[i][j] = new PowerUp(i, j);
        break;
    case '!':
        positionObject[i][j] = new MoreBomb(i, j);
        break;
    case 'Z':
        positionObject[i][j] = new SpeedUp(i, j);
        break;
    case '#':
        positionObject[i][j] = new ScaleUp(i, j);
        break;
    default:
        positionObject[i][j] = new Grass(i, j);
    }
}

// methode pour supprimer tout les objets et vectors de joueur et de mob
void Map::deleteAllObject()
{
    for (int i = 0; i < mapLigne; i++)
    {
        for (int j = 0; j < mapColonne; j++)
        {
            delete positionObject[i][j];
        }
    }
    joueur.clear();
    mob.clear();
}

void Map::detectDestroyedObject()
{
    for (int i = 0; i < mapLigne; i++)
    {
        for (int j = 0; j < mapColonne; j++)
        {
            if (positionObject[i][j]->destroyed)
            {
                positionObject[i][j] = new Grass(i, j);
            }
        }
    }
    for (int mobtab = 0; mobtab < mob.size(); mobtab++)
    {
        if (mob[mobtab]->destroyed)
        {
            mob.erase(mob.begin() + mobtab);
        }
    }
}