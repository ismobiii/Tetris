#pragma once
#include<graphics.h>
#include"Head.h"

//COLORREF colors[7] = { RGB(255, 0, 0), RGB(255, 165, 0), RGB(255, 255, 0), RGB(0, 128, 0), 
//RGB(0, 255, 255), RGB(0, 0, 255), RGB(128, 0, 128) };

void drawItem(int x, int y, COLORREF c)
{
	/*方块设计
	* 网格大小为（15*36）*（10*36）
	* 实际尺寸：32*32（单位：像素）
	* 边框颜色：白色(因为后面多加了白色网格线，打算舍弃这个设定
	* 圆角半径：4（单位：像素）
	* 内部间距：2（单位：像素）
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
	//这个函数用于填充区域
	floodfill(x + p + r, y + p + r + 1, WHITE);
	setfillcolor(tmp_fill_color);
}

//俄罗斯方块的形状定义
/*一个俄罗斯方块应该具有特征【形状】，一个俄罗斯方块最多有4个形状
每个形状都需要描述4个点，每个点需要用2个坐标值来描述坐标，
因此我们需要一个4 × 4 × 2 的数组来储存俄罗斯方块的形状,
得到俄罗斯方块的结构体如下：
*/
struct Square
{
	int dir[4][4][2];//坐标
};
//结构体定义好了，我们就需要根据7种俄罗斯方块的结构来实例化7个Square
//两两一组形成坐标
Square squares[7] = {
	{ 0, -2, 0, -1, 0, 0, 1, 0, 0, -1, 1, -1, 2, -1, 0, 0, 0, -2, 1, -2, 1, -1, 1, 0, 0, 0, 1, 0, 2, 0, 2, -1 },       //  L 型
	{ 0, 0, 1, 0, 1, -1, 1, -2, 0, -1, 0, 0, 1, 0, 2, 0, 0, -2, 0, -1, 0, 0, 1, -2, 0, -1, 1, -1, 2, -1, 2, 0 },       //  L 型（反）
	{ 0, -1, 0, 0, 1, -1, 1, 0, 0, -1, 0, 0, 1, -1, 1, 0, 0, -1, 0, 0, 1, -1, 1, 0, 0, -1, 0, 0, 1, -1, 1, 0 },        // 田 型
	{ 0, 0, 1, -1, 1, 0, 2, 0, 1, -2, 1, -1, 1, 0, 2, -1, 0, -1, 1, -1, 1, 0, 2, -1, 0, -1, 1, -2, 1, -1, 1, 0 },      // 山 型
	{ 0, -3, 0, -2, 0, -1, 0, 0, 0, -3, 1, -3, 2, -3, 3, -3, 0, -3, 0, -2, 0, -1, 0, 0, 0, -3, 1, -3, 2, -3, 3, -3 },  //  | 型
	{ 0, -1, 1, -1, 1, 0, 2, 0, 0, -1, 0, 0, 1, -2, 1, -1, 0, -1, 1, -1, 1, 0, 2, 0, 0, -1, 0, 0, 1, -2, 1, -1 },      //  Z 型
	{ 0, 0, 1, -1, 1, 0, 2, -1, 1, -2, 1, -1, 2, -1, 2, 0, 0, 0, 1, -1, 1, 0, 2, -1, 1, -2, 1, -1, 2, -1, 2, 0 }       //  Z 型（反）
};

//俄罗斯方块的迭代
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