#include <iostream>
#include <windows.h>
#include <cstdlib> 
#include "game1.h"
#include "imageprocess.h"
#include "stdio.h"
#include"menu.h"
#include <windows.h>
#pragma comment (lib, "winmm.lib")  
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include"music.h"
extern IMAGE map;
extern IMAGE Cross, Circle,win1, win2, win3, who,who2,win4,map2,green,orange;
void ifhit3();
using namespace std;
int whofirst;
int Board[ROW1][COL1] = {0};
void loadimage2()
{
	loadimage(&Cross, _T("cross.png"), 150, 150, true);
	loadimage(&Circle, _T("circle.png"), 150,150, true);
	loadimage(&map, _T("map.png"), 480, 480, true);
	loadimage(&win1, _T("win1.png"), 480, 480, true);
	loadimage(&win2, _T("win2.png"), 480, 480, true);
	loadimage(&win3, _T("win3.png"), 480, 480, true);
	loadimage(&who, _T("first.png"), 480, 480, true);
	loadimage(&who2, _T("first2.png"), 480, 480, true);
	loadimage(&win4, _T("win4.png"), 480, 480, true);
	loadimage(&green, _T("green.png"), 40, 40, true);
	loadimage(&orange, _T("orange.png"), 40, 40, true);
	loadimage(&map2, _T("game3.png"), 480, 480, true);



}
void update()
{
	putimage(0, 0, &map);
	Sleep(100);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (Board[i][j] == 1)
				putimage(j * 170, i * 170, &Circle);
			else if (Board[i][j] == -1)
				putimage(j * 170, i * 170, &Cross);
	}
}
void first(int Board[ROW1][COL1], int row, int col)
{
	
	printf("玩家1先走？\n");
	putimage(0, 0, &who);
	ifhit3();
		if(whofirst==1){
			printf("玩家1先走\n");
			putimage(0, 0, &map);
			Sleep(1000);
			Player1(Board, ROW1, COL1);//玩家走
		
		}
		else if (whofirst==-1)
		{
			printf("玩家2先走\n");
			putimage(0, 0, &map);
			Sleep(1000);
		}		
	}
	


void Player1(int Board[ROW1][COL1], int row, int col)
{
	playerNum = 1;
	cout << "玩家1下棋" << endl;
	if (time_ == 5)
		play_music(play_b1_5);
	else if (time_ == 10)
		play_music(play_b1_10);
	else if (time_ == 15)
		play_music(play_b1_15);
	Sleep(time_ * 1000);
	imageProcess(playerNum);
	putimage(0, 0, &map);
	Sleep(100);
	//放置棋子图片
	update();	
}

void Player2(int Board[ROW1][COL1], int row, int col)
{
	playerNum = 2;
	cout << "玩家2下棋" << endl;
	if (time_ == 5) {
		play_music(play_b2_5);
	}
	else if (time_ == 10) {
		play_music(play_b2_10);
	}
	else if (time_ ==15) {
		play_music(play_b2_15);
	}
	Sleep(time_ * 1000);
	imageProcess(playerNum);
	//更新棋盘
	update();
}

 
int IsWin(int Board[ROW1][COL1], int row, int col)
{
	for (int i = 0; i < ROW1; i++)//行3
	{
		if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][2] != 0)
			return Board[i][0];
	}
	for (int i = 0; i < COL1; i++)//竖3
	{
		if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] && Board[2][i] !=0)
			return Board[0][i];
	}

	if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[2][2] != 0)//叉3
		return Board[1][1];
	if (Board[2][0] == Board[1][1] && Board[1][1] == Board[0][2] && Board[0][2] != 0)
		return Board[1][1];
	if (IsFull(Board, ROW1, COL1) == 3)
	{
		return 3;
	}
	return 0;
}

int IsFull(int Board[ROW1][COL1], int row, int col)//判断是否空格满了
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (Board[i][j] == 0)
				return 0;
	
		}
	}
	return 3; 
}
int game1()
{
	for (int i = 0; i < ROW1; i++)
	{
		for (int j = 0; j < COL1; j++)
		{
			Board[i][j] = 0;
		}
	}
	initgraph(480, 480, SHOWCONSOLE);
	int ret=10;
	first(Board, ROW1, COL1);
	while (1)
	{
		Player2(Board, ROW1, COL1);//玩家2走	
		ret = IsWin(Board, ROW1, COL1);
		if (ret != 0)
			break;

		Player1(Board, ROW1, COL1);//玩家1走
		ret = IsWin(Board, ROW1, COL1);//判断输赢
		if (ret != 0)
			break;
	}
	if (ret == 1)
	{
		printf("玩家1胜利\n");
		putimage(0, 0, &win1);
		play_music(play_win1);
		Sleep(5000);
	}
	else if (ret == -1)
	{
		printf("玩家2胜利！\n");
		putimage(0, 0, &win2);
		play_music(play_win2);
		Sleep(5000);
	}
	else if (ret == 3)
	{
		printf("平局！\n");
		putimage(0, 0, &win3);
		play_music(play_win3);
		Sleep(5000);
	}
	return 0;

}


void ifhit3()
{
	while (1)

	{
		if (!MouseHit())continue;
		if (MouseHit())
		{
			double xx = 0, yy = 0;
			MOUSEMSG r = GetMouseMsg();
			switch (r.uMsg)
			{
			case WM_LBUTTONDOWN:xx = r.x; yy = r.y;//左键按下
				break;
			}
			if (xx > 127 && xx < 363 && yy>165 && yy < 240)whofirst = 1;
			else if (xx > 127 && xx < 363 && yy>298 && yy < 376)whofirst = -1;
			else continue;

		}

		break;
	}
}