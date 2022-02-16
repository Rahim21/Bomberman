#include "Affichage.h"
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void setcursor(bool visible, DWORD size) {
	if(size == 0)
		size = 20;	
	
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}
void instructions(){
	
	system("cls");
	std::cout<<"Instructions";
	std::cout<<"\n----------------";
	std::cout<<"\n bla bla bla bla bla ";
	std::cout<<"\n\n Press 'q' to move left";
	std::cout<<"\n Press 'd' to move right";
    std::cout<<"\n Press 's' to move down";
    std::cout<<"\n Press 'z' to move up";
    std::cout<<"\n Press 'x' to plant the bomb";
	std::cout<<"\n Press 'escape' to exit";
	std::cout<<"\n\nPress any key to go back to menu";
	getch();
}
void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void play(){
    //il faut faire une fonction play
}
void menu(){	 
	do{
		system("cls");
		gotoxy(10,5); std::cout<<" -------------------------- "; 
		gotoxy(10,6); std::cout<<" |       Bomberman        | "; 
		gotoxy(10,7); std::cout<<" --------------------------";
		gotoxy(10,9); std::cout<<"1. Start Game";
		gotoxy(10,10); std::cout<<"2. Instructions";	 
		gotoxy(10,11); std::cout<<"3. Quit";
		gotoxy(10,13); std::cout<<"Select option: ";
		char op = getche();
		
		if( op=='1') {
            play();
            }
		else if( op=='2'){
             instructions();
            }
		else if( op=='3'){
             exit(0);
            }
		
	}while(1);

}