#pragma once

#include"PlayerStatus.h"
#include <graphics.h>  

class Land  // 地面类
{
public:
	IMAGE im_land;  // 地面图像
	float left_x, right_x, top_y; // 用来刻画一块地面的左、右、上坐标
	float land_width, land_height; // 一块地面图像的宽度、高度

	void initialize();// 初始化

	void draw(float px, float py);// 显示相关信息	
};
