#include <iostream>
#include "Player.h" // linked with makefile

// Méthodes de notre classe Player
Player::Player(int i, int j, std::string pseudo) : Position{i, j}
{
    this->i = i;
    this->j = j;
    if (pseudo.length() > 0)
    {
        this->pseudo = pseudo;
    }
    else
    {
        this->pseudo = "Joueur1";
    }
}

void Player::playerAction()
{
}

void Player::poserBombe()
{
}

void Player::displayObject()
{
    if (bombPlaced)
    {
        std::cout << " P O ";
    }
    else
    {
        std::cout << "  P  ";
    }
}

// la fonction info player ça sert à rien il affiche juste toString on peut faire les deux dans une seul fonction !!
void Player::infoPlayer()
{
    std::cout << this->toString() << std::endl;
}

std::string Player::toString()
{
    return pseudo + " | " + std::to_string(heart) + " Heart | " + std::to_string(nbrBomb) + " Bomb | Position (" + std::to_string(j) + ";" + std::to_string(i) + ")";
}

int Player::getPlayerI()
{
    return i;
}

int Player::getPlayerJ()
{
    return j;
}

void Player::setPlayerI(int _i)
{
    this->i = _i;
}

void Player::setPlayerJ(int _j)
{
    this->j = _j;
}