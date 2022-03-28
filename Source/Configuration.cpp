#include "Configuration.h"
#include <chrono>
#include <thread>

Map carte;

static bool multijoueur = false;
static int tour{0};
static int selectPlayer = (multijoueur) ? tour % 2 : 0;
static int getPlayerI;
static int getPlayerJ;

static int nextBomb{0};
static int selectBomb = nextBomb % 3;
static int getBombI;
static int getBombJ;

static int selectMob;
static int getMobPosI;
static int getMobPosJ;

static int getArrowPosI;
static int getArrowPosJ;
std::string arrow_down(1, char(281));
std::string arrow_left(1, char(17));
std::string arrow_right(1, char(282));
std::string arrow_up(1, char(280));

static int porteeMax = 1;
static int degatBomb = 1;

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
	std::cout << R"(
	Instructions BOMBERMAN :

	---------- Deplacement JOUEUR ----------
	Appuyez sur 'Z' : aller vers le haut
	Appuyez sur 'Q' : aller vers la gauche
	Appuyez sur 'S' : aller vers le bas
	Appuyez sur 'D' : aller vers la droite
	Appuyez sur 'X' : poser une bombe
	Appuyez sur '3' en pleine partie : Quitter
		
	Appuyez sur n'importe quelle touche : Revenir au menu
	)";
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
	std::cout << R"(
  --------------------------------
  |  Bomberman | HAYAT & MTARFI  |
  --------------------------------
	)";
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
	porteeMax = 1;
	degatBomb = 1;
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
		// remplacer par les mouvements du Player [ZQSD et ^<v>]
		for (int speedPlayer = 0; speedPlayer < carte.joueur[selectPlayer]->speed; speedPlayer++)
		{
			getPlayerI = carte.joueur[selectPlayer]->getPlayerI();
			getPlayerJ = carte.joueur[selectPlayer]->getPlayerJ();

			// Si au bout de 2 essaies le joueur ne saisie pas la bonne touche : il passe son tour
			bool turnPlayer = false;
			int countTurn = 0;
			do
			{
				char clavier = getche();
				turnPlayer = nextKeyPressed(clavier, carte);
				countTurn += 1;
			} while (turnPlayer != true && countTurn < 2);
			refreshGame(carte);
		}

		// Nouveau tour
		tour += 1;
		selectPlayer = (multijoueur) ? tour % 2 : 0;

		// redéfinition de la position exacte du Player après s'être déplacé !
		getPlayerI = carte.joueur[selectPlayer]->getPlayerI();
		getPlayerJ = carte.joueur[selectPlayer]->getPlayerJ();
		// les mobs jouent après le tour des joueurs

		if (!carte.arrow.empty())
		{

			getArrowPosI = carte.arrow[0]->getArrowI();
			getArrowPosJ = carte.arrow[0]->getArrowJ();
			std::string sens = carte.arrow[0]->symbole;
			arrow_mouvment(carte, getArrowPosI, getArrowPosJ, sens);
		}
		gotoxy(5, 44);
			std::cout<<"Nbr Mob:"<<carte.mob.size();
		for (selectMob = 0; selectMob < (int)carte.mob.size(); selectMob += 1)
		{	
			if (carte.mob[selectMob]->symbole == "B")
			{
				if (Bowman_detecting_Player(carte) && carte.arrow.size() == 0)
				{
					throw_arrow(carte);
				}
			}
			verificationMouvementMob(carte);
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
	afficherTour(m);
	afficheCommande();
}

/* ---------- PLAYER ---------- */

bool nextKeyPressed(const char &clavier, Map &carte)
{
	bool explosionDetected = false;
	std::string keyList = "zZqQsSdDxX"; // ajouter un charactere ou code ascci pour la barre d'espace : poser bombe (si char sinon dans un else if)
	if (std::find(std::begin(keyList), std::end(keyList), clavier) != std::end(keyList))
	{
		if (verificationMouvement(clavier, carte))
		{

			getPlayerI = carte.joueur[selectPlayer]->getPlayerI();
			getPlayerJ = carte.joueur[selectPlayer]->getPlayerJ();

			for (int i = 0; i < carte.joueur[selectPlayer]->nbrBomb; i++)
			{
				if (carte.joueur[selectPlayer]->playerBomb[i] != nullptr)
				{
					if (carte.joueur[selectPlayer]->playerBomb[i]->symbole == "@")
					{
						getBombI = carte.joueur[selectPlayer]->playerBomb[i]->i;
						getBombJ = carte.joueur[selectPlayer]->playerBomb[i]->j;
						if (bombExploded(carte, getBombI, getBombJ))
						{
							carte.joueur[selectPlayer]->playerBomb[i] = nullptr;
							carte.positionObject[getBombI][getBombJ] = new Grass(getBombI, getBombJ);
							explosionDetected = true;
						}
					}
				}
			}

			/*
			static_cast<Player *>(positionObject[getPlayerI()][getPlayerJ()])->infoPlayer();
			*/
		}
		if (explosionDetected)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			explosionDetected = false;
			endGame(carte, getPlayerI, getPlayerJ);
			carte.detectDestroyedObject();
		}
		refreshGame(carte);
		return true;
	}
	else if (clavier == '3')
	{
		system("cls");
		std::cout << "Au revoir !" << std::endl;
		exit(0);
	}
	return false;
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
			carte.joueur[selectPlayer]->playerBomb[selectBomb] = new Bomb(getPlayerI, getPlayerJ);
			carte.joueur[selectPlayer]->playerBomb[selectBomb]->activation = true;
			carte.positionObject[getPlayerI][getPlayerJ] = carte.joueur[selectPlayer]->playerBomb[selectBomb];
			carte.joueur[selectPlayer]->setPlayerI(i2);
			carte.joueur[selectPlayer]->setPlayerJ(j2);
			nextBomb += 1;
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
	}else if (key=="X")
	{
		if(carte.mob.size()==0){
			next_level(carte);
			return true;
		}
		return false;
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
	getMobPosI = carte.mob[selectMob]->getMobI();
	getMobPosJ = carte.mob[selectMob]->getMobJ();
	switch (carte.mob[selectMob]->followPlayer(getPlayerI, getPlayerJ, getMobPosI, getMobPosJ))
	{
	// haut
	case 0:
		if (getMobPosI - 1 < 0)
		{
			return false;
		}
		else
		{
			return verification_ObstacleMob(carte, getMobPosI - 1, getMobPosJ);
		}
		break;
	// gauche
	case 1:
		if (carte.mob[selectMob]->getMobJ() - 1 < 0)
		{
			return false;
		}
		else
		{
			return verification_ObstacleMob(carte, getMobPosI, getMobPosJ - 1);
		}
		break;
	// bas
	case 2:
		if (carte.mob[selectMob]->getMobI() + 1 > carte.mapLigne - 1)
		{
			return false;
		}
		else
		{
			return verification_ObstacleMob(carte, getMobPosI + 1, getMobPosJ);
		}
		break;
	// droite
	case 3:
		if (carte.mob[selectMob]->getMobJ() + 1 > carte.mapColonne - 1)
		{
			return false;
		}
		else
		{
			return verification_ObstacleMob(carte, getMobPosI, getMobPosJ + 1);
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
		
		// static_cast<PowerUp *>(carte.positionObject[*i2][*j2])->addPower(*carte.joueur[selectPlayer]->playerBomb[selectBomb]);
		degatBomb += 1;
	}
	else if (dynamic_cast<ScaleUp *>(carte.positionObject[*i2][*j2]) != nullptr)
	{
		// ajouter l'effet à la bombe du player
		// static_cast<ScaleUp *>(carte.positionObject[*i2][*j2])->addScale(carte.joueur[selectPlayer]->playerBomb[selectBomb]); // si initialisation de playerBomb non dynamic
		for (int allBomb = 0; allBomb < 3; allBomb++)
		{
			if (carte.joueur[selectPlayer]->playerBomb[allBomb] != nullptr)
			{
				static_cast<ScaleUp *>(carte.positionObject[*i2][*j2])->addScale(*carte.joueur[selectPlayer]->playerBomb[allBomb]);
			}
		}
		porteeMax += 1;
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

void arrow_damaged_Player(Map &carte, int &i2, int &j2)
{
	if (dynamic_cast<Player *>(carte.positionObject[i2][j2]) != nullptr)
	{
		carte.arrow[0]->damager(*static_cast<Player *>(carte.positionObject[i2][j2]));
	}
}

void getdamaged(Map &carte, int *i2, int *j2)
{
	if (dynamic_cast<Mob *>(carte.positionObject[*i2][*j2]) != nullptr)
	{
		static_cast<Mob *>(carte.positionObject[*i2][*j2])->damager(*carte.joueur[selectPlayer]);
	}
}
/*-----------------------------------------------------BOWMAN---------------------------------------------------------------*/
void arrow_mouvment(Map &carte, int &i, int &j, std::string sens)
{
	int nextI, nextJ;
	if (sens == arrow_down)
	{
		nextI = i + 1;
		nextJ = j;
	}
	else if (sens == arrow_up)
	{
		nextI = i - 1;
		nextJ = j;
	}
	else if (sens == arrow_left)
	{
		nextI = i;
		nextJ = j - 1;
	}
	else if (sens == arrow_right)
	{
		nextI = i;
		nextJ = j + 1;
	}

	if (nextI >= 0 && nextI < carte.mapLigne && nextJ >= 0 && nextJ < carte.mapColonne)
	{
		if (carte.positionObject[nextI][nextJ]->symbole == " ")
		{
			carte.positionObject[nextI][nextJ] = carte.arrow[0];
			carte.positionObject[i][j] = new Grass(i, j);

			carte.arrow[0]->setArrowI(nextI);
			carte.arrow[0]->setArrowJ(nextJ);
		}
		else if (carte.positionObject[nextI][nextJ]->symbole == "P" || carte.positionObject[nextI][nextJ]->symbole == "PO")
		{
			arrow_damaged_Player(carte, nextI, nextJ);
			carte.positionObject[i][j] = new Grass(i, j);
			carte.arrow.erase(carte.arrow.begin());
			endGame(carte, nextI, nextJ);
		}
		else
		{
			carte.positionObject[i][j] = new Grass(i, j);
			carte.arrow.erase(carte.arrow.begin());
		}
	}
	else
	{
		carte.positionObject[i][j] = new Grass(i, j);
		carte.arrow.erase(carte.arrow.begin());
	}
}

void throw_arrow(Map &carte)
{
	int BowmanI = carte.mob[selectMob]->getMobI();
	int BowmanJ = carte.mob[selectMob]->getMobJ();
	int PlayerI = carte.joueur[selectPlayer]->getPlayerI();
	int PlayerJ = carte.joueur[selectPlayer]->getPlayerJ();

	if (BowmanI == PlayerI)
	{
		if (BowmanJ < PlayerJ && carte.positionObject[BowmanI][BowmanJ + 1]->symbole == " ")
		{
			if (carte.arrow.empty())
			{
				carte.positionObject[BowmanI][BowmanJ + 1] = new Arrow(BowmanI, BowmanJ + 1, arrow_right);
				carte.arrow.push_back(static_cast<Arrow *>(carte.positionObject[BowmanI][BowmanJ + 1]));
			}
		}
		else if (BowmanJ > PlayerJ && carte.positionObject[BowmanI][BowmanJ - 1]->symbole == " ")
		{
			if (carte.arrow.empty())
			{
				carte.positionObject[BowmanI][BowmanJ - 1] = new Arrow(BowmanI, BowmanJ - 1, arrow_left);
				carte.arrow.push_back(static_cast<Arrow *>(carte.positionObject[BowmanI][BowmanJ - 1]));
			}
		}
	}
	else if (BowmanJ == PlayerJ)
	{
		if (BowmanI < PlayerI && carte.positionObject[BowmanI + 1][BowmanJ]->symbole == " ")
		{
			if (carte.arrow.empty())
			{
				carte.positionObject[BowmanI + 1][BowmanJ] = new Arrow(BowmanI + 1, BowmanJ, arrow_down);
				carte.arrow.push_back(static_cast<Arrow *>(carte.positionObject[BowmanI + 1][BowmanJ]));
			}
		}
		else if (BowmanI > PlayerI && carte.positionObject[BowmanI - 1][BowmanJ]->symbole == " ")
		{
			if (carte.arrow.empty())
			{
				carte.positionObject[BowmanI - 1][BowmanJ] = new Arrow(BowmanI - 1, BowmanJ, arrow_up);
				carte.arrow.push_back(static_cast<Arrow *>(carte.positionObject[BowmanI - 1][BowmanJ]));
			}
		}
	}
}
bool Bowman_detecting_Player(Map &carte)
{
	int BowmanI = carte.mob[selectMob]->getMobI();
	int BowmanJ = carte.mob[selectMob]->getMobJ();
	int PlayerI = carte.joueur[selectPlayer]->getPlayerI();
	int PlayerJ = carte.joueur[selectPlayer]->getPlayerJ();
	if (BowmanI == PlayerI)
	{
		if (BowmanJ < PlayerJ)
		{
			for (int j = BowmanJ + 1; j < PlayerJ; j++)
			{
				if (carte.positionObject[BowmanI][j]->symbole != " ")
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			for (int j = PlayerJ + 1; j < BowmanJ; j++)
			{
				if (carte.positionObject[BowmanI][j]->symbole != " ")
				{
					return false;
				}
				return true;
			}
		}
	}
	else if (BowmanJ == PlayerJ)
	{
		if (BowmanI < PlayerI)
		{
			for (int i = BowmanI + 1; i < PlayerI; i++)
			{
				if (carte.positionObject[i][BowmanJ]->symbole != " ")
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			for (int i = PlayerI + 1; i < BowmanI; i++)
			{
				if (carte.positionObject[i][BowmanJ]->symbole != " ")
				{
					return false;
				}
			}
			return true;
		}
	}
	return false;
}

void gameover()
{
	system("cls");
	std::cout << std::endl;
	std::cout << R"(
	--------------------------
	-------- Game Over -------
	--------------------------

	Appuyez sur n'importe quelle touche pour revenir au menu.
	)" << std::endl;
	getch();
}

void win_level()
{
		system("cls");
	std::cout << std::endl;
	std::cout << R"(
	--------------------------
	----- Level completed ----
	--------------------------

	Click any key to pass to next level 
	)"<< std::endl;
	getch();
}
void next_level(Map &carte){
	win_level();
	tour = 0;
	carte.joueur.clear();
	carte.mob.clear();
	//passer au niveau suivant
	menu();
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

bool bombExploded(Map &carte, int i, int j)
{
	// int porteeMax = carte.joueur[selectPlayer]->playerBomb[selectBomb]->portee;
	//   Vérifier la sortie de map i et j
	for (int portee = 1; portee <= porteeMax; portee++)
	{
		if (i - portee >= 0)
		{
			if (bombExplodedAround(carte, i - portee, j) == false)
			{
				break;
			} // haut
		}
	}
	for (int portee = 1; portee <= porteeMax; portee++)
	{
		if (i + portee < carte.mapLigne)
		{
			if (bombExplodedAround(carte, i + portee, j) == false)
			{
				break;
			} // bas
		}
	}
	for (int portee = 1; portee <= porteeMax; portee++)
	{
		if (j - portee >= 0)
		{
			if (bombExplodedAround(carte, i, j - portee) == false)
			{
				break;
			} // gauche
		}
	}
	for (int portee = 1; portee <= porteeMax; portee++)
	{
		if (j + portee < carte.mapColonne)
		{
			if (bombExplodedAround(carte, i, j + portee) == false)
			{
				break;
			} // droite
		}
	}
	return true;
}

bool bombExplodedAround(Map &carte, int i, int j)
{
	// la portee de l'explosion s'arrête lorsque la case est un mur I
	std::string key = carte.positionObject[i][j]->symbole;
	if (key == "I")
	{
		return false;
	}
	carte.positionObject[i][j]->exploded = true;
	static_cast<Bomb *>(carte.positionObject[getBombI][getBombJ])->infligerDegat(*carte.positionObject[i][j], degatBomb);
	return true;
}