#ifndef PLAYER_H
#define PLAYER_H

#include "Position.h"
#include "Item.h"
#include "Bomb.h"
//#include <string>

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
    Bomb *playerBomb[3] = {nullptr, nullptr, nullptr};
    bool bombPlaced{false};

public:
    Player(const int i, const int j, std::string pseudo = "", const std::string symbole = "P");
    void playerAction();
    void verficationObstacle(const char &keyPressed);
    // void poserBombe(Map &carte, int &getPlayerI, int &getPlayerJ, int &i2, int &j2);
    void displayObject();
    void receiveBombDamage(int degat);
    void infoPlayer();
    std::string toString();
    int getPlayerI();
    int getPlayerJ();
    void setPlayerI(int _i);
    void setPlayerJ(int _j);
};

#endif