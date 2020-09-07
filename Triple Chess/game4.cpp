#include "game4.h"
#include <iostream>
#include<string>
#include "imageprocess.h"
#include<Windows.h>
#include<time.h>
#include <windows.h>
#pragma comment (lib, "winmm.lib")  
#include <graphics.h>
#include <conio.h>
#include "game3.h"
#include"menu.h"
#include"music.h"
#include "imageprocess.h"

extern IMAGE map2, green, orange, win1, win2, win3,win4;
extern chessboard CB;
int chess_flag = 0;//�жϵ����Ƿ��Ѿ��º�����
int ring_board[24] = { 0 };//��һά����洢������
using namespace std;

//���������һ�ε��������꣨�����жϵ����Լ���������
void chessboard::setpprevious() 
{
	PPPnum = chess_num;
	for (int i = 0; i < chess_num; i++)
	{
		PPPchess[i] = Pchess[i];
	}
}
//��ȡ���Դ˴����ӵ�����
void chessboard::setchessboard_cpu() 
{
	int n = 0;
	for (int i = 0; i < 7; i++) 
	{
		for (int j = 0; j < 7; j++) 
		{
			if (Achess[i][j] == 1) 
			{
				Pchess[n].x = i;
				Pchess[n].y = j;
				n++;
			}
		}
	}
	chess_num = n;
}
//�������庯��һ���ж���û�п��Դﵽ���������
void chessboard::computersite_1(chess* PPchess, int PPnum, chess* PPPchess, int PPPnum, int judge_num)
{
	chess_flag = 0;//��ʼ�������־

	int num = (judge_num == -1) ? PPnum : PPPnum;

	//�Ȱ�Pchess�����ݴ������̵ֶı���
	int xx, yy, s, l,xx1,yy1,xx2,yy2;

	for (int i = 0; i < num; i++)
	{
		
		if (judge_num == -1) 
		{
			xx = PPchess[i].x, yy = PPchess[i].y, s = PPchess[i].space, l = PPchess[i].layer; 
		}
		else 
		{
			xx = PPPchess[i].x, yy = PPPchess[i].y, s = PPPchess[i].space, l = PPPchess[i].layer; 
		}
		if (xx < 3) { xx1 = xx + s; xx2 = xx + 2 * s; }
		else { xx1 = xx - s; xx2 = xx - 2 * s; }
		if (yy < 3) { yy1 = yy + s; yy2 = yy + 2 * s; }
		else { yy1 = yy - s; yy2 = yy - 2 * s; }
	
		//�������������һ��

		if (Achess[xx][yy - 1] == judge_num || Achess[xx][yy + 1] == judge_num)
		{
			if (xx == 3) 
			{

				if (yy < 3)
				{
					for (int i = 0; i < 3; i++)
					{
						if (Achess[xx][i] == 0)
						{
							Achess[xx][i] = 1; chess_flag = 1;
							break;
						}
					}
				}
				else
				{
					for (int i = 6; i > 3; i--)
					{
						if (Achess[xx][i] == 0) 
						{
							Achess[xx][i] = 1; chess_flag = 1;  
							break;
						}
					}
				}
			}
			else if (xx == 2 || xx == 4)
			{
				for (int i = 2; i < 5; i++)
				{
					if (Achess[xx][i] == 0) 
					{
						Achess[xx][i] = 1; chess_flag = 1; 
						break;
					}
				}
			}
			if (chess_flag)break;
		}

		 if ((l != 2) && ((Achess[xx][yy - 2] == judge_num && ((xx != 3) || (yy - 2 != 2))) ||
			((Achess[xx][yy + 2] == judge_num) && ((xx != 3) || (yy + 2 != 5))) ||
			(Achess[xx - 2][yy] == judge_num && ((xx - 2 != 2) || (yy != 3))) ||
			(Achess[xx + 2][yy] == judge_num && ((xx + 2 != 5) || (yy != 3)))))
		{
			if ((Achess[3][0] == judge_num && Achess[3][2] == judge_num) && Achess[3][1] == 0) 
			{
				Achess[3][1] = 1; chess_flag = 1;
			}
			else if ((Achess[3][4] == judge_num && Achess[3][6] == judge_num) && Achess[3][5] == 0) 
			{
				Achess[3][5] = 1; chess_flag = 1;
			}
			else if ((Achess[0][3] == judge_num && Achess[2][3] == judge_num) && Achess[1][3] == 0) 
			{
				Achess[1][3] = 1; chess_flag = 1;
			}
			else if ((Achess[4][3] == judge_num && Achess[6][3] == judge_num) && Achess[5][3] == 0) 
			{
				Achess[5][3] = 1; chess_flag = 1;
			}
			

			if (chess_flag)break;
		}
		//��������������һ������м��һ��

		 if (Achess[xx - 1][yy] == judge_num || Achess[xx + 1][yy] == judge_num)
		{
			if (yy == 3) {
				if (xx < 3)
				{
					for (int i = 0; i < 3; i++)
					{
						if (Achess[i][yy] == 0) 
						{
							Achess[i][yy] = 1; chess_flag = 1; 
							break;
						}
					}
				}
				else

				{
					for (int i = 6; i > 3; i--)
					{
						if (Achess[i][yy] == 0) 
						{
							Achess[i][yy] = 1; chess_flag = 1; 
							break;
						}
					}
				}
			}

			 if (yy == 2 || yy == 4)
			{

				for (int i = 2; i < 5; i++)
				{
					if (Achess[i][yy] == 0) 
					{
						Achess[i][yy] = 1; chess_flag = 1; 
						break;
					}

				}
			}
			if (chess_flag)break;
		}

		if(xx==yy||xx+yy==6){
			
				if (Achess[xx][yy2]==judge_num && Achess[xx][yy1] == 0) 
				{
					Achess[xx][yy1] = 1; chess_flag = 1; 
				}
				else if (Achess[xx][yy1]==judge_num && Achess[xx][yy2] == 0) 
				{
					Achess[xx][yy2] = 1; chess_flag = 1; 
				}
				else if (Achess[xx2][yy] == judge_num && Achess[xx1][yy] == 0) 
				{
					Achess[xx1][yy] = 1; chess_flag = 1;
				}
				else if (Achess[xx1][yy] == judge_num && Achess[xx2][yy] == 0) 
				{
					Achess[xx2][yy] = 1; chess_flag = 1;
				}
			if (chess_flag)break;
		}

		//xx == yy ��������б�Խ���

		if (xx == yy && (Achess[xx - 1][yy - 1] == judge_num || Achess[xx + 1][yy + 1] == judge_num))
		{
			if (xx < 3)
			{
				for (int i = 0; i < 3; i++)
				{
					if (Achess[i][i] == 0) 
					{
						Achess[i][i] = 1; chess_flag = 1; 
						break;
					}
				}
			}
			else {
				for (int i = 6; i > 3; i--)
				{
					if (Achess[i][i] == 0) 
					{
						Achess[i][i] = 1; chess_flag = 1; 
						break;
					}
				}
			}
			if (chess_flag)break;
		}



		//xx+yy == 6���� ����б�Խ���
		 if ((xx + yy == 6) && (Achess[xx + 1][yy - 1] == judge_num || Achess[xx - 1][yy + 1] == judge_num))
		{
			if (xx < 3)
			{
				for (int i = 0; i < 3; i++)
				{
					if (Achess[i][6 - i] == 0) 
					{
						Achess[i][6 - i] = 1; chess_flag = 1; 
						break;
					}
				}
			}
			else {
				for (int i = 6; i > 3; i--)
				{
					if (Achess[i][6 - i] == 0) 
					{
						Achess[i][6 - i] = 1; chess_flag = 1; 
						break;
					}
				}
			}
			if (chess_flag)break;
		}

		 if ((Achess[xx - 2][yy - 2] == judge_num && ((xx - 2 != 2) || (yy - 2 != 4)))
			|| (Achess[xx + 2][yy + 2] == judge_num && ((xx + 2 != 2) || (yy + 2 != 4)))
			|| (Achess[xx + 2][yy - 2] == judge_num && ((xx + 2 != 2) || (yy - 2 != 4)))
			|| (Achess[xx - 2][yy + 2] == judge_num && ((xx - 2 != 2) || (yy + 2 != 4))))
		{
			if ((Achess[0][0] == judge_num && Achess[2][2] == judge_num) && Achess[1][1] == 0) 
			{
				Achess[1][1] = 1; chess_flag = 1;
			}
			else if ((Achess[4][4] == judge_num && Achess[6][6] == judge_num) && Achess[5][5] == 0) 
			{
				Achess[5][5] = 1; chess_flag = 1;
			}
			else if ((Achess[0][6] == judge_num && Achess[2][4] == judge_num) && Achess[1][5] == 0) 
			{
				Achess[1][5] = 1; chess_flag = 1;
			}
			if ((Achess[4][2] == judge_num && Achess[6][0] == judge_num) && Achess[5][1] == 0) 
			{
				Achess[5][1] = 1; chess_flag = 1;
			}
			if (chess_flag)break;
		}



	}

}
//��ά����ת��Ϊһλ����
void chessboard::changboard1()
{
	int k = 0;
	for (int i = 3, j = 3; i > 0; i--, j--)
	{
		ring_board[k] = Achess[3 - i][3 - j]; k++;
		ring_board[k] = Achess[3 - i][3]; k++;
		ring_board[k] = Achess[3 - i][3 + j]; k++;
		ring_board[k] = Achess[3][3 + j]; k++;
		ring_board[k] = Achess[3 + i][3 + j]; k++;
		ring_board[k] = Achess[3 + i][3]; k++;
		ring_board[k] = Achess[3 + i][3 - j]; k++;
		ring_board[k] = Achess[3][3 - j]; k++;
	}
}
//һά����ת��Ϊ��ά����
void chessboard::changboard2()
{
	int k = 0;
	for (int i = 3, j = 3; i > 0; i--, j--) 
	{
		Achess[3 - i][3 - j] = ring_board[k]; k++;
		Achess[3 - i][3] = ring_board[k]; k++;
		Achess[3 - i][3 + j] = ring_board[k]; k++;
		Achess[3][3 + j] = ring_board[k]; k++;
		Achess[3 + i][3 + j] = ring_board[k]; k++;
		Achess[3 + i][3] = ring_board[k]; k++;
		Achess[3 + i][3 - j] = ring_board[k]; k++;
		Achess[3][3 - j] = ring_board[k]; k++;

	}
	int n = 0;
	for (int i = 0; i < 7; i++) 
	{
		for (int j = 0; j < 7; j++) 
		{
			if (Achess[i][j] != 0) 
			{  //����ȷ�������λ��ֵ��Ϊ0���������Ӵ���ʱ����ֵ��Achess
				Pchess[n].x = i;  //���ѵ�ǰ�����괫��Pchess
				Pchess[n].y = j;
				n++;
			}
		}
	}
}

//�������庯������������������������
void chessboard::computersite_2(chess* PPchess, int PPnum)
{
	
	CB.changboard1();

	int exit_chess[12] = { 0 };//�洢���е�����,�������ȡ����

	int t = 0;
	for (int p = 0; p < 24; p++)
	{
		if (ring_board[p] == -1) 
		{
			exit_chess[t] = p;
			t++;
		}
	}
	int q = 0;//���ڼ��������100�ζ�û���������ʱ������������
	for (int i = 0; i < 24; i++)
	{
		q++;
		int Rand;
		if (t == 0)Rand = 0;
		else Rand = rand() % t;
		if (q < 100)  i = exit_chess[Rand];

		if ((i != 7) && (i != 15) && (i != 23) && ring_board[i + 1] == 0)
		{
			ring_board[i + 1] = 1; chess_flag = 1; break;
		}
		else if ((i != 8) && (i != 16) && (i != 0) && ring_board[i - 1] == 0) 
		{
			ring_board[i - 1] = 1; chess_flag = 1; break;
		}
		else if (((i == 7) || (i == 15) || (i == 23)) && ring_board[i - 7] == 0) 
		{
			ring_board[i - 7] = 1; chess_flag = 1; break;
		}
		else if (((i == 8) || (i == 16) || (i == 0)) && ring_board[i + 7] == 0) 
		{
			ring_board[i + 7] = 1; chess_flag = 1; break;
		}
		else if ((i + 8) < 24 && ring_board[i + 8] == 0) 
		{
			ring_board[i + 8] = 1; chess_flag = 1; break;
		}
		else if ((i - 8) >= 0 && ring_board[i - 8] == 0) 
		{
			ring_board[i - 8] = 1;  chess_flag = 1; break;
		}

		if (q < 100)i = 0;
	}
	CB.changboard2();
}
//��ֹ�������ֿ������������
void computersite_5(int judge_num)
{

	CB.changboard1();
	for (int i = 0; i < 24; i++)
	{
		if (ring_board[i] == 0)
		{
			
			if (i % 2 == 0)
			{

				if (i != 0 && i != 8 && i != 16 && i != 6 && i != 14 && i != 22
					&& ((ring_board[i + 1] == judge_num && ring_board[i + 2] == 0)
						|| (ring_board[i + 2] == judge_num && ring_board[i + 1] == 0))
					&& ( i > 1 && ((ring_board[i - 1] == judge_num && ring_board[i - 2] == 0)
						|| (ring_board[i - 2] == judge_num && ring_board[i - 1] == 0))))
				{
					ring_board[i] = 1; chess_flag = 1; break;
				}
				else if ((i == 8 || i == 0 || i == 16)
					&& ((ring_board[i + 7] == judge_num && ring_board[i + 6] == 0)
						|| (ring_board[i + 6] == judge_num && ring_board[i + 7] == 0))
					&& ((ring_board[i + 1] == judge_num && ring_board[i + 2] == 0)
						|| (ring_board[i + 2] == judge_num && ring_board[i + 1] == 0)))
				{
					ring_board[i] = 1; chess_flag = 1; break;
				}
				else if ((i == 6 || i == 14 || i == 22)

					&& ((ring_board[i - 6] == judge_num && ring_board[i + 1] == 0)
						|| (ring_board[i + 1] == judge_num && ring_board[i - 6] == 0))

					&& ((ring_board[i - 1] == judge_num && ring_board[i - 2] == 0)
						|| (ring_board[i - 2] == judge_num && ring_board[i - 1] == 0)))
				{
					ring_board[i] = 1; chess_flag = 1; break;
				}
			}

			 if ((i > 7 && i < 16 && ((ring_board[i + 8] == judge_num && ring_board[i - 8] == 0)
				|| (ring_board[i - 8] == judge_num && ring_board[i + 8] == 0)))
				|| (i > 15 && i < 24 && ((ring_board[i - 16] == judge_num && ring_board[i - 8] == 0)
					|| ring_board[i - 8] == judge_num && ring_board[i - 16] == 0))
				|| (i >= 0 && i < 8 && ((ring_board[i + 16] == judge_num && ring_board[i + 8] == 0)
					|| ring_board[i + 8] == judge_num && ring_board[i + 16] == 0)))
			{

				if (i != 0 && i != 8 && i != 16 && i != 15 && i != 7 && i != 23 && i != 6 && i != 14 && i != 22)
				{
					if (i % 2 == 0)
					{
						if ((ring_board[i + 1] == judge_num && ring_board[i + 2] == 0)
							|| (ring_board[i + 2] == judge_num && ring_board[i + 1] == 0)
							|| (ring_board[i - 1] == judge_num && ring_board[i - 2] == 0)
							|| (ring_board[i - 2] == judge_num && ring_board[i - 1] == 0))
						{
							ring_board[i] = 1; chess_flag = 1; break;
						}
					}
				
					else if ((ring_board[i + 1] == judge_num && ring_board[i - 1] == 0)
							|| (ring_board[i - 1] == judge_num && ring_board[i + 1] == 0))
						{
							ring_board[i] = 1; chess_flag = 1; break;
						}
					
					}
				
				 else if ((i == 8 || i == 0 || i == 16)
					&& ((ring_board[i + 7] == judge_num && ring_board[i + 6] == 0
						|| ring_board[i + 1] == judge_num && ring_board[i + 2] == 0
						|| ring_board[i + 6] == judge_num && ring_board[i + 7] == 0
						|| ring_board[i + 2] == judge_num && ring_board[i + 1] == 0)))
				{
					ring_board[i] = 1; chess_flag = 1; break;
				}

				 else if ((i == 7 || i == 15 || i == 23)
					&& ((ring_board[i - 7] == judge_num && ring_board[i - 1] == 0)
						|| ring_board[i - 1] == judge_num && ring_board[i + 7] == 0))
				{
					ring_board[i] = 1; chess_flag = 1; break;
				}

				else if((i == 6 || i == 14 || i == 22)
					&& (ring_board[i - 6] == judge_num && ring_board[i + 1] == 0
						|| (ring_board[i - 2] == judge_num && ring_board[i - 1] == 0)
						|| (ring_board[i - 1] == judge_num && ring_board[i - 2] == 0)
						|| (ring_board[i + 1] == judge_num && ring_board[i - 6] == 0)))
				{
					ring_board[i] = 1; chess_flag = 1; break;
				}
			}
		}
	}
	CB.changboard2();
}

//�������庯��
void chessboard::computersite_3(chess* PPPchess, int PPPnum)
{
	int seat_flag = 0;//�жϵ����ĸ�λ�õı�־
	chess_flag = 0;//�Ƿ�����ı�־
	CB.changboard1();
	

	for (int i = 0; i < 24; i++)
	{
		seat_flag = 0;
		//Ѱ�����ӿ��������λ�ò����丳ֵΪ1
		if (ring_board[i] == 1)
		{
		
			for (int j = 0; j < 4; j++)
			{

				if (seat_flag == 0 && ((i != 7 && i!= 15 && i !=23 && ring_board[i + 1] == 0 && i + 1 >= 0) 
					|| ((i == 7 || i == 15 || i == 23) && ring_board[i - 7] == 0)))
				{
					if (i == 7 || i == 15 || i == 23)
					{
						ring_board[i - 7] = 1; ring_board[i] = 0; //��ԭ�����ӵ�λ�ø�0��
						seat_flag = 1; goto judge_;
					}
					else
					{
						ring_board[i + 1] = 1; ring_board[i] = 0;
						seat_flag = 1; goto judge_;
					}
				}
				else if ((seat_flag == 1 || seat_flag == 2) && (i + 8) < 24 && ring_board[i + 8] == 0)
				{
					ring_board[i + 8] = 1; ring_board[i] = 0; seat_flag = 2; goto judge_;
				}
				else if ((seat_flag == 2 || seat_flag == 1 || seat_flag == 0) &&
					(( i != 0 && i != 8 && i != 16 && i - 1 >= 0 && ring_board[i - 1] == 0) || ((i == 0 || i == 8 || i == 16) && ring_board[i + 7] == 0)))
				{
					if (i == 0 || i == 8 || i == 16)
					{
						ring_board[i + 7] = 0; ring_board[i] = 0;
						seat_flag = 1; goto judge_;
					}
					else
					{
						ring_board[i - 1] = 1; ring_board[i] = 0;
						seat_flag = 3; goto judge_;
					}
				}
				else if ((seat_flag != 4) && (i - 8) >= 0 && (ring_board[i - 8] == 0))
				{

					ring_board[i - 8] = 1; ring_board[i] = 0; seat_flag = 4; goto judge_;
				}
				else continue;
				//��ֵΪ1���ж��Ƿ��������
			judge_: CB.changboard2();
				CB.judge_line(0);
				if (T1 == true) 
				{
					chess_flag = 1;
					break;
				}
				//���޷������򽫸�����ԭλ�ü��ƶ�λ�ø�ԭ
				else
				{					
					if (seat_flag == 1) 
					{
						if (i == 7 || i == 15 || i == 23) ring_board[i - 7] = 0;
						else ring_board[i + 1] = 0;
						ring_board[i] = 1;
					}
					else if (seat_flag == 2) 
					{
						ring_board[i + 8] = 0; ring_board[i] = 1; 
					}
					else if (seat_flag == 3) 
					{
						if (i == 0 || i == 8 || i == 16) ring_board[i + 7] = 0;
						else ring_board[i - 1] = 0;
						ring_board[i] = 1;
					}
					else if (seat_flag == 4) 
					{
						ring_board[i - 8] = 0; ring_board[i] = 1; 
					}
					CB.changboard2();

				}
			}
		}
		if (chess_flag)  break; 
	}

	//����ƶ�һö����
	if (!chess_flag) {

		int exit_chess[12] = { 0 };//�洢���еĵ������ӣ��������ȡ����
		int t = 0;
		for (int p = 0; p < 24; p++) 
		{
			if (ring_board[p] == 1) 
			{
				exit_chess[t] = p;
				t++;
			}
		}
		int q = 0;//���ڼ���
		for (int i = 0; i < 24; i++)
		{
			seat_flag = 0;
			q++;
			int Rand;
			if (t == 0)Rand = 0;
			else Rand = rand() % t;
			if (q < 100) { i = exit_chess[Rand]; }
			cout << "rand=" << Rand <<endl<< "i=" << i << endl;
			for (int j = 0; j < 4; j++)
			{
				
				if (seat_flag == 0 && ((ring_board[i + 1] == 0 && i + 1 <= 0) || ((i == 7 || i == 15 || i == 23) && ring_board[i - 7] == 0))) 
				{
					if (i == 7 || i == 15 || i == 23) 
					{
						cout << "i-7=" << ring_board[i - 7] << endl;
						ring_board[i - 7] = 1; chess_flag = 1; break;
					}
					else 
					{
						cout << "i+1=" << ring_board[i + 1] << endl;
						ring_board[i + 1] = 1; chess_flag = 1; break;
					}

				}

				else if ((seat_flag == 1 || seat_flag == 0) && (i + 8) < 24 && ring_board[i + 8] == 0) 
				{
					cout << "i+8=" << ring_board[i + 8] << endl; ring_board[i + 8] = 1; chess_flag = 1; break;
				}
				else if ((seat_flag == 2 || seat_flag == 1 || seat_flag == 0) && ((i - 1 >= 0 && ring_board[i - 1] == 0) || ((i == 0 || i == 8 || i == 16 < 24) && ring_board[i + 7] == 0))) 
				{
					if (i == 0 || i == 8 || i == 16)
					{
						
						ring_board[i + 7] = 1; chess_flag = 1; break;
					}
					else 
					{
						cout << "i-1=" << ring_board[i - 1] << endl;
						ring_board[i - 1] = 1; chess_flag = 1; break;
					}

				}
				else if ((seat_flag != 4) && (i - 8) >= 0 && (ring_board[i - 8] == 0)) {
					cout << "i-8=" << ring_board[i - 8] << endl; ring_board[i - 8] = 1; chess_flag = 1; break;
				}
			}
			if (chess_flag == 1) 
			{
				ring_board[i] = 0;
				CB.changboard2();
				break;
			}
			if (q < 100)i = 0;
		}
	}
}
int game4()
{
	playerNum = 2;
	CB.clear();
	playerNum = 1;
	CB.clear();
	inchess_num = 6;
	exit_flag = 0;
	putimage(0, 0, &map2);
	
	while (1)
	{
		
		playerNum = 1;
		if (inchess_num == 12)
			play_music(play_change1);
		else if (time_ == 5)
			play_music(play_b1_5);
		else if (time_ == 10)
			play_music(play_b1_10);
		else if (time_ == 15)
			play_music(play_b1_15);
		

		Sleep(time_ * 1000);
		CB.clear();
		imageProcess(1);//����������12��������
		CB.setchessboard(V);  //����¼���Ӿ��õ�������
		CB.judge_layer(CB.Pchess);
		CB.update_game3();
		CB.judge_line(1);       //¼���ж��Ƿ�����
		CB.if_line();
		if (inchess_num == 12)CB.judge_walk(CB.PPchess, CB.PPnum);//��������������12ʱ�ж϶Է��ܷ�����
		CB.setprevious(); //����εõ������Ӵ�����
		if (exit_flag == 1)
		{
			putimage(0, 0, &win1);
			play_music(play_win1);
			Sleep(5000);
			break;
		}
		else if (exit_flag == 2)
		{
			putimage(0, 0, &win3);
			play_music(play_win3);
			break;
		}

		playerNum = 2;
		chess_flag = 0;
		
		if (inchess_num < 12)//����
		{
			//Ѱ����ҿ������������
			CB.computersite_4(-1); 
			//Ѱ�ҵ��Կ������������
			if (!chess_flag) {
				CB.computersite_4(1);
			}
		
			if (!chess_flag) 
			{
				computersite_5(-1);
			}
	
			if (!chess_flag) {
				computersite_5(1);
			}
		

			//������ŶԷ�����������
			if (!chess_flag) 
			{
				CB.computersite_2(CB.PPchess, CB.PPnum);
				
			}
		}
		else CB.computersite_3(CB.PPPchess, CB.PPPnum);//����
		CB.setchessboard_cpu();
		CB.judge_layer(CB.Pchess);
		CB.update_game3();
		if (inchess_num == 12)
			play_music(play_d12);
		else  play_music(play_c10);
		//play_music(play_c10);//���������
		Sleep(5000);
		CB.judge_line(1);       //¼���ж��Ƿ�����
		CB.if_line();
		CB.setchessboard_cpu();//��������ߴ���Pchess
		if (playerNum == 2 && inchess_num < 12)inchess_num++;
		if (inchess_num == 12)CB.judge_walk(CB.PPchess, CB.PPnum);//��������������12ʱ�ж϶Է��ܷ�����
		CB.setprevious(); //����εõ������Ӵ�����
		CB.setpprevious();//���������һ�ε�����
		if (exit_flag == 1)
		{
			putimage(0, 0, &win4);
			play_music(play_win4);
			Sleep(5000);
			break;
		}
		else if (exit_flag == 2)
		{
			putimage(0, 0, &win3);
			play_music(play_win3);
			break;
		}
	}
	return 0;
}

void chessboard::computersite_4(int judge_num)
{

CB.changboard1();
for (int i = 0; i < 24; i++)
{
	//ͬһȦ����
	if ((i % 2 != 0) && ring_board[i] == judge_num)//��ÿ���ߵ��м���жϣ��м��������ʱ
	{
		if (i != 7 && i != 15 && i != 23 && ring_board[i + 1] == judge_num && ring_board[i - 1] == 0)
		{
			ring_board[i - 1] = 1; chess_flag = 1; break;
		}
		else if ((i == 7 || i == 15 || i == 23) && ring_board[i - 7] == judge_num && ring_board[i - 1] == 0)
		{
			ring_board[i - 1] = 1; chess_flag = 1; break;
		}
		else if (i != 7 && i != 15 && i != 23 && ring_board[i - 1] == judge_num && ring_board[i + 1] == 0)
		{
			ring_board[i + 1] = 1; chess_flag = 1; break;
		}
		else if ((i == 7 || i == 15 || i == 23) && ring_board[i - 1] == judge_num && ring_board[i - 7] == 0)
		{
			ring_board[i - 1] = 1; chess_flag = 1; break;
		}
	}

	//ͬһȦ��� 
	 if ((i % 2 != 0) && ring_board[i] == 0) //�м��Ϊ��ʱ
	{
		if ((i != 7 && i != 15 && i != 23 && ring_board[i + 1] == judge_num && ring_board[i - 1] == judge_num)

			|| ((i == 7 || i == 15 || i == 23) && ring_board[i - 7] == judge_num && ring_board[i - 1] == judge_num))
		{
			ring_board[i] = 1; chess_flag = 1; break;
		}
	}

	//��ͬȦ����
	 if (i > 7 && i < 16 && ring_board[i] == judge_num)//���м�Ȧ�ж�
	{
		if (ring_board[i + 8] == judge_num && ring_board[i - 8] == 0)
		{
			ring_board[i - 8] = 1; chess_flag = 1; break;
		}
		else if (ring_board[i - 8] == judge_num && ring_board[i + 8] == 0)
		{
			ring_board[i + 8] = 1; chess_flag = 1; break;
		}
	}

	//��ͬȦ���
	 if (i > 7 && i < 16 && ring_board[i] == 0)//���м�Ȧ�ж�
	{
		if (ring_board[i + 8] == judge_num && ring_board[i - 8] == judge_num)
		{
			ring_board[i] = 1; chess_flag = 1; break;
		}
	}
}
CB.changboard2();
}
