#include"Land.h"

void Land::initialize() // ��ʼ��
{
	loadimage(&im_land, _T("picture/land.png")); // �������ͼƬ
	land_width = im_land.getwidth(); // ��õ���ͼ��Ŀ���
	land_height = im_land.getheight();
	left_x = WIDTH / 2;  // land��ʼ���ڻ������м䣬���þ�����ҽ�ɫ�ŵ���
	right_x = left_x + land_width;
	top_y = HEIGHT / 2;
}

void Land::draw(float px, float py)// ��ʾ�����Ϣ	
{
	putimage(left_x - px, top_y - py, &im_land);  // ��ɫ���������Ƶ�����һ��ƫ����
	//������ƫ��10��10Ϊ��������Եĵؿ�Ҫƫ-10��-10
}