#pragma once

#include"randBetweenMinMax.h"
#include"Land.h"
#include"Enemy.h"
#include <vector>
using namespace std;


class Scene // 游戏场景类
{
public:
	IMAGE im_bk;  // 背景图像	
	IMAGE im_star; // 终点处放一个星星图案
	vector<Land> lands; // 多个地面
	vector<Enemy> enemies; // 多个敌人
	int level; // 玩家玩到第几关
	int lastlevel; // 上一次玩到第几关

	void draw(float px, float py);// 显示相关信息	

	void initialize();// 初始化
};