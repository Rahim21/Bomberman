#include <iostream>
#include "Wall.h" // linked with makefile

// Méthodes de notre classe Wall
std::ostream& operator<<(std::ostream& os,const Wall& w){
    os<<"I"<<std::endl;
    return os;
}