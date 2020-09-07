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

void Player1(int Board[ROW1][COL1], int row, int col);//**电脑移动的函数声明**
void Player2(int Board[ROW1][COL1], int row, int col);//**玩家移动的函数声明**
void first(int Board[ROW1][COL1], int row, int col);//谁先走
int IsWin(int Board[ROW1][COL1], int row, int col);//**判断电脑或者玩家有没有获得游戏胜利的函数声明**
int IsFull(int Board[ROW1][COL1], int row, int col);//**判断是否平局的函数声明**
int game1();
#endif

