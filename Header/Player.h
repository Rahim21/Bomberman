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
class Player : public Position
{
public:
    std::string pseudo;
    int heart{3};
    int nbrBomb{1};
    int speed{1};

public:
    Player(const int i, const int j, std::string pseudo = "");
    void playerAction();
    void deplacement(const char &keyPressed);
    void poserBombe();
    friend std::ostream &operator<<(std::ostream &os, const Player &p);
    void infoPlayer();
    std::string toString();

    int getPlayerI();
    int getPlayerJ();
};

#endif