using namespace std;
#pragma once
#ifndef _GAME1_H_
#define _GAME1_H_
const int ROW1 = 3;
const int COL1 = 3;
extern const int ROW1;
extern const int COL1;
extern int Board[ROW1][COL1];
extern int playerNum;
void update();

void Player1(int Board[ROW1][COL1], int row, int col);//**�����ƶ��ĺ�������**
void Player2(int Board[ROW1][COL1], int row, int col);//**����ƶ��ĺ�������**
void first(int Board[ROW1][COL1], int row, int col);//˭����
int IsWin(int Board[ROW1][COL1], int row, int col);//**�жϵ��Ի��������û�л����Ϸʤ���ĺ�������**
int IsFull(int Board[ROW1][COL1], int row, int col);//**�ж��Ƿ�ƽ�ֵĺ�������**
int game1();
#endif

