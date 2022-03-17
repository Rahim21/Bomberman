#include "Affichage.h"

static Map carte;

static bool multijoueur = false;
static int tour{0};
static int selectPlayer = (multijoueur) ? tour % 2 : 0;
static int getPlayerI;
static int getPlayerJ;
static int selectBomb{0};

static int selectMob;
static int getMobPosI;
static int getMobPosJ;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void setcursor(bool visible, DWORD size)
{
	if (size == 0)
		size = 20;

	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}
void instructions()
{
	std::cout << "Instructions";
	std::cout << "\n----------------";
	std::cout << "\n deplacement joueur 1 :";
	std::cout << "\n\n Appuyez sur 'q' : aller vers la gauche";
	std::cout << "\n Appuyez sur 'd' : aller vers la droite";
	std::cout << "\n Appuyez sur 's' : aller vers le bas";
	std::cout << "\n Appuyez sur 'z' : aller vers le haut";
	std::cout << "\n Appuyez sur 'x' : poser une bombe";
	std::cout << "\n Appuyez sur 'Echap' : Quitter";
	std::cout << "\n\nAppuyez sur n'importe quelle touche : Revenir au menu";
	getch();
}
void gotoxy(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void titre()
{
	gotoxy(4, 2);
	std::cout << "-------------------------------- ";
	gotoxy(4, 3);
	std::cout << "|  Bomberman | HAYAT & MTARFI  | ";
	gotoxy(4, 4);
	std::cout << "--------------------------------";
	gotoxy(0, 8);
}

void afficherTour(const Map &carte)
{
	(selectPlayer == 0) ? gotoxy(38, 3) : gotoxy(38, 5);
	std::cout << " Tour [" << tour + 1 << "] : ";
	gotoxy(50, 3);
	carte.joueur[0]->infoPlayer();
	if (multijoueur)
	{
		gotoxy(50, 5);
		carte.joueur[1]->infoPlayer();
	}
}

void menu()
{
	do
	{
		system("cls");
		titre();
		gotoxy(10, 9);
		std::cout << "1. Start Game";
		gotoxy(10, 10);
		std::cout << "2. Instructions";
		gotoxy(10, 11);
		std::cout << "3. Quit";
		gotoxy(10, 13);
		std::cout << "Selectionnez une option: ";
		char clavier = getche();

		if (clavier == '1')
		{
			system("cls");
			play();
		}
		else if (clavier == '2')
		{
			system("cls");
			instructions();
		}
		else if (clavier == '3')
		{
			system("cls");
			exit(0);
		}

	} while (1);
}

void play()
{
	carte.createMap(carte);

	if (carte.joueur.size() == 2)
	{
		multijoueur = true;
	}
	else if (carte.joueur.size() < 1 || carte.joueur.size() > 2)
	{
		std::cerr << "Votre map doit contenir plus ou moins 2 Joueurs Max !" << std::endl;
		exit(1);
	}

	do
	{
		getPlayerI = carte.joueur[selectPlayer]->getPlayerI();
		getPlayerJ = carte.joueur[selectPlayer]->getPlayerJ();
		refreshGame(carte);
		char clavier = getche();
		// remplacer par les mouvements du Player [ZQSD et ^<v>]
		nextKeyPressed(clavier, carte);
		// les mobs jouent après le tour des joueurs
		for (selectMob = 0; selectMob < (int)carte.mob.size(); selectMob += 1)
		{
			if (verificationMouvementMob(carte))
			{
				// std::cout << "Mob : Grrr !" << std::endl;
			}
		}
	} while (1);
}

void afficheCommande()
{
	gotoxy(5, 35);
	std::cout << R"(
                    Z                        ^
     Joueur 1 :   Q S D       Joueur 2 :   <   >            QUITTER : Tapez 3
                                             v
)";
	gotoxy(5, 6);
	std::cout << "Saisir Deplacement :" << std::endl;
	gotoxy(26, 6);
}

void refreshGame(Map &m)
{
	system("cls");
	titre();
	std::cout << m;
	afficheCommande();
	afficherTour(m);
}

/* ---------- PLAYER ---------- */

void nextKeyPressed(const char &clavier, Map &carte)
{
	std::string keyList = "zZqQsSdDxX"; // ajouter un charactere ou code ascci pour la barre d'espace : poser bombe (si char sinon dans un else if)
	if (std::find(std::begin(keyList), std::end(keyList), clavier) != std::end(keyList))
	{
		if (verificationMouvement(clavier, carte))
		{
			tour += 1;
			selectPlayer = (multijoueur) ? tour % 2 : 0;
			/*
			static_cast<Player *>(positionObject[getPlayerI()][getPlayerJ()])->infoPlayer();
			*/
		}
		refreshGame(carte);
	}
	else if (clavier == '3')
	{
		system("cls");
		std::cout << "Au revoir !" << std::endl;
		exit(0);
	}
}

void echanger(Map &carte, int *i2, int *j2, bool destroy)
{
	// Update du tableau d'objet de type Position
	auto tmp1 = carte.positionObject[*i2][*j2];
	carte.positionObject[*i2][*j2] = carte.positionObject[getPlayerI][getPlayerJ];
	carte.positionObject[getPlayerI][getPlayerJ] = tmp1;

	if (destroy)
	{
		carte.positionObject[getPlayerI][getPlayerJ] = new Grass(getPlayerI, getPlayerJ);
	}

	// Update du Tableau de player de type Player
	carte.joueur[selectPlayer]->setPlayerI(*i2);
	carte.joueur[selectPlayer]->setPlayerJ(*j2);
}

bool verification_Obstacle(Map &carte, int i2, int j2)
{
	auto key = carte.positionObject[i2][j2]->symbole;
	if (key == " ")
	{
		if ((carte.positionObject[getPlayerI][getPlayerJ])->symbole == "PO")
		{
			carte.joueur[selectPlayer]->bombPlaced = false;
			// carte.joueur[selectPlayer]->poserBombe(carte, getPlayerI, getPlayerJ, i2, j2); // poser la bombe à la case [getPlayerI][getPlayerJ] et deplacer le player à [i2][j2]

			// faire ceci dans la méthode poserBombe | error: 'Map' has not been declared
			carte.positionObject[i2][j2] = carte.positionObject[getPlayerI][getPlayerJ];
			carte.positionObject[getPlayerI][getPlayerJ] = new Bomb(getPlayerI, getPlayerJ);

			carte.joueur[selectPlayer]->setPlayerI(i2);
			carte.joueur[selectPlayer]->setPlayerJ(j2);
		}
		else
		{
			echanger(carte, &i2, &j2, false);
		}
		return true;
	}
	else if (key == "L" || key == "U" || key == "!" || key == "Z" || key == "#")
	{
		upgradePlayer(carte, &i2, &j2);
		echanger(carte, &i2, &j2, true);
		return true;
	}
	else if (key == "M" || key == "G" || key == "B")
	{
		getdamaged(carte, &i2, &j2);
		endGame(carte, getPlayerI, getPlayerJ);
		return true;
	}
	else
	{
		return false;
	}
}

// Créer un tableau de Joueur et Mob, pour récupérer les coordonnées et pouvoir les déplacer et structure pour i et j
// penser à faire les vérif autre ex: si mur etc...
bool verificationMouvement(const char &clavier, Map &carte)
{
	switch (clavier)
	{
	case 'Z':
	case 'z':
		if (carte.joueur[selectPlayer]->getPlayerI() - 1 < 0)
		{
			return false;
		}
		else
		{
			return verification_Obstacle(carte, carte.joueur[selectPlayer]->getPlayerI() - 1, carte.joueur[selectPlayer]->getPlayerJ());
		}
	case 'Q':
	case 'q':
		if (carte.joueur[selectPlayer]->getPlayerJ() - 1 < 0)
		{
			return false;
		}
		else
		{
			return verification_Obstacle(carte, carte.joueur[selectPlayer]->getPlayerI(), carte.joueur[selectPlayer]->getPlayerJ() - 1);
		}
	case 'S':
	case 's':
		if (carte.joueur[selectPlayer]->getPlayerI() + 1 > carte.mapLigne - 1)
		{
			return false;
		}
		else
		{
			return verification_Obstacle(carte, carte.joueur[selectPlayer]->getPlayerI() + 1, carte.joueur[selectPlayer]->getPlayerJ());
		}
	case 'D':
	case 'd':
		if (carte.joueur[selectPlayer]->getPlayerJ() + 1 > carte.mapColonne - 1)
		{
			return false;
		}
		else
		{
			return verification_Obstacle(carte, carte.joueur[selectPlayer]->getPlayerI(), carte.joueur[selectPlayer]->getPlayerJ() + 1);
		}
	case 'X':
	case 'x':
		// placer bombe
		carte.joueur[selectPlayer]->bombPlaced = true;
		return true;
	default:
		return false;
	}
}

/* ---------- MOB ---------- */

bool verificationMouvementMob(Map &carte)
{
	/*
	0 : haut
	1 : gauche
	2 : bas
	3 : droite
	*/
	// on appelle la fonction Alea_sens qui génere des nombre alearatoirement entre 0 et 3 ce qui donne le mouvement alératoire des mobs
	switch (carte.mob[selectMob]->Alea_sens())
	{
	case 0:
		if (carte.mob[selectMob]->getMobI() - 1 < 0)
		{
			return false;
		}
		else
		{
			return verification_ObstacleMob(carte, carte.mob[selectMob]->getMobI() - 1, carte.mob[selectMob]->getMobJ());
		}
		break;
	case 1:
		if (carte.mob[selectMob]->getMobJ() - 1 < 0)
		{
			return false;
		}
		else
		{
			return verification_ObstacleMob(carte, carte.mob[selectMob]->getMobI(), carte.mob[selectMob]->getMobJ() - 1);
		}
		break;
	case 2:
		if (carte.mob[selectMob]->getMobI() + 1 > carte.mapLigne - 1)
		{
			return false;
		}
		else
		{
			return verification_ObstacleMob(carte, carte.mob[selectMob]->getMobI() + 1, carte.mob[selectMob]->getMobJ());
		}
		break;
	case 3:
		if (carte.mob[selectMob]->getMobJ() + 1 > carte.mapColonne - 1)
		{
			return false;
		}
		else
		{
			return verification_ObstacleMob(carte, carte.mob[selectMob]->getMobI(), carte.mob[selectMob]->getMobJ() + 1);
		}
		break;
	default:
		return false;
	}

	return true;
}

bool verification_ObstacleMob(Map &carte, int i2, int j2)
{
	if (carte.positionObject[i2][j2]->symbole == " ")
	{
		echangerMob(carte, &i2, &j2);
		return true;
	}
	else if (carte.positionObject[i2][j2]->symbole == "P")
	{
		Mob_damaged_Player(carte, &i2, &j2);
		endGame(carte, i2, j2);
	}

	return false;
}

void echangerMob(Map &carte, int *i2, int *j2)
{
	getMobPosI = carte.mob[selectMob]->getMobI();
	getMobPosJ = carte.mob[selectMob]->getMobJ();
	// Update tableau d'affichage de type char
	char tmp;
	tmp = carte.map[*i2][*j2];
	carte.map[*i2][*j2] = carte.map[getMobPosI][getMobPosJ];
	carte.map[getMobPosI][getMobPosJ] = tmp;

	// Update du tableau d'objet de type Position
	auto tmp1 = carte.positionObject[*i2][*j2];
	carte.positionObject[*i2][*j2] = carte.positionObject[getMobPosI][getMobPosJ];
	carte.positionObject[getMobPosI][getMobPosJ] = tmp1;

	// Update du Tableau de mob de type mob
	carte.mob[selectMob]->setMobI(*i2);
	carte.mob[selectMob]->setMobJ(*j2);
}

void upgradePlayer(Map carte, int *i2, int *j2)
{
	if (dynamic_cast<MoreLife *>(carte.positionObject[*i2][*j2]) != nullptr)
	{
		static_cast<MoreLife *>(carte.positionObject[*i2][*j2])->addLife(*carte.joueur[selectPlayer]);
	}
	else if (dynamic_cast<MoreBomb *>(carte.positionObject[*i2][*j2]) != nullptr)
	{
		static_cast<MoreBomb *>(carte.positionObject[*i2][*j2])->addBomb(*carte.joueur[selectPlayer]);
	}
	else if (dynamic_cast<PowerUp *>(carte.positionObject[*i2][*j2]) != nullptr)
	{
		// ajouter la puissance à la bombe du player
		// static_cast<PowerUp *>(carte.positionObject[*i2][*j2])->addPower(carte.joueur[selectPlayer]->playerBomb[selectBomb]); // si initialisation de playerBomb non dynamic
		static_cast<PowerUp *>(carte.positionObject[*i2][*j2])->addPower(*carte.joueur[selectPlayer]->playerBomb[selectBomb]);
	}
	else if (dynamic_cast<ScaleUp *>(carte.positionObject[*i2][*j2]) != nullptr)
	{
		// ajouter l'effet à la bombe du player
		// static_cast<ScaleUp *>(carte.positionObject[*i2][*j2])->addScale(carte.joueur[selectPlayer]->playerBomb[selectBomb]); // si initialisation de playerBomb non dynamic
		static_cast<ScaleUp *>(carte.positionObject[*i2][*j2])->addScale(*carte.joueur[selectPlayer]->playerBomb[selectBomb]);
	}
	else if (dynamic_cast<SpeedUp *>(carte.positionObject[*i2][*j2]) != nullptr)
	{
		static_cast<SpeedUp *>(carte.positionObject[*i2][*j2])->addSpeed(*carte.joueur[selectPlayer]);
	}
	else
	{
		std::cout << "Erreur Item !" << std::endl;
	}
}

void Mob_damaged_Player(Map &carte, int *i2, int *j2)
{
	if (dynamic_cast<Player *>(carte.positionObject[*i2][*j2]) != nullptr)
	{
		static_cast<Mob *>(carte.mob[selectMob])->damager(*static_cast<Player *>(carte.positionObject[*i2][*j2]));
	}
}

void getdamaged(Map &carte, int *i2, int *j2)
{
	if (dynamic_cast<Mob *>(carte.positionObject[*i2][*j2]) != nullptr)
	{
		static_cast<Mob *>(carte.positionObject[*i2][*j2])->damager(*carte.joueur[selectPlayer]);
	}
}
void gameover()
{
	system("cls");
	std::cout << std::endl;
	std::cout << "\t\t--------------------------" << std::endl;
	std::cout << "\t\t-------- Game Over -------" << std::endl;
	std::cout << "\t\t--------------------------" << std::endl
			  << std::endl;
	std::cout << "\t\tPress any key to go back to menu.";
	getch();
}
void clearGame(Map &carte)
{
	tour = 0;
	carte.joueur.clear();
	carte.mob.clear();
	gameover();
	menu();
}
void endGame(Map &carte, int &i2, int &j2)
{
	if (dynamic_cast<Player *>(carte.positionObject[i2][j2])->heart <= 0)
	{
		carte.positionObject[i2][j2] = new Grass(i2, j2);
		carte.map[i2][j2] = ' ';
		carte.joueur[selectPlayer] = nullptr;
		if (multijoueur)
		{
			if (carte.joueur[0] == nullptr && carte.joueur[1] == nullptr)
			{
				clearGame(carte);
			}
		}
		else if (carte.joueur[0] == nullptr)
		{
			clearGame(carte);
		}
	}
}