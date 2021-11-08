#ifndef _model_h_
#define _model_h_
#include <Windows.h>
void ResetData();
int TestBoard(int pX, int pY);
int CheckBoard(int pX, int pY);
COORD getCOORD(int pX, int pY);
int checkWin(int pX, int pY);
#endif

