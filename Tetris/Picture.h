#pragma once
#include"Block.h"
#include"Head.h"

//绘制网格
void DrawFrame()
{
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 1);

	for (int i = 1; i < 10; i++) {
		//画竖线
		line(36 * i, 0, 36 * i, 36 * 15);
	}

	for (int j = 1; j < 15; j++) {
		line(0, 36 * j, 36 * 10, 36 * j);//画横线
	}
}

void drawGameBG()
{
	// 划分区域（游戏区域、计分区域）
	// 方块尺寸——36 * 36（单位：像素）
	// 游戏尺寸——10 * 15（单位：方块）
	// 下一个方块显示区域——4 * 4（单位：方块）
	COLORREF tmp = getlinecolor();

	for (int i = 0; i < 541; ++i)
	{
		setlinecolor(RGB(135, 206, 250 - i / 5));
		line(0, 540 - i, 360, 540 - i);
	}

	setlinecolor(tmp);

	DrawFrame();//绘画网格
}

//“尘埃落定”的方块的绘制
void drawMap()
{
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 15; ++j)
			if (mp[i][j])
				drawItem(i * 36, j * 36, mp_c[i][j]);
}
//当前方块的绘制
void drawSquareNow()
{
	drawItem((now_mp_x + squares[now_s_idx].dir[now_d_idx][0][0]) * 36, (now_mp_y + squares[now_s_idx].dir[now_d_idx][0][1]) * 36, colors[now_c_idx]);
	drawItem((now_mp_x + squares[now_s_idx].dir[now_d_idx][1][0]) * 36, (now_mp_y + squares[now_s_idx].dir[now_d_idx][1][1]) * 36, colors[now_c_idx]);
	drawItem((now_mp_x + squares[now_s_idx].dir[now_d_idx][2][0]) * 36, (now_mp_y + squares[now_s_idx].dir[now_d_idx][2][1]) * 36, colors[now_c_idx]);
	drawItem((now_mp_x + squares[now_s_idx].dir[now_d_idx][3][0]) * 36, (now_mp_y + squares[now_s_idx].dir[now_d_idx][3][1]) * 36, colors[now_c_idx]);
}
//下一个方块的绘制
void drawSquareNext()
{
	int tmp_x = 360 + 48;
	int tmp_y = 36 + 108;
	COLORREF c = colors[next_c_idx];
	drawItem(tmp_x + squares[next_s_idx].dir[next_d_idx][0][0] * 36, tmp_y + squares[next_s_idx].dir[next_d_idx][0][1] * 36, c);
	drawItem(tmp_x + squares[next_s_idx].dir[next_d_idx][1][0] * 36, tmp_y + squares[next_s_idx].dir[next_d_idx][1][1] * 36, c);
	drawItem(tmp_x + squares[next_s_idx].dir[next_d_idx][2][0] * 36, tmp_y + squares[next_s_idx].dir[next_d_idx][2][1] * 36, c);
	drawItem(tmp_x + squares[next_s_idx].dir[next_d_idx][3][0] * 36, tmp_y + squares[next_s_idx].dir[next_d_idx][3][1] * 36, c);
}
//侧边栏区域的绘制
void drawSide()
{
	tmp_line_color = getlinecolor();
	getlinestyle(&tmp_line_style);
	tmp_text_color = getlinecolor();
	gettextstyle(&tmp_text_style);

	for (int i = 0; i < 541; ++i)
	{
		setlinecolor(RGB(224, 178, 220 - i / 15));
		line(361, i, 600, i);
	}
	settextcolor(RGB(65, 105, 225));
	settextstyle(25, 0, L"华文楷体");
	outtextxy(360 + 48, 300, L"左移：←");
	outtextxy(360 + 48, 325, L"右移：→");
	outtextxy(360 + 48, 350, L"变形：↑");
	outtextxy(360 + 48, 375, L"下落：↓");
	outtextxy(360 + 48, 400, L"暂停：空格键");
	outtextxy(360 + 48, 425, L"开始：ENTER");

	setlinecolor(WHITE);
	rectangle(360 + 48, 36, 600 - 48, 36 + 144);
	drawSquareNext();
	setlinecolor(0x7FFFAA);
	rectangle(360 + 48, 36, 600 - 48, 36 + 144);

	swprintf(top_score_tips, 29, L"历史记录：% d", top_score * 100);
	outtextxy(360 + 48, 225, top_score_tips);
	swprintf(score_tips, 29, L"本轮得分：%d", score * 100);
	outtextxy(360 + 48, 250, score_tips);

	setlinecolor(tmp_line_color);
	setlinestyle(&tmp_line_style);
	settextcolor(tmp_text_color);
	settextstyle(&tmp_text_style);
}
