#pragma once

#include"PlayerStatus.h"
#include <graphics.h>  

class Land  // ������
{
public:
	IMAGE im_land;  // ����ͼ��
	float left_x, right_x, top_y; // �����̻�һ���������ҡ�������
	float land_width, land_height; // һ�����ͼ��Ŀ�ȡ��߶�

	void initialize();// ��ʼ��

	void draw(float px, float py);// ��ʾ�����Ϣ	
};
