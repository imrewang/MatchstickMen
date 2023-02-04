#pragma once

#include"Scene.h"

class Player  // ��ҿ��Ƶ���Ϸ��ɫ��
{
public:
	IMAGE im_show;  // ��ǰʱ��Ҫ��ʾ��ͼ��
	IMAGE im_standright; // ����վ��ͼ��
	IMAGE im_standleft; // ����վ��ͼ��
	IMAGE im_jumpright; // ���ҷ�����Ծͼ��
	IMAGE im_jumpleft; // ��������Ծͼ��
	vector <IMAGE> ims_runright; // ���ұ��ܵ�ͼ������
	vector <IMAGE> ims_runleft; // �����ܵ�ͼ������
	int animId;  // ����ѭ���������ŵ�id
	PlayerStatus playerStatus; // ��ǰ��״̬

	float x_left, y_bottom; // ���������꣬��ΪֻҪ���������͵�����ײ������
	float vx, vy; // �ٶ�
	float gravity; // �������ٶ�
	float width, height; // ͼƬ�Ŀ�ȡ��߶�

	void draw();// ��ʾ�����Ϣ	

	void initialize(); // ��ʼ��

	void updateXY(float mx, float my); // �������룬�����������

	void runRight(Scene& scene);// ��Ϸ��ɫ���ұ���

	void runLeft(Scene& scene); // ��Ϸ��ɫ������

	void standStill();// ��Ϸ��ɫĬ��Ϊ��������Ҿ�ֹվ��

	void beginJump();// ����w�����Ϸ��������Ϸ��ɫ��Ծ�Ĵ���

	int isCollideEnemy(Enemy& enemy); // �жϽ�ɫ�Ƿ�͵�����ײ������Ƿ���1�����򷵻�0

	// �ж���Ϸ��ɫ�Ƿ���վ���������ϣ�����ǵĻ�����1�����򷵻�0
	int isOnLand(Land& land);

	int isNotOnAllLands(vector<Land>& lands); // �ж�����Ƿ������еĵ�����

	// �ж���Ϸ��ɫ�Ƿ���վ�ڵؿ�Ĳ���ϣ�����ǵĻ�����1�����򷵻�0
	int isOnRightSide(Land& land);

	int isNotOnAllRightSides(vector<Land>& lands); // �ж�����Ƿ������еĵؿ�Ĳ����

		// �ж���Ϸ��ɫ�Ƿ���վ�ڵؿ�Ĳ���ϣ�����ǵĻ�����1�����򷵻�0
	int isOnLeftSide(Land& land);

	int isNotOnAllLeftSides(vector<Land>& lands); // �ж�����Ƿ������еĵؿ�Ĳ����

	void updateYcoordinate(Scene& scene);// x�����ǰ����̿��Ƶģ���y������ÿ֡�Զ����µ�
};
