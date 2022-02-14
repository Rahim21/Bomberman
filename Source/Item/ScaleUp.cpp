#include <iostream>
#include "ScaleUp.h" // linked with makefile

// Méthodes de notre classe ScaleUp [augmente la portée des bombes]
void addScale(Bomb b)
{
    b.portee+=1;
}