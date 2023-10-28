#pragma once
#include<graphics.h>
#include"Head.h"

//COLORREF colors[7] = { RGB(255, 0, 0), RGB(255, 165, 0), RGB(255, 255, 0), RGB(0, 128, 0), 
//RGB(0, 255, 255), RGB(0, 0, 255), RGB(128, 0, 128) };

void drawItem(int x, int y, COLORREF c)
{
	/*�������
	* �����СΪ��15*36��*��10*36��
	* ʵ�ʳߴ磺32*32����λ�����أ�
	* �߿���ɫ����ɫ(��Ϊ�������˰�ɫ�����ߣ�������������趨
	* Բ�ǰ뾶��4����λ�����أ�
	* �ڲ���ࣺ2����λ�����أ�
	*/
	tmp_fill_color = getfillcolor();

	const int r = 6;
	const int p = 2;

	int up_l_x = x + p + r;
	int up_r_x = x + 36 - p - r;
	int up___y = y + p;

	int down_l_x = x + p + r;
	int down_r_x = x + 36 - p - r;
	int down___y = y + 36 - p;

	int left_u_y = y + p + r;
	int left_d_y = y + 36 - p - r;
	int left___x = x + p;

	int right_u_y = y + p + r;
	int right_d_y = y + 36 - p - r;
	int right___x = x + 36 - p;

	getpixel(x, y);
	setlinestyle(PS_SOLID, 1);
	line(up_l_x, up___y, up_r_x, up___y);
	line(down_l_x, down___y, down_r_x, down___y);
	line(left___x, left_u_y, left___x, left_d_y);
	line(right___x, right_u_y, right___x, right_d_y);
	arc(x + p, y + p, x + p + 2 * r, y + p + 2 * r, pi / 2, pi);
	arc(x + 36 - p, y + p, x + 36 - p - 2 * r, y + p + 2 * r, 0, pi / 2);
	arc(x + p, y + 36 - p, x + p + 2 * r, y + 36 - p - 2 * r, -pi, -pi / 2);
	arc(x + 36 - p, y + 36 - p, x + 36 - p - 2 * r, y + 36 - p - 2 * r, -pi / 2, 0);

	setfillcolor(c);
	//������������������
	floodfill(x + p + r, y + p + r + 1, WHITE);
	setfillcolor(tmp_fill_color);
}

//����˹�������״����
/*һ������˹����Ӧ�þ�����������״����һ������˹���������4����״
ÿ����״����Ҫ����4���㣬ÿ������Ҫ��2������ֵ���������꣬
���������Ҫһ��4 �� 4 �� 2 ���������������˹�������״,
�õ�����˹����Ľṹ�����£�
*/
struct Square
{
	int dir[4][4][2];//����
};
//�ṹ�嶨����ˣ����Ǿ���Ҫ����7�ֶ���˹����Ľṹ��ʵ����7��Square
//����һ���γ�����
Square squares[7] = {
	{ 0, -2, 0, -1, 0, 0, 1, 0, 0, -1, 1, -1, 2, -1, 0, 0, 0, -2, 1, -2, 1, -1, 1, 0, 0, 0, 1, 0, 2, 0, 2, -1 },       //  L ��
	{ 0, 0, 1, 0, 1, -1, 1, -2, 0, -1, 0, 0, 1, 0, 2, 0, 0, -2, 0, -1, 0, 0, 1, -2, 0, -1, 1, -1, 2, -1, 2, 0 },       //  L �ͣ�����
	{ 0, -1, 0, 0, 1, -1, 1, 0, 0, -1, 0, 0, 1, -1, 1, 0, 0, -1, 0, 0, 1, -1, 1, 0, 0, -1, 0, 0, 1, -1, 1, 0 },        // �� ��
	{ 0, 0, 1, -1, 1, 0, 2, 0, 1, -2, 1, -1, 1, 0, 2, -1, 0, -1, 1, -1, 1, 0, 2, -1, 0, -1, 1, -2, 1, -1, 1, 0 },      // ɽ ��
	{ 0, -3, 0, -2, 0, -1, 0, 0, 0, -3, 1, -3, 2, -3, 3, -3, 0, -3, 0, -2, 0, -1, 0, 0, 0, -3, 1, -3, 2, -3, 3, -3 },  //  | ��
	{ 0, -1, 1, -1, 1, 0, 2, 0, 0, -1, 0, 0, 1, -2, 1, -1, 0, -1, 1, -1, 1, 0, 2, 0, 0, -1, 0, 0, 1, -2, 1, -1 },      //  Z ��
	{ 0, 0, 1, -1, 1, 0, 2, -1, 1, -2, 1, -1, 2, -1, 2, 0, 0, 0, 1, -1, 1, 0, 2, -1, 1, -2, 1, -1, 2, -1, 2, 0 }       //  Z �ͣ�����
};

//����˹����ĵ���
void initDatasPerSquare() {
	now_mp_x = 5;
	now_mp_y = -1;
	flag_next = 0;
	now_c_idx = next_c_idx;
	now_s_idx = next_s_idx;
	now_d_idx = next_d_idx;
	next_s_idx = rand() % 7;
	next_c_idx = rand() % 7;
	next_d_idx = rand() % 4;
}