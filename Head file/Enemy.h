#pragma once

#include"PlayerStatus.h"
#include "EasyXPng.h"
#include <graphics.h>  

class Enemy  // ������
{
public:
	IMAGE im_enemy;  // ����ͼ��
	float x, y; // �����̻����˵���������
	float enemy_width, enemy_height; // ����ͼ��Ŀ�ȡ��߶�
	float x_min, x_max; // �����ƶ���x�������ֵ����Сֵ
	float vx; // ������x������ƶ��ٶ�

	void initialize(); // ��ʼ��

	void draw(float px, float py);// ��ʾ�����Ϣ	

	void update();  // ������һ����Χ�ڣ������ƶ�
};
