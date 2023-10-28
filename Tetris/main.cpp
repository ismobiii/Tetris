#include<iostream>
#include"Head.h"
#include"Block.h"
#include"Game.h"
#include"Move.h"
#include"Picture.h"

using namespace std;

int main()
{
	//HWND hwnd = GetHWnd(); // ��ȡ��ͼ���ھ��
	//ShowWindow(hwnd, SW_HIDE); // ���ؿ���̨����

	int itemp = 0;
	initEnvironment();
	// ��ʼ��Ϸ
	while (true)
	{
		initDatasPerRound();
		while (!flag_over)
		{
			initDatasPerSquare();
			while (!flag_next)
			{
				BeginBatchDraw();
				drawGameBG();
				drawSide();
				drawMap();
				drawSquareNow();
				FlushBatchDraw();
				
				if (itemp == 0) {
					MessageBox(0, L"��ENTER����ʼ��Ϸ��", L"С��ʾ", MB_SETFOREGROUND);
					moveAction();//��һ����Ϸ��ʱ����Ҫ�Լ��ֶ�ѡ��ʼ��Ϸ
					itemp = 1;
				}
				Cmd cmd = getCmd();
				execCmd(cmd);//��������
			}//ÿһ���·��������
		}
		EndBatchDraw();
		// һ�ֽ������ͳ��
		swprintf(over_tips, 39, L"��Ϸ����\n������յ÷֣�%d\n�Ƿ������ھ֣�", score * 100);
		if (score > top_score)
			top_score = score;
		if (MessageBox(GetHWnd(), over_tips, L"�����ھ֣�", MB_ICONQUESTION | MB_YESNO) == IDNO)
			break;
	}//ÿ����Ϸ��ѭ��
	return 0;
}
