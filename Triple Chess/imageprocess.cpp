#include <iostream>
#include <windows.h>
#include<opencv2/opencv.hpp>
#include "imageprocess.h"
#include "game1.h"
#include "game3.h"
#include "menu.h"
using namespace std;
using namespace cv;

Mat hsv;
Mat temp;
int tmp;
int chess_x[14];
int chess_y[14];
int mysum;//当前玩家的棋子数

void imageProcess(int playerNum)
{
	VideoCapture capture(0);//循环显示每一帧
	Mat src;//定义一个Mat变量，用于存储每一帧的图像
	capture >> src;  //读取当前帧

	//RGB转化为hsv图像，方便下一步提取指定颜色
	cvtColor(src, hsv, COLOR_BGR2HSV); 

	//定义一个选择函数，一种颜色对应一个hsv范围，对该范围内的区域二值化
	if (playerNum==1)
		inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), temp);//绿
	else
		inRange(hsv, Scalar(100, 43, 46), Scalar(124, 255, 255), temp);//蓝

	//开操作，除噪点
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	morphologyEx(temp, temp, MORPH_OPEN, element);


	//对得到的二值化图像进行边缘检测
	Canny(temp, temp, 20, 80, 3, false);

	std::vector<std::vector<Point>> contours;
	std::vector<Vec4i> hierarchy;
	
	//寻找轮廓
	findContours(temp, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE, Point(0, 0));

	//计算轮廓矩  
	vector<Moments> mu(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i], false);
	}
	//计算轮廓中心
	vector<Point2i>  mc(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mc[i] = Point2i(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
	}
	//绘制轮廓标定形心
	Mat drawing = Mat::zeros(temp.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		//将轮廓绘制到原图上
		drawContours(src, contours, i, color, 3, 8, hierarchy, 0, Point(0, 0));
		//标定形心
		circle(src, mc[i], 2, Scalar(0, 0, 0), -1, 6, 0);     
	}
	if ((flag!=3)&&(flag != 4))
	{
		for (int i = 0; i < contours.size(); i++)//确定棋子位置
		{
			int a = (double)mc[i].x / src.cols * 3;//图像的长
			int b = (double)mc[i].y / src.rows * 3;//图像的宽
			Board[b][a] = (playerNum == 1) ? 1 : -1;
			cout << "Board[" << b + 1 << "][" << a + 1 << "] " << endl;
		}
	}
	else 
	{
		for (int i = 0; i < contours.size(); i++)//确定棋子位置
		{
			int a = (double)mc[i].x / src.cols * 7;//图像的长
			int b = (double)mc[i].y / src.rows * 7;//图像的宽
			V[b][a] =((playerNum == 1) ? -1 : 1);//游戏3的玩家1对应的棋子是-1，玩家2是1
			cout << "V[" << b + 1 << "][" << a + 1 << "] " << endl;
		}
	}
	mysum = int(contours.size() );//game3 需要用到当前的棋子数
	namedWindow("output", WINDOW_AUTOSIZE);
	imshow("output", src);
	cout << "当前色块有" << mysum << "个" << endl;
	cout <<endl;
	waitKey(30);
}
