#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include<iostream>
#include<conio.h>
#include<dos.h> 
#include <windows.h>
#include <time.h>
void gotoxy(int x,int y);
void setcursor(bool visible, DWORD size);
void instructions();
void play();
void menu();
#endif