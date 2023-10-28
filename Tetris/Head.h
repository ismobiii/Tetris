#pragma once
#include<graphics.h>
#include<cmath>
//一些符号的定义：

//Block.h文件
// 
//颜色：
COLORREF colors[7] = { RGB(255, 0, 0), RGB(255, 165, 0), RGB(255, 255, 0), RGB(0, 128, 0),
RGB(0, 255, 255), RGB(0, 0, 255), RGB(128, 0, 128) };

//里面的方块颜色类型定义相关
COLORREF tmp_line_color;
LINESTYLE tmp_line_style;
COLORREF tmp_text_color;
LOGFONT tmp_text_style;
COLORREF tmp_fill_color;
//pi的定义
const double pi = acos(-1);

//俄罗斯方块的属性定义：
int now_c_idx;//当前俄罗斯方块颜色索引
int now_s_idx;//当前俄罗斯方块形状索引
int now_d_idx;//当前俄罗斯方块类型索引
int next_c_idx;//下一个俄罗斯方块颜色索引
int next_s_idx;//下一个俄罗斯方块形状索引
int next_d_idx;//下一个俄罗斯方块类型索引

//当前俄罗斯方块的位置
/*
当前俄罗斯方块的地图位置需要设置两个变量now_mp_x、now_mp_y来确认，
然后只要根据当前俄罗斯方块的dir属性，
就可以知道当前俄罗斯方块的4个方块的地图位置，从而绘制出来。
*/
//坐标
int now_mp_x;//x坐标
int now_mp_y;//y坐标


int flag_next;//提示下一个方块开始出现的标志
int flag_over;//游戏结束的标志

//移动指令
enum Cmd {
	Cmd_rorate,//方块旋转
	Cmd_left,//方块左移
	Cmd_right,//方块右移
	Cmd_down,//方块下移
	Cmd_pause,//暂停游戏
	Cmd_action//开始游戏
};

DWORD time_now;//游戏进行时间，用于下降时

//分数
int score;
int top_score = 0;//历史最高分

int mp[10][15];//存储地图中的俄罗斯方块
int mp_tmp[10][15];
COLORREF mp_c[10][15];//存储地图中俄罗斯方块的颜色
COLORREF mp_c_tmp[10][15];

wchar_t score_tips[30];
wchar_t over_tips[50];
wchar_t top_score_tips[30];