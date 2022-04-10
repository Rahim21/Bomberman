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

/**
 * @brief place elements with coordinates
 *
 * @param x
 * @param y
 */
void gotoxy(int x, int y);

/**
 * @brief set the cursor
 *
 * @param visible
 * @param size
 */
void setcursor(bool visible, DWORD size);

/**
 * @brief display the instruction, the player's movement keys
 *
 */
void instructions();

/**
 * @brief display the title in-game
 *
 */
void titre();

/**
 * @brief display the title in the menu
 *
 */
void titreMenu();

/**
 * @brief cursor in the menu for selecting an option
 *
 * @param choixOption
 */
void optionMenu(int &choixOption);

/**
 * @brief display player turn
 *
 * @param carte
 */
void afficherTour(const Map &carte);

/**
 * @brief display the menu with these options
 *
 */
void menu();

/**
 * @brief start the game
 *
 */
void play();

/**
 * @brief display the command
 *
 */
void afficheCommande();

/**
 * @brief refresh the map
 *
 * @param m
 */
void refreshGame(Map &m);

/**
 * @brief diplay the game over
 *
 * @param carte
 */
void gameover(Map &carte);

/**
 * @brief clear the game
 *
 * @param carte
 */
void clearGame(Map &carte);

/**
 * @brief verify if is the end of the game, death of the player
 *
 * @param carte
 * @param i2
 * @param j2
 */
void endGame(Map &carte, int &i2, int &j2);

/**
 * @brief display the win level
 *
 */
void win_level();

/**
 * @brief cler map and load the next level
 *
 * @param carte
 */
void next_level(Map &carte);
/* ---------- PLAYER ---------- */
/**
 * @brief key pressed by the user's keyboard input
 *
 * @param clavier
 * @param carte
 * @return true
 * @return false
 */
bool nextKeyPressed(const char &clavier, Map &carte);

/**
 * @brief checks if the movement of the player is valid and not out of the map
 *
 * @param clavier
 * @param carte
 * @return true
 * @return false
 */
bool verificationMouvement(const char &clavier, Map &carte);

/**
 * @brief verify if there any obstacle before moving the player
 *
 * @param carte
 * @param i2
 * @param j2
 * @return true
 * @return false
 */
bool verification_Obstacle(Map &carte, int i2, int j2);

/**
 * @brief moves the player if the next square is empty
 *
 * @param carte
 * @param i2
 * @param j2
 */
void echanger(Map &carte, int *i2, int *j2);

/**
 * @brief
 *
 * @param carte player get damaged by the mob
 * @param i2
 * @param j2
 */
void getdamaged(Map &carte, int *i2, int *j2);
/* ---------- MOB ---------- */
/**
 * @brief  checks if the movement of the mob is valid and not out of the map
 *
 * @param carte
 * @return true
 * @return false
 */
bool verificationMouvementMob(Map &carte);

/**
 * @brief verify if there any obstacle before moving the mob
 *
 * @param carte
 * @param i2
 * @param j2
 * @return true
 * @return false
 */
bool verification_ObstacleMob(Map &carte, int i2, int j2);

/**
 * @brief moves the mob if the next square is empty
 *
 * @param carte
 * @param i2
 * @param j2
 */
void echangerMob(Map &carte, int *i2, int *j2);

/**
 * @brief the mob damage the player
 *
 * @param carte
 * @param i2
 * @param j2
 */
void Mob_damaged_Player(Map &carte, int *i2, int *j2);

/**
 * @brief bowman detecting the player
 *
 * @param carte
 * @return true
 * @return false
 */
bool Bowman_detecting_Player(Map &carte);

/**
 * @brief the arrow movment
 *
 * @param carte
 * @param i2
 * @param j2
 * @param sens
 */
void arrow_mouvment(Map &carte, int &i2, int &j2, std::string sens);

/**
 * @brief bowman throw the arrow
 *
 * @param carte
 */
void throw_arrow(Map &carte);

/**
 * @brief arrow damage the player
 *
 * @param carte
 * @param i2
 * @param j2
 */
void arrow_damaged_Player(Map &carte, int &i2, int &j2);
/* ---------- ITEM ---------- */

/**
 * @brief adds the effect of the item retrieved to the player
 *
 * @param carte
 * @param i2
 * @param j2
 */
void upgradePlayer(Map carte, int *i2, int *j2);
/* ---------- BOMB ---------- */

/**
 * @brief the bomb explosion
 *
 * @param carte
 * @param i
 * @param j
 * @return true
 * @return false
 */
bool bombExploded(Map &carte, int i, int j);

/**
 * @brief explodes every square around the bomb
 *
 * @param carte
 * @param i
 * @param j
 * @return true
 * @return false
 */
bool bombExplodedAround(Map &carte, int i, int j);
#endif