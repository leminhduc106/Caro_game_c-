#include <iostream>
#include <conio.h>
#include "control.h"
#include "model.h"
#include "view.h"
#include "caro.h"
using namespace std;
void main() {
	system("color 70");
	setSize();
	FixConsoleWindow();
	removeScrollbar();
	Z:
	Menu();
	system("color 70");
	if (_COMMAND == '4') { ExitGame(); return; }
	else StartGame();
	bool validEnter = true;
	while (1) {
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27) {
			ExitGame();
			return;
		}
		else if (_COMMAND == 'O') LoadGame(validEnter);
		else {
			if (_COMMAND == 'A' || _COMMAND == 75) MoveLeft();
			else if (_COMMAND == 'W' || _COMMAND == 72) MoveUp();
			else if (_COMMAND == 'S' || _COMMAND == 80) MoveDown();
			else if (_COMMAND == 'D' || _COMMAND == 77) MoveRight();
			else if (_COMMAND == 13) {
				switch (CheckBoard(_X, _Y)) {
				case -1:
				{TextColor(113); //Mau do
				cout << "X"; break; }
				case 1:
				{TextColor(116); //Mau xanh duong
					cout << "O"; break; }
				case 0: validEnter = false;
				}
				if (validEnter == true) {
					switch (ProcessFinish(TestBoard(_X, _Y))) {
					case -1: case 1: case 0:
						Y:
						if (AskContinue() == 'N') {
							ExitGame(); return;
						}
						else if (AskContinue() == 'Y'){ system("color 70"); StartGame();}
						else goto Y;
					}
				}
				validEnter = true;
			}
		}
		if (_COMMAND == 'L') SaveGame();
		if (_COMMAND == 'B') goto Z;
	}
}