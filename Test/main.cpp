#include <iostream>
#include <cstring>
#include "Configuration.h"
#include <conio.h>

int main()
{
    menu();
    exit(0);
}

/*
    MENU : <Jouer, Classement, Auteur, Quitter, Reglage touches?>
    TOUCHES : [^Zz:72-90-122, <Qq:75-81-113, vSs:80-83-115, >Dd:77-68-100] avec <conio.h>
    Possibilité de quitter à n'importe quel moment
    CLASSEMENT : <5 meilleurs scores, Pseudo, Niveau Atteint, Temps de jeu>
    Possibilité d'avoir du son sous STL + coloration en jeu ?
*/