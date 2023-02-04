#include"Player.h"

void Player::draw()// 显示相关信息	
{
	// 游戏中显示角色，角色不动，地面、背景相对运动
	putimagePng(WIDTH / 2, HEIGHT / 2 - height, &im_show);
	//putimage(WIDTH / 2, HEIGHT / 2 - height, &im_show);
}

void Player::initialize() // 初始化
{
	ims_runleft.clear(); // 先清空掉vector
	ims_runright.clear();

	loadimage(&im_standright, _T("picture/standright.png")); // 导入向右站立图片
	loadimage(&im_standleft, _T("picture/standleft.png")); // 导入向左站立图片
	loadimage(&im_jumpright, _T("picture/jumpright.png")); // 导入向右方向跳跃图像
	loadimage(&im_jumpleft, _T("picture/jumpleft.png")); // 导入向左方向跳跃图像

	playerStatus = standright; // 初始为向右站立的游戏状态
	im_show = im_standright;  // 初始显示向右站立的图片

	width = im_standright.getwidth(); // 获得图像的宽、高，所有动画图片大小一样
	height = im_standright.getheight();

	TCHAR filename[80];
	for (int i = 0; i <= 7; i++) // 把向右奔跑的八张图片对象添加到ims_runright中
	{
		_stprintf_s(filename, _T("picture/runright%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_runright.push_back(im);
	}
	for (int i = 0; i <= 7; i++) // 把向左奔跑的八张图片对象添加到ims_runright中
	{
		_stprintf_s(filename, _T("picture/runleft%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_runleft.push_back(im);
	}

	animId = 0; // 动画id开始设为0

	updateXY(WIDTH / 2, HEIGHT / 2); // 开始将角色放在画面中间
	vx = 10; // 水平方向初速度
	vy = 0;  // 竖直方向速度初始为0
	gravity = 3;  // 设定重力加速度
}

void Player::updateXY(float mx, float my) // 根据输入，更新玩家坐标
{
	x_left = mx;
	y_bottom = my;
}

void Player::runRight(Scene& scene) // 游戏角色向右奔跑
{
	x_left += vx; // 横坐标增加，向右移动
	if (!isNotOnAllRightSides(scene.lands)) {
		x_left -= vx;
	}
	else if (x_left+width - scene.lands[scene.lands.size() - 1].right_x >= width * 0.6) {//x_left + width > scene.lands[scene.lands.size() - 1].left_x
		x_left -= vx;
	}

	if (isNotOnAllLands(scene.lands))  // 移动后不在任何一块地面上了
	{
		im_show = im_jumpright;// 切换到向右起跳图片
		playerStatus = jumpright;// 切换到向右起跳状态
		return;
	}

	if (playerStatus == jumpleft || playerStatus == jumpright) // 如果是起跳状态
	{
		im_show = im_jumpright; // 改变造型为向右起跳造型
	}
	else
	{
		if (playerStatus != runright) // 如果之前角色状态不是向右奔跑
		{
			playerStatus = runright; // 切换为向右奔跑状态
			animId = 0; // 动画播放id初始化为0
		}
		else // 表示之前就是向右奔跑状态了
		{
			animId++; // 动画图片开始切换
			if (animId >= ims_runright.size()) { // 循环切换
				animId = 0;
			}
		}
		im_show = ims_runright[animId];	 // 设置要显示的对应图片	 
	}


}

void Player::runLeft(Scene& scene) // 游戏角色向左奔跑
{
	x_left -= vx; // 横坐标减少，向左移动	
	if (!isNotOnAllLeftSides(scene.lands)) {
		x_left += vx;
	}
	if (isNotOnAllLands(scene.lands))  // 移动后不在任何一块地面上了
	{
		im_show = im_jumpleft; // 切换到向左起跳图片
		playerStatus = jumpleft; // 切换到向左起跳状态
		return;
	}

	if (playerStatus == jumpleft || playerStatus == jumpright) // 如果是起跳状态
	{
		im_show = im_jumpleft; // 改变造型为向左起跳造型
	}
	else
	{
		if (playerStatus != runleft) // 如果之前角色状态不是向左奔跑
		{
			playerStatus = runleft; // 切换为向左奔跑状态
			animId = 0; // 动画播放id初始化为0
		}
		else // 之前就是向左奔跑状态了
		{
			animId++; // 动画图片开始切换
			if (animId >= ims_runleft.size()) // 循环切换
				animId = 0;
		}
		im_show = ims_runleft[animId];	 // 设置要显示的对应图片	
	}
}

void Player::standStill() // 游戏角色默认为向左或向右静止站立
{
	if (playerStatus == runleft || playerStatus == standleft)
		im_show = im_standleft;
	else if (playerStatus == runright || playerStatus == standright)
		im_show = im_standright;
}

void Player::beginJump() // 按下w或向上方向键后，游戏角色跳跃的处理
{
	if (playerStatus != jumpleft && playerStatus != jumpright) // 已经在空中的话，不要起跳
	{
		if (playerStatus == runleft || playerStatus == standleft)  // 起跳前是向左跑或向左站立状态
		{
			im_show = im_jumpleft; // 切换到向左起跳图片
			playerStatus = jumpleft; // 切换到向左起跳状态
		}
		else if (playerStatus == runright || playerStatus == standright)// 起跳前是向右跑或向右站立状态
		{
			im_show = im_jumpright;// 切换到向右起跳图片
			playerStatus = jumpright;// 切换到向右起跳状态
		}
		vy = -32; // 给角色一个向上的初速度
	}
}

int Player::isCollideEnemy(Enemy& enemy) // 判断角色是否和敌人碰撞，如果是返回1，否则返回0
{
	float x_center = x_left + width / 2;
	float y_center = y_bottom - height / 2;
	if (abs(enemy.x - x_center) <= enemy.enemy_width * 0.5
		&& abs(enemy.y - y_center) <= enemy.enemy_height * 0.5) {
		return 1;
	}
	else if (abs(enemy.x - x_center) <= width * 0.5
		&& abs(enemy.y - y_center) <= height * 0.5) {
		return 1;
	}
	else {
		return 0;
	}
}

// 判断游戏角色是否正站在这块地面上，如果是的话返回1，否则返回0
int Player::isOnLand(Land& land)
{
	float x_right = x_left + width;
	float ySpeed = vy;
	// 判断是否站在地面上，还需要考虑player的y方向速度情况，速度过快有可能直接穿透地面（要防止这个情况发生）
	if (ySpeed <= 0) {// y轴方向速度小于0，表示正在向上运动，不需要考虑速度的影响
		ySpeed = 0;
	}

	if (land.left_x - x_left <= width * 0.6 && x_right - land.right_x <= width * 0.6 && abs(y_bottom - land.top_y) <= 5 + ySpeed) {
		return 1;
	}
	else {
		return 0;
	}
}

int Player::isNotOnAllLands(vector<Land>& lands) // 判断玩家是否不在所有的地面上
{
	for (int i = 0; i < lands.size(); i++)
	{
		if (isOnLand(lands[i])) {
			return 0; // 在任何一块地面上，返回0
		}
	}
	return 1; // 不在所有地面上，返回1
}

/////////////////////////////////////////////
// 判断游戏角色是否正站在地块的侧边上，如果是的话返回1，否则返回0
int Player::isOnRightSide(Land& land)
{
	float x_right = x_left + width;
	float y_top = y_bottom - height;
	
	if (x_left < land.left_x && x_right > land.left_x && y_top < land.top_y + land.land_height && y_bottom>land.top_y) {
		return 1;
	}
	return 0;
	
}

int Player::isNotOnAllRightSides(vector<Land>& lands) // 判断玩家是否不在所有的地块的侧边上
{
	for (int i = 0; i < lands.size(); i++)
	{
		if (isOnRightSide(lands[i])) {
			return 0; // 在任何一块地块的侧边上，返回0
		}
	}
	return 1; // 不在所有地面上，返回1
}
////////////////////////////////////////////
// 判断游戏角色是否正站在地块的侧边上，如果是的话返回1，否则返回0
int Player::isOnLeftSide(Land& land)
{
	float x_right = x_left + width;
	float y_top = y_bottom - height;

	if (x_left < land.right_x && x_right > land.right_x && y_top < land.top_y + land.land_height && y_bottom>land.top_y) {
		return 1;
	}
	return 0;

}

int Player::isNotOnAllLeftSides(vector<Land>& lands) // 判断玩家是否不在所有的地块的侧边上
{
	for (int i = 0; i < lands.size(); i++)
	{
		if (isOnLeftSide(lands[i])) {
			return 0; // 在任何一块地块的侧边上，返回0
		}
	}
	return 1; // 不在所有地面上，返回1
}

void Player::updateYcoordinate(Scene& scene) // x坐标是按键盘控制的，而y坐标是每帧自动更新的
{
	if (playerStatus == jumpleft || playerStatus == jumpright) // 当前是在空中跳跃状态
	{
		vy += gravity; // y方向速度受重力影响变化
		y_bottom += vy;  // y方向位置受速度影响变化
		for (int i = 0; i < scene.lands.size(); i++)   // 对所有地面遍历
		{
			if (isOnLand(scene.lands[i])) // 当火柴人正好站在一个地面上时
			{
				y_bottom = scene.lands[i].top_y; // 保证正好落在地面上
				if (playerStatus == jumpleft) {// 向左跳，落地后切换到向左站立方向
					playerStatus = standleft;
				}
				if (playerStatus == jumpright) {// 向右跳，落地后切换到向右站立方向
					playerStatus = standright;
				}
				break; // 跳出循环，不需要再对其他地面判断了
			}
		}
	}
}