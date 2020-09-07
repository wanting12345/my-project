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
int mysum;//��ǰ��ҵ�������

void imageProcess(int playerNum)
{
	VideoCapture capture(0);//ѭ����ʾÿһ֡
	Mat src;//����һ��Mat���������ڴ洢ÿһ֡��ͼ��
	capture >> src;  //��ȡ��ǰ֡

	//RGBת��Ϊhsvͼ�񣬷�����һ����ȡָ����ɫ
	cvtColor(src, hsv, COLOR_BGR2HSV); 

	//����һ��ѡ������һ����ɫ��Ӧһ��hsv��Χ���Ը÷�Χ�ڵ������ֵ��
	if (playerNum==1)
		inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), temp);//��
	else
		inRange(hsv, Scalar(100, 43, 46), Scalar(124, 255, 255), temp);//��

	//�������������
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	morphologyEx(temp, temp, MORPH_OPEN, element);


	//�Եõ��Ķ�ֵ��ͼ����б�Ե���
	Canny(temp, temp, 20, 80, 3, false);

	std::vector<std::vector<Point>> contours;
	std::vector<Vec4i> hierarchy;
	
	//Ѱ������
	findContours(temp, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE, Point(0, 0));

	//����������  
	vector<Moments> mu(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i], false);
	}
	//������������
	vector<Point2i>  mc(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mc[i] = Point2i(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
	}
	//���������궨����
	Mat drawing = Mat::zeros(temp.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		//���������Ƶ�ԭͼ��
		drawContours(src, contours, i, color, 3, 8, hierarchy, 0, Point(0, 0));
		//�궨����
		circle(src, mc[i], 2, Scalar(0, 0, 0), -1, 6, 0);     
	}
	if ((flag!=3)&&(flag != 4))
	{
		for (int i = 0; i < contours.size(); i++)//ȷ������λ��
		{
			int a = (double)mc[i].x / src.cols * 3;//ͼ��ĳ�
			int b = (double)mc[i].y / src.rows * 3;//ͼ��Ŀ�
			Board[b][a] = (playerNum == 1) ? 1 : -1;
			cout << "Board[" << b + 1 << "][" << a + 1 << "] " << endl;
		}
	}
	else 
	{
		for (int i = 0; i < contours.size(); i++)//ȷ������λ��
		{
			int a = (double)mc[i].x / src.cols * 7;//ͼ��ĳ�
			int b = (double)mc[i].y / src.rows * 7;//ͼ��Ŀ�
			V[b][a] =((playerNum == 1) ? -1 : 1);//��Ϸ3�����1��Ӧ��������-1�����2��1
			cout << "V[" << b + 1 << "][" << a + 1 << "] " << endl;
		}
	}
	mysum = int(contours.size() );//game3 ��Ҫ�õ���ǰ��������
	namedWindow("output", WINDOW_AUTOSIZE);
	imshow("output", src);
	cout << "��ǰɫ����" << mysum << "��" << endl;
	cout <<endl;
	waitKey(30);
}
