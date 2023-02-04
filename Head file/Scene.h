#pragma once

#include"randBetweenMinMax.h"
#include"Land.h"
#include"Enemy.h"
#include <vector>
using namespace std;


class Scene // ��Ϸ������
{
public:
	IMAGE im_bk;  // ����ͼ��	
	IMAGE im_star; // �յ㴦��һ������ͼ��
	vector<Land> lands; // �������
	vector<Enemy> enemies; // �������
	int level; // ����浽�ڼ���
	int lastlevel; // ��һ���浽�ڼ���

	void draw(float px, float py);// ��ʾ�����Ϣ	

	void initialize();// ��ʼ��
};