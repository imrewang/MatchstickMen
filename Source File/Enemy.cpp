#include"Enemy.h"

void Enemy::initialize() // 初始化
{
	loadimage(&im_enemy, _T("picture/bat.png")); // 导入敌人-蝙蝠-图片
	enemy_width = im_enemy.getwidth(); // 获得图像的宽、高
	enemy_height = im_enemy.getheight();
}

void Enemy::draw(float px, float py)// 显示相关信息	
{
	putimagePng(x - enemy_width / 2 - px, y - enemy_height / 2 - py, &im_enemy); // 角色不动，绘制敌人有一个相对偏移量
}

void Enemy::update()  // 敌人在一定范围内，左右移动
{
	x += vx;
	if (x > x_max || x < x_min) {
		vx = -vx;
	}
}