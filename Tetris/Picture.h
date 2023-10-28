#pragma once
#include"Block.h"
#include"Head.h"

//��������
void DrawFrame()
{
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 1);

	for (int i = 1; i < 10; i++) {
		//������
		line(36 * i, 0, 36 * i, 36 * 15);
	}

	for (int j = 1; j < 15; j++) {
		line(0, 36 * j, 36 * 10, 36 * j);//������
	}
}

void drawGameBG()
{
	// ����������Ϸ���򡢼Ʒ�����
	// ����ߴ硪��36 * 36����λ�����أ�
	// ��Ϸ�ߴ硪��10 * 15����λ�����飩
	// ��һ��������ʾ���򡪡�4 * 4����λ�����飩
	COLORREF tmp = getlinecolor();

	for (int i = 0; i < 541; ++i)
	{
		setlinecolor(RGB(135, 206, 250 - i / 5));
		line(0, 540 - i, 360, 540 - i);
	}

	setlinecolor(tmp);

	DrawFrame();//�滭����
}

//�������䶨���ķ���Ļ���
void drawMap()
{
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 15; ++j)
			if (mp[i][j])
				drawItem(i * 36, j * 36, mp_c[i][j]);
}
//��ǰ����Ļ���
void drawSquareNow()
{
	drawItem((now_mp_x + squares[now_s_idx].dir[now_d_idx][0][0]) * 36, (now_mp_y + squares[now_s_idx].dir[now_d_idx][0][1]) * 36, colors[now_c_idx]);
	drawItem((now_mp_x + squares[now_s_idx].dir[now_d_idx][1][0]) * 36, (now_mp_y + squares[now_s_idx].dir[now_d_idx][1][1]) * 36, colors[now_c_idx]);
	drawItem((now_mp_x + squares[now_s_idx].dir[now_d_idx][2][0]) * 36, (now_mp_y + squares[now_s_idx].dir[now_d_idx][2][1]) * 36, colors[now_c_idx]);
	drawItem((now_mp_x + squares[now_s_idx].dir[now_d_idx][3][0]) * 36, (now_mp_y + squares[now_s_idx].dir[now_d_idx][3][1]) * 36, colors[now_c_idx]);
}
//��һ������Ļ���
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
//���������Ļ���
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
	settextstyle(25, 0, L"���Ŀ���");
	outtextxy(360 + 48, 300, L"���ƣ���");
	outtextxy(360 + 48, 325, L"���ƣ���");
	outtextxy(360 + 48, 350, L"���Σ���");
	outtextxy(360 + 48, 375, L"���䣺��");
	outtextxy(360 + 48, 400, L"��ͣ���ո��");
	outtextxy(360 + 48, 425, L"��ʼ��ENTER");

	setlinecolor(WHITE);
	rectangle(360 + 48, 36, 600 - 48, 36 + 144);
	drawSquareNext();
	setlinecolor(0x7FFFAA);
	rectangle(360 + 48, 36, 600 - 48, 36 + 144);

	swprintf(top_score_tips, 29, L"��ʷ��¼��% d", top_score * 100);
	outtextxy(360 + 48, 225, top_score_tips);
	swprintf(score_tips, 29, L"���ֵ÷֣�%d", score * 100);
	outtextxy(360 + 48, 250, score_tips);

	setlinecolor(tmp_line_color);
	setlinestyle(&tmp_line_style);
	settextcolor(tmp_text_color);
	settextstyle(&tmp_text_style);
}
