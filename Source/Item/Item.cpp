#include <iostream>
#include "Item.h" // linked with makefile

// Méthodes de notre classe Item [classe abstraite]
Item::Item() : Position(i, j) {}

void Item::displayObject()
{
    std::cout << "     ";
}