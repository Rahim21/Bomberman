#include <iostream>
#include "ScaleUp.h" // linked with makefile

// Méthodes de notre classe ScaleUp [augmente la portée des bombes]
void ScaleUp::addScale(Bomb &b)
{
    b.portee += 1;
}

std::ostream& operator<<(std::ostream& os,const ScaleUp& SC){
    os<<"SC"<<std::endl;
    return os;
}