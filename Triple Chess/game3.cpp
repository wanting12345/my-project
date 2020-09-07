#include <iostream>
#include "game3.h"
#include<string>
#include "imageprocess.h"
#include<Windows.h>
#include"menu.h"
#include "imageprocess.h"
#include"music.h"
#include<time.h>
#include <windows.h>
#pragma comment (lib, "winmm.lib")  
#include <graphics.h>
#include <conio.h>

using namespace std;
int inchess_num = 0;

int& chess_num = mysum; //ÿ�δ�����������������Ҫ���Ӿ��õ�
int exit_flag = 0;
int V[7][7] = {0};
chessboard CB;
extern IMAGE map2, green, orange,win1,win2,win3;
bool T1 = false; //������ж��Ƿ������Ĳ�������
int V2[][7];

void chessboard::setchessboard(int V2[][7]) {
	int n = 0;
	if (playerNum == 1) Pname = "Player1";  //��������ָ�ֵ
	else Pname = "Player2";
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++) //������ȷ�������
		{
			if (V2[i][j] != 0 && Achess[i][j] == 0) {  //����ȷ�������λ��ֵ��Ϊ0���������Ӵ���ʱ����ֵ��Achess
				Achess[i][j] = V2[i][j];
				Pchess[n].x = i;  //���ѵ�ǰ�����괫��Pchess
				Pchess[n].y = j;
				n++;
			}
		}
	}
}

void chessboard::setprevious() {
	PPnum = chess_num;
	for (int i = 0; i < chess_num; i++)
	{
		PPchess[i] = Pchess[i];
	}
}

void chessboard::clear() {
	int a;
	if (playerNum == 1) a = -1; //�жϵ�ǰ��Ҷ�Ӧ-1����1
	else a = 1;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (Achess[i][j] == a) Achess[i][j] = 0; V[i][j] = 0;//����
		}
	}
}

void chessboard::judge_layer(chess* Pchess) {
	for (int i = 0; i < chess_num; i++) 
	{
		int x = Pchess[i].x, y = Pchess[i].y;
		if (x == 0 || x == 6 || y == 0 || y == 6) 
		{
			Pchess[i].layer = 1; Pchess[i].space = 3; }
		else if (((x == 1 || x == 5) && y > 0 && y < 6) || ((y == 1 || y == 5) && x > 0 && x < 6)) 
		{
			Pchess[i].layer = 2; Pchess[i].space = 2; 
		}
		else {
			Pchess[i].layer = 3; Pchess[i].space = 1; 
		}
	}

}

void chessboard::judge_line(int delete_flag) {
	T1 = false;

	//ÿ���ҵ������ͻ������λ�õ����Ӹ�Ϊ0
	//�ں�����Ѱ������
	for (int i = 0, j = 3; i < 3 && j > 0; i++, j--) {
		if (Achess[i][i] != 0 && Achess[i][i] == Achess[i][i + j] && Achess[i][i] == Achess[i][i + j + j])
		{
			if (delete_flag) 
			{
				Achess[i][i] = Achess[i][i + j] = Achess[i][i + j + j] = 0;
				V[i][i] = V[i][i + j] = V[i][i + j + j] = 0;
			}
			T1 = true;  goto judge;
		}
			if (Achess[6 - i][i] != 0 && Achess[6 - i][i] == Achess[6 - i][i + j] && Achess[6 - i][i] == Achess[6 - i][i + j + j])
			{
				if (delete_flag) 
				{
					Achess[6 - i][i] = Achess[6 - i][i + j] = Achess[6 - i][i + j + j] = 0;
					V[6 - i][i] = V[6 - i][i + j] = V[6 - i][i + j + j] = 0;
				}
				T1 = true;  goto judge;
			}
		
		//��������Ѱ������

		for (int i = 0, j = 3; i < 3 && j > 0; i++, j--) {
			if (Achess[i][i] != 0 && Achess[i][i] == Achess[i + j][i] && Achess[i][i] == Achess[i + j + j][i])
			{
				if (delete_flag) {
					Achess[i][i] = Achess[i + j][i] = Achess[i + j + j][i] = 0;
					V[i][i] = V[i + j][i] = V[i + j + j][i] = 0;
				}
				T1 = true;  goto judge;
			}
			if (Achess[i][6 - i] != 0 && Achess[i][6 - i] == Achess[i + j][6 - i] && Achess[i][6 - i] == Achess[i + j + j][6 - i])
			{
				if (delete_flag) {
					Achess[i][6 - i] = Achess[i + j][6 - i] = Achess[i + j + j][6 - i] = 0;
					V[i][6 - i] = V[i + j][6 - i] = V[i + j + j][6 - i] = 0;
				}
				T1 = true;  goto judge;
			}
		}
		//��ʣ�µ�б�ߺ�©����������������������Ѱ������
		if (Achess[0][0] != 0 && Achess[0][0] == Achess[1][1] && Achess[0][0] == Achess[2][2]) {
			if (delete_flag) { Achess[0][0] = Achess[1][1] = Achess[2][2] = 0; V[0][0] = V[1][1] = V[2][2] = 0; }
			T1 = true;   goto judge;
		}
		if (Achess[0][6] != 0 && Achess[0][6] == Achess[1][5] && Achess[0][6] == Achess[2][4]) {

			if (delete_flag) { Achess[0][6] = Achess[1][5] = Achess[2][4] = 0; V[0][6] = V[1][5] = V[2][4] = 0; }
			T1 = true; goto judge;
		}
		if (Achess[6][0] != 0 && Achess[6][0] == Achess[5][1] && Achess[6][0] == Achess[4][2]) {
			if (delete_flag) { Achess[6][0] = Achess[5][1] = Achess[4][2] = 0; V[6][0] = V[5][1] = V[4][2] = 0; }
			T1 = true; goto judge;
		}
		if (Achess[6][6] != 0 && Achess[6][6] == Achess[5][5] && Achess[6][6] == Achess[4][4]) {
			if (delete_flag) {
				Achess[6][6] = Achess[5][5] = Achess[4][4] = 0; V[6][6] = V[5][5] = V[4][4] = 0;
			}
			T1 = true;  goto judge;
		}
		if (Achess[0][3] != 0 && Achess[0][3] == Achess[1][3] && Achess[0][3] == Achess[2][3]) {
			if (delete_flag) { Achess[0][3] = Achess[1][3] = Achess[2][3] = 0; V[0][3] = V[1][3] = V[2][3] = 0; }
			T1 = true; goto judge;
		}
		if (Achess[4][3] != 0 && Achess[4][3] == Achess[5][3] && Achess[4][3] == Achess[6][3]) {
			if (delete_flag) { Achess[4][3] = Achess[5][3] = Achess[6][3] = 0; V[4][3] = V[5][3] = V[6][3] = 0; }
			T1 = true;  goto judge;
		}
		if (Achess[3][0] != 0 && Achess[3][0] == Achess[3][1] && Achess[3][0] == Achess[3][2]) {
			if (delete_flag) { Achess[3][0] = Achess[3][1] = Achess[3][2] = 0; V[3][0] = V[3][1] = V[3][2] = 0; }
			T1 = true;goto judge;
		}
		if (Achess[3][4] != 0 && Achess[3][4] == Achess[3][5] && Achess[3][4] == Achess[3][6]) {
			if (delete_flag) { Achess[3][6] = Achess[3][5] = Achess[3][4] = 0; V[3][6] = V[3][5] = V[3][4] = 0; }
			T1 = true;  goto judge;
		}
		//���ҵ�����������������ֻ������ʱ�����ʤ��
	judge: if (delete_flag) { 
		if (T1 == true && chess_num == 3 && (inchess_num == 12 || inchess_num == 11)) { 
			cout << Pname << " win!!!" << endl;  exit_flag = 1; cout << "����"<<endl;
		} 
	}

	}
}

//����ʱ�ж϶Է��Ƿ�Χס
void chessboard::judge_walk(chess* PPchess, int PPnum) {
	bool T2 = false;//������ж��ܷ�����Ĳ�������
	int xx, yy, s, l, xx1, yy1;
	cout << "PPnum="<<PPnum << endl;
	for (int i = 0; i < PPnum; i++)
	{
		
		//�Ȱ�Pchess�����ݴ������̵ֶı������Ͳ���д��ô�������
	    xx = PPchess[i].x, yy = PPchess[i].y, s = PPchess[i].space, l = PPchess[i].layer;
		if (xx < 3)xx1 = xx + s;
		else xx1 = xx - s;
		if (yy < 3) yy1 = yy + s;
		else yy1 = yy - s;
		cout << xx << yy << s << l << xx1 << yy1;

		//xx == 3 Ҳ�����м��һ��
		if (xx == 3) {
			if (l == 2 && (Achess[xx][yy - 1] == 0 || Achess[xx][yy + 1] == 0)) T2 = true;
			else {
				if (yy < 3 && Achess[3][1] == 0) T2 = true;
				else if (yy > 3 && Achess[3][5] == 0) T2 = true;
			}
			if (Achess[xx - s][yy] == 0 || Achess[xx + s][yy] == 0) T2 = true;
			if (T2 == true) { cout << "hh1" << endl; break; }
		}

		//yy == 3 Ҳ�����м��һ��
		 if (yy == 3) {
			if (l == 2 && (Achess[xx - 1][yy] == 0 || Achess[xx + 1][yy] == 0)) T2 = true;
			else {
				if (xx < 3 && Achess[1][3] == 0) T2 = true;
				else if (xx > 3 && Achess[5][3] == 0) T2 = true;
			}
			if (Achess[xx][yy - s] == 0 || Achess[xx][yy + s] == 0) T2 = true;
			if (T2 == true) { cout << "hh2" << endl; break; }
		}

		//xx == yy ��������б�Խ���
		 if (xx == yy) {
			if (l == 2) {
				if ((xx < 3) && (Achess[0][0] == 0 || Achess[2][2] == 0)) T2 = true;
				else if (xx > 3 && (Achess[4][4] == 0 || Achess[6][6] == 0)) T2 = true;
			}
			else {
				if (xx < 3 && Achess[1][1] == 0) T2 = true;
				else if (xx > 3 && Achess[5][5] == 0) T2 = true;
			}
			if (Achess[xx][yy1] == 0 || Achess[xx1][yy] == 0) T2 = true;
			if (T2 == true) { cout << "hh3" << endl; break; }
		}
		
		//xx+yy == 6���� ����б�Խ���
		 if (xx + yy == 6) {
			if (l == 2) {
				if (xx < 3 && (Achess[0][6] == 0 || Achess[2][4] == 0)) T2 = true;
				else if (xx > 3 && (Achess[6][0] == 0 || Achess[4][2] == 0)) T2 = true;
			}
			else {
				if (xx < 3 && Achess[1][5] == 0) T2 = true;
				else if (xx > 3 && Achess[5][1] == 0) T2 = true;
			}
			
			
			if (Achess[xx][yy1] == 0 || Achess[xx1][yy] == 0) T2 = true;
			if (T2 == true) { cout << "hh4" << endl; break; }
		}

		//�������м������
		 if (l == 3)
		{
			if (xx == 3)
			{
				if (Achess[xx + 1][yy] == 0 || Achess[xx - 1][yy] == 0)T2 = true;
			}
			else if (yy == 3)
			{
				if (Achess[xx ][yy + 1] == 0 || Achess[xx ][yy - 1] == 0)T2 = true;
			}
			if (T2 == true) { cout << "hh5" << endl; break; }

		}
	
	}

		//�Է�����������壬���Է�������Ϊ12ʱ��ƽ�֣�������С��12����Է���
		if (T2 == false) {
			if (PPnum == 12) {
				cout << "Tied" << endl; exit_flag = 2;
			}
			else {
				cout << Pname << " win!!!" << endl;
				exit_flag = 1; cout << "Χס" << endl;
			}
			
	}
}

void chessboard::update_game3()
{
	putimage(0, 0, &map2);
	Sleep(100);
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
			if (Achess[i][j] == 1)
				drawAlpha(&orange, (40+j * (420 / 7)), (40+i * (420 / 7)));
			else if (Achess[i][j] == -1)
				drawAlpha(&green, (40+j * (420 / 7)), (40+i * (420 / 7)));
	}
}
void chessboard::if_line()
{
	if (T1 == true)
	{
		if (playerNum == 2)
		{
			if (flag == 3) {
				play_music(play_delete2);
				Sleep(5 * 1000);
			}
			else {
				play_music(play_delete3);
				Sleep(2 * 1000);
			}
		}
		else {
			play_music(play_delete1);
			Sleep(5 * 1000);
		}
		CB.update_game3();
		imageProcess(playerNum);
	}
}
	int game3()
	{
		playerNum = 2;
		CB.clear(); 
		playerNum = 1;
		CB.clear();
		inchess_num =0 ;
		
		exit_flag = 0;
		initgraph(480, 480, SHOWCONSOLE);
		putimage(0, 0, &map2);
		
		while (1)
		{
			
			cout << T1 << endl;
			cout << inchess_num << exit_flag<<endl;
			playerNum = 1;
			if (inchess_num == 12) play_music( play_change1); 
			else if (time_ == 5) {
				play_music(play_b1_5);
			}
			else if (time_ == 10) {
				play_music(play_b1_10);
			}
			else if (time_ == 15) {
				play_music(play_b1_15);
			}
			Sleep( time_*1000);

			if (inchess_num == 12)CB.clear();
			imageProcess(1);//����������12��������
			CB.setchessboard(V);  //����¼���Ӿ��õ�������
			CB.judge_layer(CB.Pchess);
			CB.update_game3();
			CB.judge_line(1);       //¼���ж��Ƿ�����
			CB.if_line();
			if (inchess_num == 12)CB.judge_walk(CB.PPchess, CB.PPnum);//��������������12ʱ�ж϶Է��ܷ�����
			if (inchess_num >= 11)CB.setprevious(); //����εõ������Ӵ�����
			if (exit_flag == 1)
			{
				putimage(0, 0, &win1);
				play_music(play_win1); Sleep(20000);
				break;
			}
			else if (exit_flag == 2)
			{
				putimage(0, 0, &win3);
				play_music(play_win3);
				break;
			}
			playerNum = 2;

			if (inchess_num == 12)play_music(play_change2);
			else if (time_ == 5) {
				play_music(play_b2_5);
			}
			else if (time_ == 10) {
				play_music(play_b2_10);
			}
			else if (time_ == 15) {
				play_music(play_b2_15);
			}
			Sleep(time_ * 1000);
			if (inchess_num == 12)CB.clear(); //����������12��������
			imageProcess(2);
			CB.setchessboard(V);  //����¼���Ӿ��õ�������
			CB.judge_layer(CB.Pchess);
			CB.update_game3();
			CB.judge_line(1);       //¼���ж��Ƿ�����
			CB.if_line();
			if (playerNum == 2 && inchess_num < 12)inchess_num++;
			if (inchess_num == 12)CB.judge_walk(CB.PPchess, CB.PPnum);//��������������12ʱ�ж϶Է��ܷ�����
			if (inchess_num == 12)CB.setprevious(); //����εõ������Ӵ�����
			if (exit_flag == 1)
			{
				putimage(0, 0, &win2);
				CB.clear();
				play_music(play_win2);
				Sleep(5000);
				break;
			}
			else if (exit_flag == 2)
			{
				putimage(0, 0, &win3);
				play_music(play_win3); Sleep(5000);
				break;
			}
		}

		
		return 0;
	}




