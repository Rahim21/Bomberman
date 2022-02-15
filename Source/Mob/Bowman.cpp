#include <iostream>
#include "Bowman.h" // linked with makefile

// Méthodes de notre classe Bowman
std::ostream& operator<<(std::ostream& os,const Bowman& b){
    os<<"B"<<std::endl;
    return os;
}