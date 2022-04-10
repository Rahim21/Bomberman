#include <iostream>
#include "Player.h" // linked with makefile
#include <windows.h>
#include <sstream>

// Méthodes de notre classe Player
Player::Player(int i, int j, std::string pseudo, std::string symbole) : Position{i, j, symbole}
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
    this->symbole = symbole;
}

void Player::displayObject()
{
    if (bombPlaced)
    {
        symbole = "PO";
        std::cout << " P O ";
    }
    else
    {
        symbole = "P";
        std::cout << "  " + symbole + "  ";
    }
}

void Player::receiveBombDamage(int degat)
{
    heart -= degat;
    if (heart <= 0)
    {
        destroyed = true;
    }
}

// la fonction info player ça sert à rien il affiche juste toString on peut faire les deux dans une seul fonction !!
void Player::infoPlayer()
{
    std::cout << this->toString() << std::endl;
}

std::string Player::toString()
{
    std::string StringHeart;
    std::stringstream tmp;
    for (int nbrHeart = 0; nbrHeart < heart; nbrHeart++)
    {
        StringHeart = char(3);
        tmp << StringHeart + " ";
    }
    StringHeart = tmp.str();
    return pseudo + " | " + StringHeart + " Heart | " + std::to_string(nbrBomb) + " Bomb | Position (" + std::to_string(j) + ";" + std::to_string(i) + ")";
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