#ifndef PLAYER_H
#define PLAYER_H

#include "Position.h"
#include "Item.h"
#include "Bomb.h"
#include <vector>

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
    std::vector<Bomb *> playerBomb;
    bool bombPlaced{false};

public:
    /**
     * @brief Construct a new Player object
     *
     * @param i
     * @param j
     * @param pseudo
     * @param symbole
     */
    Player(const int i, const int j, std::string pseudo = "", const std::string symbole = "P");

    /**
     * @brief verify if any obstacle before move the player
     *
     * @param keyPressed
     */
    void verficationObstacle(const char &keyPressed);

    /**
     * @brief display the player, alone or with a bomb
     *
     */
    void displayObject();

    /**
     * @brief the player receive bomb damage
     *
     * @param degat
     */
    void receiveBombDamage(int degat);

    /**
     * @brief info about the player : heart, number of bomb, ...
     *
     */
    void infoPlayer();

    /**
     * @brief display all the player info bar
     *
     * @return std::string
     */
    std::string toString();

    /**
     * @brief Get the Player I object
     *
     * @return int
     */
    int getPlayerI();

    /**
     * @brief Get the Player J object
     *
     * @return int
     */
    int getPlayerJ();

    /**
     * @brief Set the Player I object
     *
     * @param _i
     */
    void setPlayerI(int _i);

    /**
     * @brief Set the Player J object
     *
     * @param _j
     */
    void setPlayerJ(int _j);
};

#endif