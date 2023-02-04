#pragma once

#include"Scene.h"

class Player  // 玩家控制的游戏角色类
{
public:
	IMAGE im_show;  // 当前时刻要显示的图像
	IMAGE im_standright; // 向右站立图像
	IMAGE im_standleft; // 向左站立图像
	IMAGE im_jumpright; // 向右方向跳跃图像
	IMAGE im_jumpleft; // 向左方向跳跃图像
	vector <IMAGE> ims_runright; // 向右奔跑的图像序列
	vector <IMAGE> ims_runleft; // 向左奔跑的图像序列
	int animId;  // 用于循环动画播放的id
	PlayerStatus playerStatus; // 当前的状态

	float x_left, y_bottom; // 这两个坐标，因为只要用这两个和地面碰撞就行了
	float vx, vy; // 速度
	float gravity; // 重力加速度
	float width, height; // 图片的宽度、高度

	void draw();// 显示相关信息	

	void initialize(); // 初始化

	void updateXY(float mx, float my); // 根据输入，更新玩家坐标

	void runRight(Scene& scene);// 游戏角色向右奔跑

	void runLeft(Scene& scene); // 游戏角色向左奔跑

	void standStill();// 游戏角色默认为向左或向右静止站立

	void beginJump();// 按下w或向上方向键后，游戏角色跳跃的处理

	int isCollideEnemy(Enemy& enemy); // 判断角色是否和敌人碰撞，如果是返回1，否则返回0

	// 判断游戏角色是否正站在这块地面上，如果是的话返回1，否则返回0
	int isOnLand(Land& land);

	int isNotOnAllLands(vector<Land>& lands); // 判断玩家是否不在所有的地面上

	// 判断游戏角色是否正站在地块的侧边上，如果是的话返回1，否则返回0
	int isOnRightSide(Land& land);

	int isNotOnAllRightSides(vector<Land>& lands); // 判断玩家是否不在所有的地块的侧边上

		// 判断游戏角色是否正站在地块的侧边上，如果是的话返回1，否则返回0
	int isOnLeftSide(Land& land);

	int isNotOnAllLeftSides(vector<Land>& lands); // 判断玩家是否不在所有的地块的侧边上

	void updateYcoordinate(Scene& scene);// x坐标是按键盘控制的，而y坐标是每帧自动更新的
};
