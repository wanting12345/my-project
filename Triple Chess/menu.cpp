#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include"menu.h"
#include <windows.h>
#pragma comment (lib, "winmm.lib")  
#include<iostream>

IMAGE background;
IMAGE choose;
IMAGE map,begin1,begin2,begin0,end_choose, Cross, Circle, win1, win2, win3, who, who2, win4, green, orange, map2;;//叉，圆，空棋盘

//棋子宽度高度
#define chesswideth 140
#define chessHight 140
int flag = 0, end_flag = 0;
int time_;

//加载图片资源
void loadResource()
{
	loadimage(&map, _T("map.png"), Mapwideth, MapHight, true);
	loadimage(&begin1, _T("begin1.png"), Mapwideth, MapHight, true);
	loadimage(&begin2, _T("begin2.png"), Mapwideth, MapHight, true);
	loadimage(&begin0, _T("begin0.png"), Mapwideth, MapHight, true);
	loadimage(&end_choose, _T("end_choose.png"), Mapwideth, MapHight, true);
	loadimage(&Cross, _T("cross.png"), 150, 150, true);
	loadimage(&Circle, _T("circle.png"), 150, 150, true);
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

//播放提示音
void play_a1()//刚开始的音效
{
	mciSendString(TEXT("open 欢迎来到快乐三连.wav alias a1"), NULL, 0, NULL);
	mciSendString(TEXT("play a1 wait"), NULL, 0, NULL);
	mciSendString(TEXT("close a1"), NULL, 0, NULL);
}
void play_a2()//刚开始的音效
{
	mciSendString(TEXT("open 请选择玩家下棋的间隔.wav alias a2"), NULL, 0, NULL);
	mciSendString(TEXT("play a2 wait"), NULL, 0, NULL);
	mciSendString(TEXT("close a2"), NULL, 0, NULL);
}
void play_a3()//刚开始的音效
{
	mciSendString(TEXT("open 请选择游戏种类.wav alias a3"), NULL, 0, NULL);
	mciSendString(TEXT("play a3 wait"), NULL, 0, NULL);
	mciSendString(TEXT("close a3"), NULL, 0, NULL);
}
//鼠标检测
void ifhit1()//游戏时间的鼠标检测
{
	while (1)

	{
		if (!MouseHit())continue;
		if (MouseHit())
		{
			double xx = 0, yy = 0;
			MOUSEMSG m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:xx = m.x; yy = m.y;//左键按下


				break;
			}

			if (xx > 133 && xx < 374 && yy>119 && yy < 190)time_ = 5;
			else if (xx > 133 && xx < 374 && yy>215 && yy < 286)time_ = 10;
			else if (xx > 133 && xx < 374 && yy>306 && yy < 370)time_ = 15;
			else continue;
		}
		break;
	}
}
void ifhit2()//选择什么游戏的鼠标检测
{
	while (1)
	{
		if (!MouseHit())continue;
		if (MouseHit())
		{
			double xx = 0, yy = 0;
			MOUSEMSG n = GetMouseMsg();
			switch (n.uMsg)
			{
			case WM_LBUTTONDOWN:xx = n.x; yy = n.y;//左键按下
				break;
			}

			if (xx > 88 && xx < 400 && yy>104 && yy < 168)flag = 1;
			else if (xx > 88 && xx < 400 && yy>192 && yy < 256)flag = 2;
			else if (xx > 88 && xx < 400 && yy>280 && yy < 347)flag = 3;
			else if (xx > 88 && xx < 400 && yy>370 && yy < 437)flag = 4;
			else continue;
		}
		break;
	}
}

void ifhit6()//选择退出游戏或继续游戏的鼠标检测
{
	while (1)

	{
		if (!MouseHit())continue;
		if (MouseHit())
		{
			double xx = 0, yy = 0;
			MOUSEMSG n = GetMouseMsg();
			switch (n.uMsg)
			{
			case WM_LBUTTONDOWN:xx = n.x; yy = n.y;//左键按下
				break;
			}
			if (xx > 88 && xx < 400 && yy>106 && yy < 227)end_flag = 1;
			else if (xx > 88 && xx < 400 && yy>290 && yy < 405)end_flag = 2;
			else continue;
		}
		break;
	}
}

//开始界面
void begin()
{
	initgraph(Mapwideth, MapHight, SHOWCONSOLE);
	putimage(0, 0, &begin1);
	play_a2();
	ifhit1();
	std::cout<< "time=" << time_ <<std::endl;
	putimage(0, 0, &begin2);
	play_a3();
	ifhit2();
	std::cout << "flag=" << flag << std::endl;
	

}

// 载入PNG图并去透明部分
void drawAlpha(IMAGE* picture, int  picture_x, int picture_y) //x为载入图片的X坐标，y为Y坐标
{

	// 变量初始化
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //获取picture的显存指针
	int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
	int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
	int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
	int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
	int dstX = 0;    //在显存里像素的角标

	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //在显存里像素的角标
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
			int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //在显存里像素的角标
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
			}
		}
	}
}


