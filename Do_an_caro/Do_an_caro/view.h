#ifndef _view_h_
#define _view_h_
void FixConsoleWindow();
void GotoXY(int x, int y);
void removeScrollbar();
void setSize();
void DrawBoard(int pSize);
int ProcessFinish(int pWhoWin);
void TextColor(int color);
int AskContinue();
#endif
