#include <iostream>
#include "Grass.h" // linked with makefile

// Méthodes de notre classe Grass
std::ostream& operator<<(std::ostream& os,const Grass& g){
    os<<""<<std::endl;
    return os;
}