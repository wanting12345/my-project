#include <iostream>
#include <string>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>
#include<imgproc/imgproc.hpp>
#include<math.h>

using namespace std;
using namespace cv;

int main()
{
	int num;//最终获取的数字
	//设置HSV范围
	int iLowH = 11;
	int iHighH = 30;

	int iLowS = 43;
	int iHighS = 255;

	int iLowV = 46;
	int iHighV = 255;
	//设帧宽、高
	int width = 600;
	int height = 400;

	while (true)
	{
		VideoCapture capture(0);

		//设置读入视频的像素尺寸
		capture.set(CAP_PROP_FRAME_WIDTH,width); //宽度 
		capture.set(CAP_PROP_FRAME_HEIGHT, height); //高度
		while (1)
		{
			Mat frame;
			capture >> frame;
			//转为二值图像
			Mat imgHSV;
			cvtColor(frame, imgHSV, COLOR_BGR2HSV);
			//HSV范围内的区域转为二值图像
			Mat erzhi;
			inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), erzhi);
			//开操作 
			Mat element = getStructuringElement(MORPH_RECT, Size(7, 7));
			morphologyEx(erzhi, erzhi, MORPH_OPEN, element);
			//闭操作 
			morphologyEx(erzhi, erzhi, MORPH_CLOSE, element);
			namedWindow("读取视频", WINDOW_NORMAL);
			resizeWindow("读取视频", width, height);
			imshow("读取视频", frame);
			//寻找最外层轮廓  
			vector<vector<Point>> contours;
			vector<Vec4i> hierarchy;
			findContours(erzhi, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);

			for (int i = 0; i < contours.size(); i++)
			{
				if (contourArea(contours[i]) < 80)//面积太小忽略			
					continue;
				//寻找最小外接矩形
				RotatedRect rect = minAreaRect(contours[i]);

				Point2f P[4];
				rect.points(P);
				//获取重心坐标
				int x = (P[0] + P[2]).x / 2;
				int y = (P[0] + P[2]).y / 2;
				//排序
				//将画面分为九个部分
				int standardx = width / 3;
				int standardy = height / 3;
				if (x < standardx)
				{
					num = 1;	
					}
					else if (x > standardx && x < (2 * standardx))
					{
						num = 2;
						}
						else
						{
							num = 3;
							}

				if (y < standardy)
				{
					num = num;
					}
					else if (y > standardy && y < (2 * standardy))
					{
						num = num + 3;
						}	
						else
						{
							num = num + 6;
							}


			//	cout << num << "\n";
				waitKey(200);		//延时30ms
				
				}
			}


		}


		
		
	}


