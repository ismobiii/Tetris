#pragma once
#include"Head.h"
#include"Block.h"
#include<conio.h>
#include<Windows.h>

//执行指令：
//(1)旋转指令
/*当触发了旋转指令以后，我们需要依次尝试该俄罗斯方块
的其他三种形状，如果出现了以下情况之一，就能说明这
样旋转后的放置是不合理的

俄罗斯方块的某个方块跨越左边界
俄罗斯方块的某个方块跨越右边界
俄罗斯方块的某个方块跨越下边界
俄罗斯方块的某个方块的位置在地图mp上已经存在方块
以下是校验函数：
*/
bool checkPut(int mp_x, int mp_y, int dir_idx)
{
	int sq_x[4];
	int sq_y[4];
	for (int i = 0; i < 4; i++) {
		sq_x[i] = mp_x + squares[now_s_idx].dir[dir_idx][i][0];
		sq_y[i] = mp_y + squares[now_s_idx].dir[dir_idx][i][1];
	}

	//[左右越界、下方越界、重复占格]
	for (int i = 0; i < 4; ++i) {
		if (sq_x[i] < 0 || sq_x[i] > 9 || sq_y[i] > 14)
			return false;
		if (sq_y[i] < 0)//检查坐标合法性
			continue;
		if (mp[sq_x[i]][sq_y[i]])
			return false;
	}
	return true;
}

void moveRotate()
{
	//尝试剩余所有形状，可以旋转即调整旋转状态
	for (int i = 1; i <= 3; i++) {
		if (checkPut(now_mp_x, now_mp_y, (now_d_idx + i) % 4))
		{
			Sleep(100);//让变化形状尽量慢一点
			now_d_idx = (now_d_idx + i) % 4;
			break;
		}
	}
}

//左移指令
void moveLeft()
{
	//尝试是否能左移
	Sleep(100);
	if (checkPut(now_mp_x - 1, now_mp_y, now_d_idx))
		--now_mp_x;
}

//右移指令
void moveRight()
{
	Sleep(100);
	//尝试是否能够右移
	if (checkPut(now_mp_x + 1, now_mp_y, now_d_idx))
		++now_mp_x;
}

//下移指令
//需求：
//提示可以开始下一个俄罗斯方块
//将当前俄罗斯方块记录到地图mp中
//进行消行
//判断游戏是否结束
void recordSquareNow()
{
	int sq_x[4];
	int sq_y[4];
	for (int i = 0; i < 4; i++) {
		sq_x[i] = now_mp_x + squares[now_s_idx].dir[now_d_idx][i][0];
		sq_y[i] = now_mp_y + squares[now_s_idx].dir[now_d_idx][i][1];
	}
	for (int i = 0; i < 4; ++i)
		if (sq_y[i] >= 0)
		{
			mp[sq_x[i]][sq_y[i]] = 1;
			mp_c[sq_x[i]][sq_y[i]] = colors[now_c_idx];
		}
}

//进行销行
void execClear()
{
	memset(mp_tmp, 0, sizeof(mp_tmp));
	memset(mp_c_tmp, 0, sizeof(mp_c_tmp));
	int cnt_j = 14;
	for (int j = 14; j >= 0; --j)
	{
		int cnt = 0;
		for (int i = 0; i < 10; ++i)
			if (mp[i][j])
				++cnt;
		if (cnt != 10)
		{
			for (int i = 0; i < 10; ++i)
			{
				mp_tmp[i][cnt_j] = mp[i][j];
				mp_c_tmp[i][cnt_j] = mp_c[i][j];
			}
			--cnt_j;
		}
		else
			++score;
	}
	for (int j = 0; j < 15; ++j)
		for (int i = 0; i < 10; ++i)
		{
			mp[i][j] = mp_tmp[i][j];
			mp_c[i][j] = mp_c_tmp[i][j];
		}
}

//判断游戏是否结束
bool checkOver()
{
	for (int i = 0; i < 10; i++)
	{
		if (mp[i][0]) {
			return true;
		}
	}
	return false;
}

//下移指令
void moveDown()
{
	// 尝试能否下移
	if (checkPut(now_mp_x, now_mp_y + 1, now_d_idx))
	{
		++now_mp_y;
		return;
	}
	Sleep(100);
	// 不能下移则说明这块方块“触礁”了，执行以下操作
	// 1、提示可以开始下一个方块
	// 2、将方块记录到map地图中
	// 3、判断是否可以消行
	// 4、判断消行后游戏是否结束
	flag_next = 1;
	recordSquareNow();
	execClear();
	if (checkOver())
		flag_over = 1;
}

//暂停游戏，直到下次敲空格键，游戏才继续
void movePause()
{
	while (true) {
		time_now = 0;
		MessageBox(0, L"游戏暂停\n按ENTER继续游戏", L"提示", MB_SETFOREGROUND);
		if (GetAsyncKeyState(VK_RETURN)) {
			break;
		}
	}
}

//开始游戏
int moveAction()
{
	while (true) {
		time_now = 0;
		if (GetAsyncKeyState(VK_RETURN)) {
			Sleep(100);
			return 1;
		}
	}
}

Cmd getCmd()
{
	while (true) {
		//指令超时
		DWORD time_tmp = GetTickCount();
		if (time_tmp - time_now >= 1000) {
			time_now = time_tmp;
			return Cmd_down;
		}

		//接受指针
		if (GetAsyncKeyState(VK_UP))
		{
			Sleep(50);
			return Cmd_rorate;
		}
		else if (GetAsyncKeyState(VK_LEFT)) {
			Sleep(50);
			return Cmd_left;
		}
		else if (GetAsyncKeyState(VK_RIGHT)) {
			Sleep(50);
			return Cmd_right;
		}
		else if (GetAsyncKeyState(VK_DOWN)) {
			Sleep(50);
			return Cmd_down;
		}
		else if (GetAsyncKeyState(VK_SPACE)) {
			Sleep(50);
			return Cmd_pause;
		}
	}
	//降低CPU的占用
	//Sleep(40);
}

void execCmd(Cmd cmd)
{
	switch (cmd)
	{
	case Cmd_down:
		moveDown();
		break;
	case Cmd_left:
		moveLeft();
		break;
	case Cmd_right:
		moveRight();
		break;
	case Cmd_rorate:
		moveRotate();
		break;
	case Cmd_pause:
		movePause();
		break;
	case Cmd_action:
		break;
	}
}