#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "Map.h"
#include "Position.h"

#include <random>
#include <algorithm>
#include <iostream>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <time.h>

void gotoxy(int x, int y);
void setcursor(bool visible, DWORD size);
void instructions();
void titre();
void afficherTour(const Map &carte);
void menu();
void play();
void afficheCommande();
void refreshGame(Map &m);
void gameover();
void clearGame(Map &carte);
void endGame(Map &carte, int &i2, int &j2);
/* ---------- PLAYER ---------- */
void nextKeyPressed(const char &clavier, Map &carte);
bool verificationMouvement(const char &clavier, Map &carte);
bool verification_Obstacle(Map &carte, int i2, int j2);
void echanger(Map &carte, int *i2, int *j2);
void getdamaged(Map &carte, int *i2, int *j2);
/* ---------- MOB ---------- */
bool verificationMouvementMob(Map &carte);
bool verification_ObstacleMob(Map &carte, int i2, int j2);
void echangerMob(Map &carte, int *i2, int *j2);
void Mob_damaged_Player(Map &carte, int *i2, int *j2);
/* ---------- ITEM ---------- */
void upgradePlayer(Map carte, int *i2, int *j2);
#endif