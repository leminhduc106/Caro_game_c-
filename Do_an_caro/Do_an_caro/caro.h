#ifndef _caro_h_
#define _caro_h_
#define BOARD_SIZE 12 //Kich thuoc ma tran ban co
#define LEFT 3 //Toa do trai man hinh ban co
#define TOP 1 //Toa do tren man hinh ban co
//Khai bao kieu du lieu
extern struct _POINT { int x, y, c; }; //x: toa do dong, y: toa do cot, c: danh dau
extern _POINT _A[BOARD_SIZE][BOARD_SIZE]; //Ma tran ban co
extern bool _TURN; //true la luot nguoi thu 1 con false la luot nguoi thu 2
extern int _COMMAND; //Bien nhan gia tri nguoi dung nhap
extern int _X, _Y; //Toa do hien hanh tren man hinh ban co
#endif
