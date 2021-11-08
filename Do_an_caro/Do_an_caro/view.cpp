#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "control.h"
#include "view.h"
#include "caro.h"
using namespace std;
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void removeScrollbar() { //Ham tat cuon chuot
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}
void setSize() { //Ham cai dat kich thuoc man hinh console
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 115 * 10, 70 * 10, TRUE);
}
void DrawBoard(int pSize) {
	for (int i = 0; i <= pSize; i++) {
		for (int j = 0; j <= pSize; j++) {
			GotoXY(LEFT + 4 * i, TOP + 2 * j);
			cout << ".";
		}
	}
	TextColor(228);
	GotoXY(BOARD_SIZE * 7, 5); cout << "Player 1";
	TextColor(228);
	for (int i = 0; i <= BOARD_SIZE; i++) {
		GotoXY(BOARD_SIZE * 8.9, 5 +1 * i);
		cout << "|";
	}
	TextColor(228);
	GotoXY(BOARD_SIZE * 10, 5); cout << "Player 2";
	//for (int i = 60; i <= 60 + 38; i++) {
	//	GotoXY(i, 9); // ngang tren player 1 box
	//	printf_s("%c", 248);
	//	GotoXY(i, 14); // ngang duoi player 1 box
	//	printf_s("%c", 248);
	//}
	//for (int i = 9; i <= 14; i++) {
	//	GotoXY(59, i); // doc trai player 1 box
	//	printf_s("%c", 248);
	//	GotoXY(59 + 40, i); // doc phai player 1 box
	//	printf_s("%c", 248);
	//}
	//for (int i = 60; i <= 60 + 38; i++) {
	//	GotoXY(i, 16); // ngang tren player 2 box
	//	printf_s("%c", 248);
	//	GotoXY(i, 21); // ngang duoi player 2 box
	//	printf_s("%c", 248);
	//}
	//for (int i = 16; i <= 21; i++) {
	//	GotoXY(59, i); // doc trai player 2 box
	//	printf_s("%c", 248);
	//	GotoXY(59 + 40, i); // doc phai player 2 box
	//	printf_s("%c", 248);
	//}
	GotoXY(0, 2 * BOARD_SIZE + 6);
	TextColor(228);
	cout << "\t\t\t\t\t\tB -> Back to main menu";
	GotoXY(_A[0][0].x, _A[0][0].y);
	TextColor(240);
}
int ProcessFinish(int pWhoWin) {
	/*GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);*/
	switch (pWhoWin) {
	case -1:
		system("cls");
		Read("C:\\Users\\lemin\\Desktop\\Do_an_caro\\Do_an_caro\\P1Win.txt");
		break;
	case 1:
		system("cls");
		Read("C:\\Users\\lemin\\Desktop\\Do_an_caro\\Do_an_caro\\P2Win.txt");
		break;
	case 0:
		system("cls");
		Read("C:\\Users\\lemin\\Desktop\\Do_an_caro\\Do_an_caro\\Draw.txt");
		break;
	case 2:
		_TURN = !_TURN;
	}
	GotoXY(_X, _Y);
	return pWhoWin;
}
int AskContinue() {
	GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 4);
	printf("Nhan 'y/n' de tiep tuc/dung: ");
	return toupper(_getch());
}
void TextColor(int color) {
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}
