#include <iostream>
#include "Player.h" // linked with makefile

// Méthodes de notre classe Player
Player::Player(std::string pseudo)
{
    this->pseudo = pseudo;
}

void Player::deplacement()
{
}

void Player::poserBombe()
{
}

std::ostream &operator<<(std::ostream &os, const Player &p)
{
    os << "P" << std::endl;
    return os;
}
// la fonction info player ça sert à rien il affiche juste toString on peut faire les deux dans une seul fonction !!
void Player::infoPlayer()
{
    std::cout << this->toString() << std::endl;
}

std::string Player::toString()
{
    return "Bomberman : " + pseudo + " | " + std::to_string(heart) + " Heart.";
}