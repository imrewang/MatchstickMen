#pragma once

#define  WIDTH 800  
#define  HEIGHT 600

enum PlayerStatus // 枚举类型，游戏角色所有的可能状态
{
	standleft, standright, runleft, runright, jumpleft, jumpright, die
};
extern enum PlayerStatus;// 枚举类型，游戏角色所有的可能状态
