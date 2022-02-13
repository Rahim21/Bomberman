#ifndef PLAYER_H
#define PLAYER_H

#include "Position.h"
#include <string>

/**
 * \class Player
 * \brief Notre Bomberman
 * \author HAYAT Rahim
 *
 * explication...
 */
class Player
{
protected:
    std::string pseudo;
    int hp;
    int bombLimit;
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