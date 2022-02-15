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

void Player::afficherPlayer()
{
    std::cout << "P" << std::endl;
}

void Player::infoPlayer()
{
    std::cout << this->toString() << std::endl;
}

std::string Player::toString()
{
    return "Bomberman : " + pseudo + " | " + std::to_string(heart) + " Heart.";
}