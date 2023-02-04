#pragma once

#include "PlayMusicOnce.h"
#include "Timer.h"
#include "Player.h"
#include <time.h>
#include <conio.h>


// 一些全局变量
extern Player player;  // 定义玩家控制的游戏角色对象
extern Scene scene;  // 定义场景全局对象
extern Timer timer;  // 用于精确延时

void startup();  // 初始化

void show(); // 显示

void updateWithoutInput(); // 和输入无关的更新

void updateWithInput(); // 和输入有关的更新
