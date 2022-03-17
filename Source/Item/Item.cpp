#include <iostream>
#include "Item.h" // linked with makefile

// Méthodes de notre classe Item [classe abstraite]
Item::Item(const int i, const int j, std::string symbole) : Position(i, j, symbole) {
        this->i = i;
    this->j = j;
    this->symbole = symbole;
}