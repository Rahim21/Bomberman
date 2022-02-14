#ifndef PLAYER_H
#define PLAYER_H

#include "Position.h"
#include <string>

/**
 * \class Player
 * \brief Notre Bomberman
 * \author HAYAT Rahim / MTARFI Souhail
 *
 * explication...
 */
class Player
{
public:
    std::string pseudo;
    int coeur;
    int nbrBomb;
    float speed;
    Position playerPosition;

public:
    Player(std::string pseudo);

    void deplacement();
    void poserBombe();
    void afficherPlayer();
    std::string toString();
};

#endif