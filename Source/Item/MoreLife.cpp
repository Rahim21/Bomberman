#include <iostream>
#include "MoreLife.h"
#include "Player.h" // linked with makefile

// Méthodes de notre classe MoreLife [augmente le nombre de points de vie de notre Bomberman] 
void MoreLife::addLife(Player p)
{   
    if (p.coeur <5)
    {
        p.coeur+=1;
    }
}