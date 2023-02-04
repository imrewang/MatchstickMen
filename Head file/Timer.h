#pragma once
#include <windows.h>

//为了防止游戏占用CPU计算资源过高
//#include "Timer.h"
//定义对象：
//Timer timer; // 用于改进的延时
//然后可以进行非阻塞式的延时，在不同性能的计算机上统一游戏速度


class Timer // 改进的延时
{
private:
	LARGE_INTEGER clock;
	LONGLONG lastClock;
	int frequency;

public:
	Timer();

	void Sleep(int ms);
};