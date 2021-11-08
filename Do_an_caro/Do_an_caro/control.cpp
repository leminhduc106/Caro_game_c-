#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include "control.h"
#include "model.h"
#include "view.h"
#include "caro.h"
#pragma warning(disable : 4996)
using namespace std;
void StartGame() {
	system("cls");
	ResetData();
	DrawBoard(BOARD_SIZE);
}
void ExitGame() {
	system("cls");
}
void MoveRight() {
	if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x) {
		_X += 4;
		GotoXY(_X, _Y);
	}
	else if (_X == _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x) {
		_X = _A[0][0].x;
		GotoXY(_X, _Y);
	}
}
void MoveLeft() {
	if (_X > _A[0][0].x) {
		_X -= 4;
		GotoXY(_X, _Y);
	}
	else if (_X == _A[0][0].x) {
		_X = _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x;
		GotoXY(_X, _Y);
	}
}
void MoveDown() {
	if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y) {
		_Y += 2;
		GotoXY(_X, _Y);
	}
	else if (_Y == _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y) {
		_Y = _A[0][0].y;
		GotoXY(_X, _Y);
	}
}
void MoveUp() {
	if (_Y > _A[0][0].y) {
		_Y -= 2;
		GotoXY(_X, _Y);
	}
	else if (_Y == _A[0][0].y) {
		_Y = _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y;
		GotoXY(_X, _Y);
	}
}

void Instruction() {
	cout << endl << endl << "                             HUONG DAN" << endl << endl;
	TextColor(116);  cout << "Dung phim mui ten hoac A,D,W,S de di chuyen. Dung phim Enter de danh dau." << endl;
	TextColor(116);  cout << "Enjoy your game!" << endl;
	system("pause");
	Menu();
}
void Infor() {
	cout << endl;
	TextColor(124);  cout << "Name: Caro" << endl;
	TextColor(124);  cout << "Author: Nhom 10 NMLT" << endl;
	TextColor(124);  cout << "Members:" << endl;
	TextColor(124);  cout << "Le Minh Duc" << endl;
	TextColor(124);  cout << "Nguyen Truong Giang" << endl;
	TextColor(124);  cout << "Pham Le Ha" << endl;
	TextColor(124);  cout << "Duong Tien Vinh" << endl;
	system("pause");
	Menu();
}
void Menu() {
	 system("cls");
	 system("color 70"); TextColor(113);
	 X:
	 GotoXY(31, 6); cout << "1. Choi 2 nguoi." << endl;
	 GotoXY(31, 7); cout << "2. Huong Dan." << endl;
	 GotoXY(31, 8); cout << "3. Thong tin." << endl;
	 GotoXY(31, 9); cout << "4. Thoat." << endl;
     GotoXY(31, 11); cout << "Menu: ";
	_COMMAND = toupper(_getch());
	cout << char(_COMMAND);
	Sleep(200);
	if (_COMMAND == '1') StartGame(); else
		if (_COMMAND == '2') Instruction(); else
			if (_COMMAND == '3') Infor(); else
				if (_COMMAND == '4') { ExitGame(); return; }
				else goto X;
}
void transFile(FILE* infile, FILE* outfile) {
	char ch;
	while (1) {
		ch = fgetc(infile);
		if (!feof(infile))
			fputc(ch, outfile);
		else break;
	}
}
void Read(const char* filename) {
	FILE* fpin;
	fpin = fopen(filename, "rt");
	transFile(fpin, stdout);
	fclose(fpin);
}
void SaveGame() {
	ofstream save("Text.txt");
	for (int i = 0; i <= BOARD_SIZE; i++) {
		for (int j = 0; j <= BOARD_SIZE; j++) {
			save << _A[i][j].x << " " << _A[i][j].y << " " << _A[i][j].c << endl;
		}
	}
}



void LoadGame(bool& ValidEnter)
{
	ResetData();
	StartGame();
	system("color 70");
	ifstream load("Text.txt");
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			load >> _A[i][j].x;
			load >> _A[i][j].y;
			load >> _A[i][j].c;
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			switch (_A[i][j].c)
			{
			case -1:
				GotoXY(_A[i][j].x, _A[i][j].y);
				TextColor(113);
				cout <<"X";
				break;
			case  1:
				GotoXY(_A[i][j].x, _A[i][j].y);
				TextColor(116);
				cout <<"O"; break;
			case  0: ValidEnter = false;
			}
		}
	}
}