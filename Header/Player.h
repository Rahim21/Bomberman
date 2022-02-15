#ifndef PLAYER_H
#define PLAYER_H

#include "Position.h"
#include "Item.h"
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
    int heart{3};
    int nbrBomb{1};
    int speed{1};
    Position playerPosition;

public:
    Player(std::string pseudo);

    void deplacement();
    void poserBombe();
    friend std::ostream& operator<<(std::ostream& os,const Player& p);
    void infoPlayer();
    std::string toString();
};

#endif