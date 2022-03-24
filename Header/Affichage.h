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
#include <cstring>

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
bool nextKeyPressed(const char &clavier, Map &carte);
bool verificationMouvement(const char &clavier, Map &carte);
bool verification_Obstacle(Map &carte, int i2, int j2);
void echanger(Map &carte, int *i2, int *j2);
void getdamaged(Map &carte, int *i2, int *j2);
/* ---------- MOB ---------- */
bool verificationMouvementMob(Map &carte);
bool verification_ObstacleMob(Map &carte, int i2, int j2);
void echangerMob(Map &carte, int *i2, int *j2);
void Mob_damaged_Player(Map &carte, int *i2, int *j2);
bool Bowman_detecting_Player(Map &carte);
void arrow_mouvment(Map &carte, int &i2, int &j2);
void throw_arrow(Map &carte);
void arrow_damaged_Player(Map &carte, int &i2, int &j2);
/* ---------- ITEM ---------- */
void upgradePlayer(Map carte, int *i2, int *j2);
/* ---------- BOMB ---------- */
bool bombExploded(Map &carte, int i, int j);
void bombExplodedAround(Map &carte, int i, int j);
#endif