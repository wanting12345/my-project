using namespace std;
#pragma once
#ifndef DASANQI_H
#define DASANQI_H
#endif


extern int playerNum;

extern int& chess_num;//��ǰ����������ϵ�������

extern bool T1;//�ж��Ƿ������ı���

extern int inchess_num;//������»غ�

extern int exit_flag;//�ж���Ӯ

//�����������㵥������¹�����������ÿ�غ϶�+1���ӵ�12��ͣ������12ʱ���ж��ܷ�������ж��Ƿ���Ҫ������
extern int V[7][7];
//����������
class chess {
public:
	int x, y; //��������
	int layer;//���ӵĲ���
	int space;//����������ڵļ��
};

//���������࣬�̳���������
class chessboard : public chess {
private:
	int Achess[7][7] = {};//����������������ӵ����꣬��Ӧ-1��1������all chess
	string Pname; // ��ҵ����֣�Ҳ�������1�����2��trueʱΪ���1������player name
public:
	chess Pchess[12];//ÿ�δ������ҵ��������ӵ����꣬����player chess
	chess PPchess[12] = {};//�ϸ�����������ӵ����꣬����previous player chess
	chess PPPchess[12];
	int PPnum = 0;//�ϸ���ҵ�������
	int PPPnum = 0;

	chessboard() {}; //�յ����������Ĺ��캯��

	void setchessboard(int V2[][7]); //�����̳�ʼ����V2�Ǿ�ȷ�����������

	void setchessboard_cpu();

	void judge_layer(chess*);//�ж����ӵĲ���

	void judge_line(int flag);//�ж��������Ƿ�����

	void clear();//���������ﵽ12ʱ��ÿ��¼������ǰ���������ҵ��ϴ����꣬��������ʱ����������12

	void judge_walk(chess* PPchess, int PPnum);//�ж϶Է��ܲ�������

	void setprevious();//�Լ�����󣬰��������

	void setpprevious();//��������ϴε�����

	void update_game3();//��������

	void if_line();//��������ʱ��������������

	void changboard1();//��������ת��Ϊһά����

	void changboard2();//��������ת���ض�ά����

	//��������ʱ�ж���һ������û�п������������,�β�Ϊ-1ʱ�ж϶���Ϊ��ң�����Ϊ����
	void computersite_1(chess* PPchess, int PPnum, chess* PPPchess, int PPPnum, int judge_num);

	//û�п����������ʱ���������������ҵ���������
	void computersite_2(chess* PPchess, int PPnum);

	//����׶Σ����ڵ����ƶ�һö����
	void computersite_3(chess* PPPchess, int PPPnum);
	void computersite_4(int judge_num);

};
int game3(void);
int game4(void);
