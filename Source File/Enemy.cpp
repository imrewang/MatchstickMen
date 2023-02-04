#include"Enemy.h"

void Enemy::initialize() // ��ʼ��
{
	loadimage(&im_enemy, _T("picture/bat.png")); // �������-����-ͼƬ
	enemy_width = im_enemy.getwidth(); // ���ͼ��Ŀ���
	enemy_height = im_enemy.getheight();
}

void Enemy::draw(float px, float py)// ��ʾ�����Ϣ	
{
	putimagePng(x - enemy_width / 2 - px, y - enemy_height / 2 - py, &im_enemy); // ��ɫ���������Ƶ�����һ�����ƫ����
}

void Enemy::update()  // ������һ����Χ�ڣ������ƶ�
{
	x += vx;
	if (x > x_max || x < x_min) {
		vx = -vx;
	}
}