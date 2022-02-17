#include "Affichage.h"
#include "Map.h"

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
	gotoxy(5, 2);
	std::cout << " -------------------------------- ";
	gotoxy(5, 3);
	std::cout << " |  Bomberman | HAYAT & MTARFI  | ";
	gotoxy(5, 4);
	std::cout << " --------------------------------";
	gotoxy(0, 8);
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
		char op = getche();

		if (op == '1')
		{
			system("cls");
			play();
		}
		else if (op == '2')
		{
			system("cls");
			instructions();
		}
		else if (op == '3')
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
	refreshGame(carte);
	do
	{
		char op = getche();
		// remplacer par les mouvements du Player [ZQSD et ^<v>]
		if (op == 'a')
		{
			carte.map[2][2] = 'P';
			refreshGame(carte);
		}
		else if (op == 'z')
		{
			carte.map[2][2] = 'W';
			refreshGame(carte);
		}
		else if (op == 'q')
		{
			system("cls");
			exit(0);
		}
	} while (1);
}

void afficheCommande()
{
	gotoxy(5, 35);
	std::cout << "Joueur 1 :" << std::endl;
	gotoxy(20, 34);
	std::cout << "Z" << std::endl;
	gotoxy(18, 35);
	std::cout << "Q" << std::endl;
	gotoxy(20, 35);
	std::cout << "S" << std::endl;
	gotoxy(22, 35);
	std::cout << "D" << std::endl;

	gotoxy(30, 35);
	std::cout << "Joueur 2 :" << std::endl;
	gotoxy(45, 34);
	std::cout << "^" << std::endl;
	gotoxy(43, 35);
	std::cout << "<" << std::endl;
	gotoxy(45, 36);
	std::cout << "v" << std::endl;
	gotoxy(47, 35);
	std::cout << ">" << std::endl;

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
}