#include <iostream>
#include "Player.h" // linked with makefile

// Méthodes de notre classe Player
Player::Player(int i, int j, std::string pseudo) : Position{i, j}
{
    this->i = i;
    this->j = j;
    this->pseudo = pseudo;
}

void playerAction()
{
}

void Player::deplacement(const char &keyPressed)
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
    return "Bomberman : " + pseudo + " | " + std::to_string(heart) + " Heart.\n (" + std::to_string(i) + ";" + std::to_string(j) + ")";
}