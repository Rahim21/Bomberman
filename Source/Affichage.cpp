#include "Affichage.h"
#include "Map.h"
#include "Position.h"

#include <algorithm>

static bool multijoueur = false;
static int tour{0};
static int modulo;

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
	((multijoueur) ? tour % 2 : 0 == 0) ? gotoxy(38, 5) : gotoxy(38, 3);
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
	Map carte;
	carte.createMap(carte);
	int i=0;
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
		refreshGame(carte);
		char clavier = getche();
		// remplacer par les mouvements du Player [ZQSD et ^<v>]
		nextKeyPressed(clavier, carte);
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

void nextKeyPressed(const char &clavier, Map &carte)
{
	std::string keyList = "zZqQsSdD3";
	if (std::find(std::begin(keyList), std::end(keyList), clavier) != std::end(keyList))
	{
		if (verificationMouvement(clavier, carte))
		{
			tour += 1;
			// mouvement();
			/*
			dans mouvement : echange de place le joueur et la case où il souhaite aller
			carte[get...][get...] = ... echange de valeur
			static_cast<Player *>(positionObject[getPlayerI()][getPlayerJ()])->infoPlayer(); : echange d'objet
			récupérer les coordonnées actuelle du joueur pour ça
			*/
		}
		refreshGame(carte);
	}
	else if (clavier == '3')
	{
		system("cls");
		exit(0);
	}
}

void echanger(Map &carte,int *i2,int *j2){
	char tmp;
	int PlayerI=carte.joueur[(multijoueur) ? tour % 2 : 0]->getPlayerI();
	int PlayerJ=carte.joueur[(multijoueur) ? tour % 2 : 0]->getPlayerJ();
	tmp=carte.map[*i2][*j2];
	carte.map[*i2][*j2]=carte.map[PlayerI][PlayerJ];
	carte.map[PlayerI][PlayerJ]=tmp;

	// auto tmp1=carte.positionObject[*i2][*j2];
	// carte.positionObject[*i2][*j2]=carte.positionObject[PlayerI][PlayerJ];
	// carte.positionObject[*i2][*j2]=tmp1;
}

void verification_Obstacle( Map &carte,int i2,int j2){
	switch (carte.map[i2][j2])
	{
	case ' ':
	case ',':
	std::cout<<"testttttt";
	echanger(carte,&i2,&j2);
	break;
	/*
		Fonction Upgrade_Player : player prend l'item , l'ancienne case de player deviens grass 
	*/
	case 'L':
	//Upgrade_Player();
		break;
	case 'U':
	//Upgrade_Player();
		break;
	case '!':
	//Upgrade_Player();
		break;
	case 'Z':
	//Upgrade_Player();
		break;
	case '#':
	//Upgrade_Player();
		break;
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
		if (carte.joueur[(multijoueur) ? tour % 2 : 0]->getPlayerI() - 1 < 0)
		{
			return false;
		}else{
			verification_Obstacle( carte,carte.joueur[(multijoueur) ? tour % 2 : 0]->getPlayerI()-1,carte.joueur[(multijoueur) ? tour % 2 : 0]->getPlayerJ());
		}
		break;
	case 'Q':
	case 'q':
		if (carte.joueur[(multijoueur) ? tour % 2 : 0]->getPlayerJ() - 1 < 0)
		{
			return false;
		}else
		{
			verification_Obstacle( carte,carte.joueur[(multijoueur) ? tour % 2 : 0]->getPlayerI(),carte.joueur[(multijoueur) ? tour % 2 : 0]->getPlayerJ()-1);
		}
		
		break;
	case 'S':
	case 's':
		if (carte.joueur[(multijoueur) ? tour % 2 : 0]->getPlayerI() + 1 > carte.mapLigne)
		{
			return false;
		}else
		{
			verification_Obstacle( carte,carte.joueur[(multijoueur) ? tour % 2 : 0]->getPlayerI()+1,carte.joueur[(multijoueur) ? tour % 2 : 0]->getPlayerJ());
		}
		
		break;
	case 'D':
	case 'd':
		if (carte.joueur[(multijoueur) ? tour % 2 : 0]->getPlayerJ() + 1 > carte.mapColonne)
		{
			return false;
		}else
		{
			verification_Obstacle( carte,carte.joueur[(multijoueur) ? tour % 2 : 0]->getPlayerI(),carte.joueur[(multijoueur) ? tour % 2 : 0]->getPlayerJ()+1);
		}
		
		break;
	case '3':
		system("cls");
		std::cout << "Au revoir !" << std::endl;
		exit(0);
	default:
		return false;
	}
	return true;
}
