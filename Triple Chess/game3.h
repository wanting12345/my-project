using namespace std;
#pragma once
#ifndef DASANQI_H
#define DASANQI_H
#endif


extern int playerNum;

extern int& chess_num;//当前玩家在棋盘上的棋子数

extern bool T1;//判断是否三连的变量

extern int inchess_num;//玩家已下回合

extern int exit_flag;//判断输赢

//计数器，计算单个玩家下过的棋子数，每回合都+1，加到12就停，等于12时才判断能否走棋和判断是否需要清棋盘
extern int V[7][7];
//定义棋子类
class chess {
public:
	int x, y; //棋子坐标
	int layer;//棋子的层数
	int space;//这层棋子相邻的间隔
};

//定义棋盘类，继承了棋子类
class chessboard : public chess {
private:
	int Achess[7][7] = {};//棋盘上两个玩家棋子的坐标，对应-1和1，就是all chess
	string Pname; // 玩家的名字，也就是玩家1和玩家2，true时为玩家1，就是player name
public:
	chess Pchess[12];//每次传入的玩家的所有棋子的坐标，就是player chess
	chess PPchess[12] = {};//上个玩家所有棋子的坐标，就是previous player chess
	chess PPPchess[12];
	int PPnum = 0;//上个玩家的棋子数
	int PPPnum = 0;

	chessboard() {}; //空的棋盘类对象的构造函数

	void setchessboard(int V2[][7]); //对棋盘初始化，V2是精确后的坐标数组

	void setchessboard_cpu();

	void judge_layer(chess*);//判断棋子的层数

	void judge_line(int flag);//判断棋盘上是否三连

	void clear();//在棋子数达到12时，每次录入坐标前先清除该玩家的上次坐标，避免走棋时棋子数超过12

	void judge_walk(chess* PPchess, int PPnum);//判断对方能不能走棋

	void setprevious();//自己下完后，把棋存起来

	void setpprevious();//保存电脑上次的棋子

	void update_game3();//更新棋盘

	void if_line();//出现三连时的提醒收起棋子

	void changboard1();//棋子坐标转换为一维数组

	void changboard2();//棋子坐标转换回二维数组

	//电脑下棋时判断玩家或电脑有没有可以三连的情况,形参为-1时判断对象为玩家，否则为电脑
	void computersite_1(chess* PPchess, int PPnum, chess* PPPchess, int PPPnum, int judge_num);

	//没有可以三连情况时，电脑随机靠着玩家的棋子下棋
	void computersite_2(chess* PPchess, int PPnum);

	//走棋阶段，用于电脑移动一枚棋子
	void computersite_3(chess* PPPchess, int PPPnum);
	void computersite_4(int judge_num);

};
int game3(void);
int game4(void);
