#pragma once
#include"Head.h"
#include"Block.h"
#include<conio.h>
#include<Windows.h>

//ִ��ָ�
//(1)��תָ��
/*����������תָ���Ժ�������Ҫ���γ��Ըö���˹����
������������״������������������֮һ������˵����
����ת��ķ����ǲ������

����˹�����ĳ�������Խ��߽�
����˹�����ĳ�������Խ�ұ߽�
����˹�����ĳ�������Խ�±߽�
����˹�����ĳ�������λ���ڵ�ͼmp���Ѿ����ڷ���
������У�麯����
*/
bool checkPut(int mp_x, int mp_y, int dir_idx)
{
	int sq_x[4];
	int sq_y[4];
	for (int i = 0; i < 4; i++) {
		sq_x[i] = mp_x + squares[now_s_idx].dir[dir_idx][i][0];
		sq_y[i] = mp_y + squares[now_s_idx].dir[dir_idx][i][1];
	}

	//[����Խ�硢�·�Խ�硢�ظ�ռ��]
	for (int i = 0; i < 4; ++i) {
		if (sq_x[i] < 0 || sq_x[i] > 9 || sq_y[i] > 14)
			return false;
		if (sq_y[i] < 0)//�������Ϸ���
			continue;
		if (mp[sq_x[i]][sq_y[i]])
			return false;
	}
	return true;
}

void moveRotate()
{
	//����ʣ��������״��������ת��������ת״̬
	for (int i = 1; i <= 3; i++) {
		if (checkPut(now_mp_x, now_mp_y, (now_d_idx + i) % 4))
		{
			Sleep(100);//�ñ仯��״������һ��
			now_d_idx = (now_d_idx + i) % 4;
			break;
		}
	}
}

//����ָ��
void moveLeft()
{
	//�����Ƿ�������
	Sleep(100);
	if (checkPut(now_mp_x - 1, now_mp_y, now_d_idx))
		--now_mp_x;
}

//����ָ��
void moveRight()
{
	Sleep(100);
	//�����Ƿ��ܹ�����
	if (checkPut(now_mp_x + 1, now_mp_y, now_d_idx))
		++now_mp_x;
}

//����ָ��
//����
//��ʾ���Կ�ʼ��һ������˹����
//����ǰ����˹�����¼����ͼmp��
//��������
//�ж���Ϸ�Ƿ����
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

//��������
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

//�ж���Ϸ�Ƿ����
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

//����ָ��
void moveDown()
{
	// �����ܷ�����
	if (checkPut(now_mp_x, now_mp_y + 1, now_d_idx))
	{
		++now_mp_y;
		return;
	}
	Sleep(100);
	// ����������˵����鷽�顰�������ˣ�ִ�����²���
	// 1����ʾ���Կ�ʼ��һ������
	// 2���������¼��map��ͼ��
	// 3���ж��Ƿ��������
	// 4���ж����к���Ϸ�Ƿ����
	flag_next = 1;
	recordSquareNow();
	execClear();
	if (checkOver())
		flag_over = 1;
}

//��ͣ��Ϸ��ֱ���´��ÿո������Ϸ�ż���
void movePause()
{
	while (true) {
		time_now = 0;
		MessageBox(0, L"��Ϸ��ͣ\n��ENTER������Ϸ", L"��ʾ", MB_SETFOREGROUND);
		if (GetAsyncKeyState(VK_RETURN)) {
			break;
		}
	}
}

//��ʼ��Ϸ
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
		//ָ�ʱ
		DWORD time_tmp = GetTickCount();
		if (time_tmp - time_now >= 1000) {
			time_now = time_tmp;
			return Cmd_down;
		}

		//����ָ��
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
	//����CPU��ռ��
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