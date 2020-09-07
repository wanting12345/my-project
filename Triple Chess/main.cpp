#include<stdio.h>
#include<iostream>
#include"menu.h"
#include "imageprocess.h"
#include "game1.h"
#include "game2.h"
#include "game3.h"
#include"music.h"
#include <windows.h>
#pragma comment (lib, "winmm.lib")  
int playerNum = 1;//玩家1为1,棋子上数字为1，对应颜色为绿，玩家2为2，棋子上数字为-1，对应颜色为蓝
extern IMAGE end_choose, begin0;
void play_game() 
{
	begin();//选择游戏种类
	if (flag == 1)
	{
		game1();
	}
	else if (flag == 2)
	{
		game2();
	}
	else if (flag == 3)
	{
		game3();
	}
	else if (flag == 4)
	{
		game4();
	}
}
int main()
{
	loadResource();//加载资源
	initgraph(Mapwideth, MapHight, SHOWCONSOLE);
	putimage(0, 0, &begin0);//欢迎界面
	Sleep(1000);
	play_music(play_a1);
	while (1)
	{
		play_game();
		putimage(0, 0, &end_choose);
		Sleep(1000);
		ifhit6();
		if (end_flag == 1)continue;
		else if (end_flag == 2)break;

	}
	exit(1);
	return 0;
}
