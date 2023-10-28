#include<iostream>
#include"Head.h"
#include"Block.h"
#include"Game.h"
#include"Move.h"
#include"Picture.h"

using namespace std;

int main()
{
	//HWND hwnd = GetHWnd(); // 获取绘图窗口句柄
	//ShowWindow(hwnd, SW_HIDE); // 隐藏控制台窗口

	int itemp = 0;
	initEnvironment();
	// 开始游戏
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
					MessageBox(0, L"按ENTER键开始游戏！", L"小提示", MB_SETFOREGROUND);
					moveAction();//第一次游戏的时候需要自己手动选择开始游戏
					itemp = 1;
				}
				Cmd cmd = getCmd();
				execCmd(cmd);//按键操作
			}//每一个新方块的生成
		}
		EndBatchDraw();
		// 一局结束后的统计
		swprintf(over_tips, 39, L"游戏结束\n你的最终得分：%d\n是否再来亿局？", score * 100);
		if (score > top_score)
			top_score = score;
		if (MessageBox(GetHWnd(), over_tips, L"再来亿局？", MB_ICONQUESTION | MB_YESNO) == IDNO)
			break;
	}//每局游戏的循环
	return 0;
}
