#include <iostream>
#include "Player.h" // linked with makefile

// Méthodes de notre classe Player
Player::Player(std::string pseudo)
{
    this->pseudo = pseudo;
}

void deplacement()
{
}

void poserBombe()
{
}

void afficherPlayer()
{
}

std::string Player::toString()
{
    return "Votre pseudo est : " + pseudo;
}