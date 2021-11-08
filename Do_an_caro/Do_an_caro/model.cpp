#include <iostream>
#include <Windows.h>
#include "model.h"
#include "caro.h"
using namespace std;
void ResetData() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			_A[i][j].x = 4 * j + LEFT + 2;
			_A[i][j].y = 2 * i + TOP + 1;
			_A[i][j].c = 0;
		}
	}
	_TURN = true; _COMMAND = -1;
	_X = _A[0][0].x; _Y = _A[0][0].y;
}
int CheckBoard(int pX, int pY) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {	
				if (_TURN == true) _A[i][j].c = -1;
				else _A[i][j].c = 1;
				return _A[i][j].c;
			}	
		}
	}
	return 0;
}
//Struct COORD
//typedef struct _COORD {
//	SHORT X;
//	SHORT Y;
//} COORD, * PCOORD;
COORD getCOORD(int pX, int pY) //Lay toa do hien hanh tren ma tran ban co
{
	COORD c;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_A[i][j].x == pX && _A[i][j].y == pY)
			{
				c.X = i;
				c.Y = j;
				return c;
			}
		}
	}
}
bool isMatch(int a[])
{
	int count = 0;
	for (int i = 0; i < 9; i++)//i=0; i < 9 vi neu danh 4 lien tiep sau do cach ra 1 o danh 4 lien tiep nua
	{
		if (a[i] == 1)
		{
			count++;
		}
		else
		{
			if (count >= 5)
				return true;
			else
				count = 0;
		}
	}
	if (count >= 5) return true; //thang
	else return false;
}
int checkWin(int pX, int pY)
{
	COORD c = getCOORD(pX, pY);
	int pWin = _A[c.X][c.Y].c; //Gan luot danh dau mac dinh
	int isWinner = 2;
	//Kiem tra cot
	int testArr1[9] = { 0,0,0,0,1,0,0,0,0 };
	for (int i = 1; i <= 4; i++)
	{
		if (c.X - i >= 0)
		{
			if (_A[c.X - i][c.Y].c == pWin) 
			{
				testArr1[4 - i] = 1;
			}
		}
		if (c.X + i < BOARD_SIZE)
		{
			if (_A[c.X + i][c.Y].c == pWin)
			{
				testArr1[4 + i] = 1;
			}
		}
	}
	if (isMatch(testArr1)) return pWin;
	// Kiem tra hang
	int testArr2[9] = { 0,0,0,0,1,0,0,0,0 };
	for (int i = 1; i <= 4; i++)
	{
		if (c.Y - i >= 0)
		{
			if (_A[c.X][c.Y - i].c == pWin)
			{
				testArr2[4 - i] = 1;
			}
		}
		if (c.Y + i < BOARD_SIZE)
		{
			if (_A[c.X][c.Y + i].c == pWin)
			{
				testArr2[4 + i] = 1;
			}
		}
	}

	if (isMatch(testArr2)) return pWin;

	// Cheo chinh

	int testArr3[9] = { 0,0,0,0,1,0,0,0,0 };

	for (int i = 1; i <= 4; i++)
	{
		if (c.X - i >= 0 && c.Y - i >= 0)
		{
			if (_A[c.X - i][c.Y - i].c == pWin)
			{
				testArr3[4 - i] = 1;
			}
		}
		if (c.X + i < BOARD_SIZE && c.Y + i < BOARD_SIZE)
		{
			if (_A[c.X + i][c.Y + i].c == pWin)
			{
				testArr3[4 + i] = 1;
			}
		}
	}

	if (isMatch(testArr3)) return pWin;

	// cheo phu
	int testArr4[9] = { 0,0,0,0,1,0,0,0,0 };
	for (int i = 1; i <= 4; i++)
	{
		if (c.X - i >= 0 && c.Y + i < BOARD_SIZE)
		{
			if (_A[c.X - i][c.Y + i].c == pWin)
			{
				testArr4[4 - i] = 1;
			}
		}
		if (c.X + i < BOARD_SIZE && c.Y - i >= 0)
		{
			if (_A[c.X + i][c.Y - i].c == pWin)
			{
				testArr4[4 + i] = 1;
			}
		}
	}

	if (isMatch(testArr4)) return pWin;
	return 2;
}
int TestBoard(int pX, int pY)
{
	bool flag = 1;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_A[i][j].c == 0) {
				flag = 0; break;
			}
		}
	}
	if (flag == 1) return 0;
	else {
		return checkWin(pX, pY);
	}
}
