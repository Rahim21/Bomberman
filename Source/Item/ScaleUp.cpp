#include <iostream>
#include "ScaleUp.h" // linked with makefile

// Méthodes de notre classe ScaleUp [augmente la portée des bombes]
void ScaleUp::addScale(Bomb &b)
{
    b.portee += 1;
}

void ScaleUp::afficherItem()
{
    std::cout << "SC" << std::endl;
}