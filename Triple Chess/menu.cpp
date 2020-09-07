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
IMAGE map,begin1,begin2,begin0,end_choose, Cross, Circle, win1, win2, win3, who, who2, win4, green, orange, map2;;//�棬Բ��������

//���ӿ�ȸ߶�
#define chesswideth 140
#define chessHight 140
int flag = 0, end_flag = 0;
int time_;

//����ͼƬ��Դ
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

//������ʾ��
void play_a1()//�տ�ʼ����Ч
{
	mciSendString(TEXT("open ��ӭ������������.wav alias a1"), NULL, 0, NULL);
	mciSendString(TEXT("play a1 wait"), NULL, 0, NULL);
	mciSendString(TEXT("close a1"), NULL, 0, NULL);
}
void play_a2()//�տ�ʼ����Ч
{
	mciSendString(TEXT("open ��ѡ���������ļ��.wav alias a2"), NULL, 0, NULL);
	mciSendString(TEXT("play a2 wait"), NULL, 0, NULL);
	mciSendString(TEXT("close a2"), NULL, 0, NULL);
}
void play_a3()//�տ�ʼ����Ч
{
	mciSendString(TEXT("open ��ѡ����Ϸ����.wav alias a3"), NULL, 0, NULL);
	mciSendString(TEXT("play a3 wait"), NULL, 0, NULL);
	mciSendString(TEXT("close a3"), NULL, 0, NULL);
}
//�����
void ifhit1()//��Ϸʱ��������
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
			case WM_LBUTTONDOWN:xx = m.x; yy = m.y;//�������


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
void ifhit2()//ѡ��ʲô��Ϸ�������
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
			case WM_LBUTTONDOWN:xx = n.x; yy = n.y;//�������
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

void ifhit6()//ѡ���˳���Ϸ�������Ϸ�������
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
			case WM_LBUTTONDOWN:xx = n.x; yy = n.y;//�������
				break;
			}
			if (xx > 88 && xx < 400 && yy>106 && yy < 227)end_flag = 1;
			else if (xx > 88 && xx < 400 && yy>290 && yy < 405)end_flag = 2;
			else continue;
		}
		break;
	}
}

//��ʼ����
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

// ����PNGͼ��ȥ͸������
void drawAlpha(IMAGE* picture, int  picture_x, int picture_y) //xΪ����ͼƬ��X���꣬yΪY����
{

	// ������ʼ��
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
	int picture_width = picture->getwidth(); //��ȡpicture�Ŀ�ȣ�EASYX�Դ�
	int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
	int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ�ȣ�EASYX�Դ�
	int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
	int dstX = 0;    //���Դ������صĽǱ�

	// ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
			int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //���Դ������صĽǱ�
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //��p=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //��p=sa/255 , FP=sb , BP=db
			}
		}
	}
}


