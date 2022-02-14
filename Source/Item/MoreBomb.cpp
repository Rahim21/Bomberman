#include <iostream>
#include "MoreBomb.h" // linked with makefile

// Méthodes de notre classe MoreBomb [augmente le nombre de bombes]
void addBomb(Player p)
{
    if (p.nbrBomb<3)
    {
        p.nbrBomb+=1;
    }
}