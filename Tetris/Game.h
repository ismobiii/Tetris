#pragma once
#include<ctime>
#include<fstream>
#include"Block.h"
#include"Game.h"
#include"Move.h"
#include"Picture.h"

/*
* ��ʼ������
��Ҫ����:�������á���ͼģʽ���á��������������
*/
void initEnvironment()
{
	// ��������
	initgraph(600, 540, 1);
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, L"����˹����");
	SetWindowPos(hwnd, HWND_TOP, 700, 20, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);

	// ��ͼģʽ����
	setbkmode(TRANSPARENT);

	// ���������
	srand(time(NULL));

	//��߷ֵĳ�ʼ��
	//initTopScore();
}

//ÿ�����Ϸ�ĳ�ʼ��
//��Ҫ����
//
//��յ�ͼmp�����Ӧ��ɫmp_c
//��ʼ����ʱ��������ʼ��Ҳ���ǿ���ֱ������ȥһ�񣬸о����Ǻ���Ҫ��
//�����ʼ����һ������˹����
//�����Ϸ״̬Ϊ��δ������
//���üƷ���
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
