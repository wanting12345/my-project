#include <windows.h>
#pragma comment (lib, "winmm.lib")  
#include <iostream>
#include "music.h"

void play_music(int a)
{
	switch (a)
	{
	case play_a1:mciSendString(TEXT("open 欢迎来到快乐三连.wav alias a1"), NULL, 0, NULL);
		mciSendString(TEXT("play a1 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close a1"), NULL, 0, NULL);
		break;
	case play_a2:mciSendString(TEXT("open 请选择玩家下棋的间隔.wav alias a2"), NULL, 0, NULL);
		mciSendString(TEXT("play a2 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close a2"), NULL, 0, NULL);
		break;
	case play_a3:mciSendString(TEXT("open 请选择游戏种类.wav alias a3"), NULL, 0, NULL);
		mciSendString(TEXT("play a3 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close a3"), NULL, 0, NULL);
		break;
	case play_b1_5: mciSendString(TEXT("open 请玩家一下棋_您有5秒时间.wav alias b1_5"), NULL, 0, NULL);
		mciSendString(TEXT("play b1_5 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close b1_5"), NULL, 0, NULL);
		break;
	case play_b1_10:mciSendString(TEXT("open 请玩家一下棋_您有10秒时间.wav alias b1_10"), NULL, 0, NULL);
		mciSendString(TEXT("play b1_10 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close b1_10"), NULL, 0, NULL);
		break;
	case play_b1_15:mciSendString(TEXT("open 请玩家一下棋_您有15秒时间.wav alias b1_15"), NULL, 0, NULL);
		mciSendString(TEXT("play b1_15 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close b1_15"), NULL, 0, NULL);
		break;
	case play_b2_5:mciSendString(TEXT("open 请玩家二下棋_您有5秒时间.wav alias b2_5"), NULL, 0, NULL);
		mciSendString(TEXT("play b2_5 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close b2_5"), NULL, 0, NULL);
		break;
	case play_b2_10:mciSendString(TEXT("open 请玩家二下棋_您有10秒时间.wav alias b2_10"), NULL, 0, NULL);
		mciSendString(TEXT("play b2_10 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close b2_10"), NULL, 0, NULL);
		break;
	case play_b2_15:mciSendString(TEXT("open 请玩家二下棋_您有15秒时间.wav alias b2_15"), NULL, 0, NULL);
		mciSendString(TEXT("play b2_15 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close b2_15"), NULL, 0, NULL);
		break;
	case play_win1: mciSendString(TEXT("open 恭喜玩家一赢得游戏.wav alias win1"), NULL, 0, NULL);
		mciSendString(TEXT("play win1 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close win1"), NULL, 0, NULL);
		break;
	case play_win2: mciSendString(TEXT("open 恭喜玩家二赢得游戏.wav alias b1_10"), NULL, 0, NULL);
		mciSendString(TEXT("play b1_10 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close b1_10"), NULL, 0, NULL);
		break;
	case play_win3: mciSendString(TEXT("open 真棒！打成平局了耶！.wav alias win3"), NULL, 0, NULL);
		mciSendString(TEXT("play win3 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close win3"), NULL, 0, NULL);
		break;
	case play_win4: mciSendString(TEXT("open 恭喜电脑赢得胜利.wav alias win4"), NULL, 0, NULL);
		mciSendString(TEXT("play win4 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close win4"), NULL, 0, NULL);
		break;
	case play_c1:mciSendString(TEXT("open 请帮帮电脑把棋子下在位置1.wav alias c1"), NULL, 0, NULL);
		mciSendString(TEXT("play c1 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close c1"), NULL, 0, NULL);
		break;
	case play_c2:mciSendString(TEXT("open 请帮帮电脑把棋子下在位置2.wav alias c2"), NULL, 0, NULL);
		mciSendString(TEXT("play c2 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close c2"), NULL, 0, NULL);
		break;
	case play_c3:mciSendString(TEXT("open 请帮帮电脑把棋子下在位置3.wav alias c3"), NULL, 0, NULL);
		mciSendString(TEXT("play c3 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close c3"), NULL, 0, NULL);
		break;
	case play_c4:mciSendString(TEXT("open 请帮帮电脑把棋子下在位置4.wav alias c4"), NULL, 0, NULL);
		mciSendString(TEXT("play c4 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close c4"), NULL, 0, NULL);
		break;
	case play_c5:mciSendString(TEXT("open 请帮帮电脑把棋子下在位置5.wav alias c5"), NULL, 0, NULL);
		mciSendString(TEXT("play c5 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close c5"), NULL, 0, NULL);
		break;
	case play_c6:mciSendString(TEXT("open 请帮帮电脑把棋子下在位置6.wav alias c6"), NULL, 0, NULL);
		mciSendString(TEXT("play c6 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close c6"), NULL, 0, NULL);
		break;
	case play_c7:mciSendString(TEXT("open 请帮帮电脑把棋子下在位置7.wav alias c7"), NULL, 0, NULL);
		mciSendString(TEXT("play c7 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close c7"), NULL, 0, NULL);
		break;
	case play_c8:mciSendString(TEXT("open 请帮帮电脑把棋子下在位置8.wav alias c8"), NULL, 0, NULL);
		mciSendString(TEXT("play c8 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close c8"), NULL, 0, NULL);
		break;
	case play_c9:mciSendString(TEXT("open 请帮帮电脑把棋子下在位置9.wav alias c9"), NULL, 0, NULL);
		mciSendString(TEXT("play c9 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close c9"), NULL, 0, NULL);
		break;
	case play_c10:mciSendString(TEXT("open 请帮电脑下棋.wav alias c9"), NULL, 0, NULL);
		mciSendString(TEXT("play c9 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close c9"), NULL, 0, NULL);
		break;
	case play_d12:mciSendString(TEXT("open 请帮电脑移动棋子.wav alias c9"), NULL, 0, NULL);
		mciSendString(TEXT("play c9 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close c9"), NULL, 0, NULL);
		break;
	case play_change1:mciSendString(TEXT("open 请玩家一移动一枚棋子.wav alias change_1"), NULL, 0, NULL);
		mciSendString(TEXT("play change_1 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close change_1"), NULL, 0, NULL);
		break;
	case play_change2:mciSendString(TEXT("open 请玩家二移动一枚棋子.wav alias change_2"), NULL, 0, NULL);
		mciSendString(TEXT("play change_2 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close change_2"), NULL, 0, NULL);
		break;
	case play_delete1:mciSendString(TEXT("open 请玩家一收起三连的棋子.wav alias delete_1"), NULL, 0, NULL);
		mciSendString(TEXT("play delete_1 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close delete_1"), NULL, 0, NULL);
		break;
	case play_delete2:mciSendString(TEXT("open 请玩家二收起三连的棋子.wav alias delete_2"), NULL, 0, NULL);
		mciSendString(TEXT("play delete_2 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close delete_2"), NULL, 0, NULL);
		break;
	case play_delete3:mciSendString(TEXT("open 电脑三连啦.wav alias delete_1"), NULL, 0, NULL);
		mciSendString(TEXT("play delete_1 wait"), NULL, 0, NULL);
		mciSendString(TEXT("close delete_1"), NULL, 0, NULL);
		break;

	default:
		break;
	}
}

