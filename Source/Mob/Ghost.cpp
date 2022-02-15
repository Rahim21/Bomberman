#include <iostream>
#include "Ghost.h" // linked with makefile

// Méthodes de notre classe Ghost
std::ostream& operator<<(std::ostream& os,const Ghost& g){
    os<<"G"<<std::endl;
    return os;
}