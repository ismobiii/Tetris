#pragma once
#include<graphics.h>
#include<cmath>
//һЩ���ŵĶ��壺

//Block.h�ļ�
// 
//��ɫ��
COLORREF colors[7] = { RGB(255, 0, 0), RGB(255, 165, 0), RGB(255, 255, 0), RGB(0, 128, 0),
RGB(0, 255, 255), RGB(0, 0, 255), RGB(128, 0, 128) };

//����ķ�����ɫ���Ͷ������
COLORREF tmp_line_color;
LINESTYLE tmp_line_style;
COLORREF tmp_text_color;
LOGFONT tmp_text_style;
COLORREF tmp_fill_color;
//pi�Ķ���
const double pi = acos(-1);

//����˹��������Զ��壺
int now_c_idx;//��ǰ����˹������ɫ����
int now_s_idx;//��ǰ����˹������״����
int now_d_idx;//��ǰ����˹������������
int next_c_idx;//��һ������˹������ɫ����
int next_s_idx;//��һ������˹������״����
int next_d_idx;//��һ������˹������������

//��ǰ����˹�����λ��
/*
��ǰ����˹����ĵ�ͼλ����Ҫ������������now_mp_x��now_mp_y��ȷ�ϣ�
Ȼ��ֻҪ���ݵ�ǰ����˹�����dir���ԣ�
�Ϳ���֪����ǰ����˹�����4������ĵ�ͼλ�ã��Ӷ����Ƴ�����
*/
//����
int now_mp_x;//x����
int now_mp_y;//y����


int flag_next;//��ʾ��һ�����鿪ʼ���ֵı�־
int flag_over;//��Ϸ�����ı�־

//�ƶ�ָ��
enum Cmd {
	Cmd_rorate,//������ת
	Cmd_left,//��������
	Cmd_right,//��������
	Cmd_down,//��������
	Cmd_pause,//��ͣ��Ϸ
	Cmd_action//��ʼ��Ϸ
};

DWORD time_now;//��Ϸ����ʱ�䣬�����½�ʱ

//����
int score;
int top_score = 0;//��ʷ��߷�

int mp[10][15];//�洢��ͼ�еĶ���˹����
int mp_tmp[10][15];
COLORREF mp_c[10][15];//�洢��ͼ�ж���˹�������ɫ
COLORREF mp_c_tmp[10][15];

wchar_t score_tips[30];
wchar_t over_tips[50];
wchar_t top_score_tips[30];