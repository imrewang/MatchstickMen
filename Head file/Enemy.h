#pragma once

#include"PlayerStatus.h"
#include "EasyXPng.h"
#include <graphics.h>  

class Enemy  // 敌人类
{
public:
	IMAGE im_enemy;  // 敌人图像
	float x, y; // 用来刻画敌人的中心坐标
	float enemy_width, enemy_height; // 敌人图像的宽度、高度
	float x_min, x_max; // 敌人移动的x坐标最大值、最小值
	float vx; // 敌人在x方向的移动速度

	void initialize(); // 初始化

	void draw(float px, float py);// 显示相关信息	

	void update();  // 敌人在一定范围内，左右移动
};
