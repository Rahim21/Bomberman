#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <iostream>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <time.h>
#include "Map.h"

void gotoxy(int x, int y);
void setcursor(bool visible, DWORD size);
void instructions();
void titre();
void afficherTour(const Map &carte);
void menu();
void play();
void afficheCommande();
void refreshGame(Map &m);
void nextKeyPressed(const char &clavier, Map &carte);
bool verificationMouvement(const char &clavier, Map &carte);
void echanger(Map &carte,int *i2,int *j2);

#endif