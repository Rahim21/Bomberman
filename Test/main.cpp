#include <iostream>
#include <cstring>
#include "affichage.h"
#include <conio.h>

int main()
{
    // menu();
    //  std::cout << "Saisir un pseudo pour votre Bomberman : \n";
    //  std::string name;
    //  std::cin >> name;
    //  Player p1 = Player{name};
    //  std::cout << p1.toString() << std::endl;
    //  Mob m1 = Mob();
    //  m1.afficherMob();
    //  Player p1{"Rahim"};
    //  MoreLife potion;
    //  p1.infoPlayer();
    //  potion.addLife(p1);
    //  p1.infoPlayer();
    Map m;
    m.createMap(m);
    std::cout << m;

    // char c;
    // int compteur{0};
    // while (compteur < 20)
    // {
    //     c = getch();
    //     if (c == 0)
    //     {
    //         switch (getch())
    //         {
    //         // FLECHE OU ZQSD OU zqsd
    //         case 72:
    //             std::cout << "Haut\n";
    //             break;
    //         case 80:
    //             std::cout << "Bas\n";
    //             break;
    //         case 75:
    //             std::cout << "Gauche\n";
    //             break;
    //         case 77:
    //             std::cout << "Droite\n";
    //             break;
    //         }
    //     }
    //     else
    //     {
    //         std::cout << "Autre ";
    //     }
    //     compteur++;
    // }
    exit(0);
}

/*
    MENU : <Jouer, Classement, Auteur, Quitter, Reglage touches?>
    TOUCHES : [^Zz:72-90-122, <Qq:75-81-113, vSs:80-83-115, >Dd:77-68-100] avec <conio.h>
    Possibilité de quitter à n'importe quel moment
    CLASSEMENT : <5 meilleurs scores, Pseudo, Niveau Atteint, Temps de jeu>
    Possibilité d'avoir du son sous STL + coloration en jeu ?
*/