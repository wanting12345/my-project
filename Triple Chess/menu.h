#pragma once
#ifndef MENU_H
#define MENU_H
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
//ÆåÅÌ¿í¶È¸ß¶È
#define Mapwideth 160*3			
#define MapHight  160*3

extern int flag;
extern int end_flag;
extern int time_;
void loadResource();
void begin();
void drawAlpha(IMAGE* picture, int  picture_x, int picture_y);
void ifhit6();
#endif 
