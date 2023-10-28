#pragma once
#include<ctime>
#include<fstream>
#include"Block.h"
#include"Game.h"
#include"Move.h"
#include"Picture.h"

/*
* 初始化环境
主要包括:窗口设置、绘图模式设置、随机数种子设置
*/
void initEnvironment()
{
	// 窗口设置
	initgraph(600, 540, 1);
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, L"俄罗斯方块");
	SetWindowPos(hwnd, HWND_TOP, 700, 20, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);

	// 绘图模式设置
	setbkmode(TRANSPARENT);

	// 随机数种子
	srand(time(NULL));

	//最高分的初始化
	//initTopScore();
}

//每大局游戏的初始化
//主要包括
//
//清空地图mp与其对应颜色mp_c
//初始化计时器（不初始化也就是开局直接落下去一格，感觉不是很重要）
//随机初始化下一个俄罗斯方块
//标记游戏状态为“未结束”
//重置计分器
void initDatasPerRound()
{
	memset(mp, 0, sizeof(mp));
	memset(mp, 0, sizeof(mp_c));
	time_now = GetTickCount();
	next_c_idx = rand() % 7;
	next_s_idx = rand() % 7;
	next_d_idx = rand() % 4;
	flag_over = 0;
	score = 0;
	//top_score = 0;
}
