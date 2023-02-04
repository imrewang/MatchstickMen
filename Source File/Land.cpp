#include"Land.h"

void Land::initialize() // 初始化
{
	loadimage(&im_land, _T("picture/land.png")); // 导入地面图片
	land_width = im_land.getwidth(); // 获得地面图像的宽、高
	land_height = im_land.getheight();
	left_x = WIDTH / 2;  // land初始化在画面正中间，正好就在玩家角色脚底下
	right_x = left_x + land_width;
	top_y = HEIGHT / 2;
}

void Land::draw(float px, float py)// 显示相关信息	
{
	putimage(left_x - px, top_y - py, &im_land);  // 角色不动，绘制地面有一个偏移量
	//还是以偏了10，10为例，那相对的地块要偏-10，-10
}