#include <iostream>
#include <windows.h>
#include <cstdlib> 
#include "game1.h"
#include "game2.h"
#include"menu.h"
#include"music.h"
#include "imageprocess.h"
#include<time.h>
#include <windows.h>
#pragma comment (lib, "winmm.lib")  
#include <graphics.h>
#include <conio.h>

extern IMAGE Cross, Circle, win1, win2, win3, who,who2 ,win4,map;//ͼƬ���������
int computerX = 0, computerY = 0; int whofirst2;
int Chess_flag = 0;//�Ƿ�������ı�־
void ifhit5();//����⣬���ѡ��˭����

int game2()
{
	for (int i = 0; i < ROW1; i++)
	{
		for (int j = 0; j < COL1; j++)
		{
			Board[i][j] = 0;
		}

	}
	int ret = 10;
	
	game2_first(Board, ROW1, COL1);
	update();
	while (1)
	{
		Computermove(Board, ROW1, COL1);//������
		ret = IsWin(Board, ROW1, COL1);//�ж���Ӯ
		if (ret != 0)
			break;
		Player2(Board, ROW1, COL1);//���2��
		ret = IsWin(Board, ROW1, COL1);
		if (ret != 0)
			break;

		
	}
	if (ret == 1)
	{
		printf("����ʤ��\n");
		putimage(0, 0, &win4);
		play_music(play_win4);
		Sleep(5000);

	}
	else if (ret == -1)
	{
		printf("���2ʤ����\n");
		putimage(0, 0, &win2);
		play_music(play_win2);
		Sleep(5000);
	}
	else if (ret == 3)
	{
		printf("ƽ�֣�\n");
		putimage(0, 0, &win3);
		play_music(play_win3);
		Sleep(5000);
	}
	return 0;
}



void ifhit5()
{
	while (1)

	{
		if (!MouseHit())continue;
		if (MouseHit())
		{
			double xx = 0, yy = 0;
			MOUSEMSG e = GetMouseMsg();
			switch (e.uMsg)
			{
			case WM_LBUTTONDOWN:xx = e.x; yy = e.y;//�������
				break;
			}
			if (xx > 127 && xx < 363 && yy>165 && yy < 240)whofirst2 = 1;
			else if (xx > 127 && xx < 363 && yy>298 && yy < 376)whofirst2 = -1;
			else continue;

		}

		break;
	}
}

void game2_first(int Board[ROW1][COL1], int row, int col)
{

	printf("���2���ߣ�\n������Y��N\n");
	putimage(0, 0, &who2);
	ifhit5();
	if (whofirst2 == -1)
	{
		printf("���2����\n");
		putimage(0, 0, &map);
		Sleep(1000);
		imageProcess(playerNum);
		Player2(Board, ROW1, COL1);//�����

	}
	else if (whofirst2 == 1)
		printf("��������\n");
	putimage(0, 0, &map);
	Sleep(1000);
	imageProcess(playerNum);
}

//�ж����޶���
void computerSite_1(int Board[ROW1][COL1], int& x, int& y, int judge_Num)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Board[i][j] == judge_Num)
			{
				//����
				if ((i + 1 < 3 && Board[i + 1][j] == judge_Num)
					|| (i - 1 >= 0 && Board[i - 1][j] == judge_Num)
					|| (i == 0 && Board[i + 2][j] == judge_Num)
					|| (i == 2 && Board[i - 2][j] == judge_Num))
				{
					for (int k = 0; k < 3; k++)
					{
						if (Board[k][j] == 0)
						{
							Board[k][j] = 1; x = k; y = j; Chess_flag = 1; break;
						}
					}
					if (Chess_flag)break;
				}
				//����
				if ((j + 1 < 3 && Board[i][j + 1] == judge_Num)
					|| (j - 1 >= 0 && Board[i][j - 1] == judge_Num)
					|| (j == 0 && Board[i][j + 2] == judge_Num)
					|| (j == 2 && Board[i][j - 2] == judge_Num))
				{
					for (int k = 0; k < 3; k++)
					{
						if (Board[i][k] == 0)
						{
							Board[i][k] = 1; x = i; y = k; Chess_flag = 1; cout << x << y << endl; break;
						}
					}
					if (Chess_flag)break;
				}
				//��б��
				if (((j + 1 < 3 && i + 1 < 3 && i == j) && Board[i + 1][j + 1] == judge_Num)
					|| ((j - 1 >= 0 && i - 1 >= 0 && i == j) && Board[i - 1][j - 1] == judge_Num)
					|| ((j == 0 && i == 0) && Board[i + 2][j + 2] == judge_Num)
					|| ((j == 2 && i == 2) && Board[i - 2][j - 2] == judge_Num))
				{
					for (int k = 0; k < 3; k++)
					{
						if (Board[k][k] == 0)
						{
							Board[k][k] = 1; x = k; y = k; Chess_flag = 1; break;
						}
					}
					if (Chess_flag)break;
				}
				//��б��
				if (((j + 1 < 3 && i - 1 >= 0 && i + j == 2) && Board[i - 1][j + 1] == judge_Num)
					|| ((j - 1 >= 0 && i + 1 < 3 && i + j == 2) && Board[i + 1][j - 1] == judge_Num)
					|| ((j == 0 && i == 2) && Board[i - 2][j + 2] == judge_Num)
					|| ((j == 2 && i == 0) && Board[i + 2][j - 2] == judge_Num))
				{
					for (int k = 0; k < 3; k++)
					{
						if (Board[k][2 - k] == 0)
						{
							Board[k][2 - k] = 1; x = k; y = 2 - k; Chess_flag = 1; break;
						}
					}
					if (Chess_flag)break;
				}

			}
		}
		if (Chess_flag)break;
	}
}
//��ֹ����
void computerSite_2(int Board[ROW1][COL1], int& x, int& y, int judge_Num)
{
	//����2,2��λ��Ϊ�գ����ڴ˴�����
	if (Board[1][1] == 0)
	{
		Board[1][1] = 1; x = 1; y = 1; Chess_flag = 1;
	}
	//������������
	else {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Board[i][j] == judge_Num)
				{
					//����
					if (i + 1 < 3 && Board[i + 1][j] == 0)
					{
						Board[i + 1][j] = 1; x = i + 1; y = j; Chess_flag = 1; break;
					}
					//����
					else if (i - 1 > 0 && Board[i - 1][j] == 0)
					{
						Board[i - 1][j] = 1; x = i - 1; y = j; Chess_flag = 1; break;
					}
					//����
					else if (j + 1 < 3 && Board[i][j + 1] == 0)
					{
						Board[i][j + 1] = 1; x = i; y = j + 1; Chess_flag = 1; break;
					}
					//����
					else if (j - 1 > 0 && Board[i][j - 1] == 0)
					{
						Board[i][j - 1] = 1; x = i; y = j - 1; Chess_flag = 1; break;
					}
					//����
					else if ((j + 1 < 3 && i + 1 < 3) && Board[i + 1][j + 1] == 0)
					{
						Board[i + 1][j + 1] = 1; x = i + 1; y = j + 1; Chess_flag = 1; break;
					}
					//����
					else if ((j - 1 > 0 && i - 1 > 0) && Board[i - 1][j - 1] == 0)
					{
						Board[i - 1][j - 1] = 1; x = i - 1; y = i - 1; Chess_flag = 1; break;
					}
					//����
					else if ((i + 1 < 3 && j - 1 >= 0) && Board[i + 1][j - 1] == 0)
					{
						Board[i + 1][j - 1] = 1; x = i + 1; y = j - 1; Chess_flag = 1; break;
					}
					//����
					else if ((i - 1 >= 0 && j + 1 < 3) && Board[i - 1][j + 1] == 0)
					{
						Board[i - 1][j + 1] = 1; x = i - 1; y = j + 1; Chess_flag = 1; break;
					}

				}

			}
			if (Chess_flag)break;

		}
	}
}
//���ŵ��Ե�������
void computerSite_3(int Board[ROW1][COL1], int& x, int& y, int judge_num)
{
	if (Board[0][0] == 0 && ((Board[0][1] == judge_num && Board[0][2] == 0) || (Board[0][2] == judge_num && Board[0][1] == 0))
		&& ((Board[1][0] == judge_num && Board[2][0] == 0) || (Board[2][0] == judge_num && Board[1][0] == 0)))
	{
		Board[0][0] = 1; Chess_flag = 1; x = 0; y = 0;
	}
	else if (Board[0][2] == 0 && ((Board[0][1] == judge_num && Board[0][0] == 0) || (Board[0][0] == judge_num && Board[0][1] == 0))
		&& ((Board[1][2] == judge_num && Board[2][2] == 0) || (Board[2][2] == judge_num && Board[1][2] == 0)))
	{
		Board[0][2] = 1; Chess_flag = 1; x = 0; y = 0;
	}
	else if (Board[2][0] == 0 && ((Board[1][0] == judge_num && Board[0][0] == 0) || (Board[0][0] == judge_num && Board[1][0] == 0))
		&& ((Board[2][2] == judge_num && Board[2][1] == 0) || (Board[2][1] == judge_num && Board[2][2] == 0)))
	{
		Board[2][0] = 1; Chess_flag = 1; x = 0; y = 0;
	}
	else if (Board[2][2] == 0 && ((Board[2][0] == judge_num && Board[2][1] == 0) || (Board[2][1] == judge_num && Board[2][0] == 0))
		&& ((Board[0][2] == judge_num && Board[1][2] == 0) || (Board[1][2] == judge_num && Board[0][2] == 0)))
	{
		Board[2][2] = 1; Chess_flag = 1; x = 0; y = 0;
	}
}
//�������
void computer_rand(int Board[ROW1][COL1], int& x, int& y)
{

	while (1)
	{
		x = rand() % ROW1;//**rand������Ϊ�õ������������**
		y = rand() % COL1;
		if (Board[x][y] == 0)
		{
			Board[x][y] = 1; Chess_flag = 1; break;
		}
	}


}

//�������庯��
void Computermove(int Board[ROW1][COL1], int row, int col)
{
	playerNum = 1;//���������1���������2

	Chess_flag = 0;//��ʼ�������־

	//�жϵ����Լ����޶���
	computerSite_1(Board, computerX, computerY, 1);

	//�ж�������޶���
	if (!Chess_flag)
	{
		computerSite_1(Board, computerX, computerY, -1); cout << "chessflag=" << Chess_flag << endl;
	}
	//���Կ��������� ����
	if (!Chess_flag)
	{
		computerSite_3(Board, computerX, computerY, 1); cout << "chessflag=" << Chess_flag << endl;
	}//��ֹ�����������
	if (!Chess_flag)
	{

		computerSite_3(Board, computerX, computerY, -1); cout << "chessflag=" << Chess_flag << endl;
	}

	//���ŵ�������
	if (!Chess_flag)
	{
		computerSite_2(Board, computerX, computerY, 1); cout << "chessflag=" << Chess_flag << endl;
	}
	//��������Լ�����������
	if (!Chess_flag)
	{
		computerSite_2(Board, computerX, computerY, -1); cout << "chessflag=" << Chess_flag << endl;
	}
	//�������
	if (!Chess_flag)
	{
		computer_rand(Board, computerX, computerY); cout << "chessflag=" << Chess_flag << endl;
	}

	//���ŵ�����Ҫ�µ����λ��
	int ax, ay;
	ax = computerX; ay = computerY;
	if (ax == 0)
	{
		switch (ay)
		{
		case 0:play_music(play_c1); break;
		case 1:play_music(play_c2); break;
		case 2:play_music(play_c3); break;
		}
	}
	else if (ax == 1)
	{
		switch (ay)
		{
		case 0:play_music(play_c4); break;
		case 1:play_music(play_c5); break;
		case 2:play_music(play_c6); break;
		}
	}
	else if (ax == 2)
	{
		switch (ay)
		{
		case 0:play_music(play_c7); break;
		case 1:play_music(play_c8); break;
		case 2:play_music(play_c9); break;
		}
	}
	update();
	Sleep(5000);
	imageProcess(playerNum);
}

