#pragma once
#include <windows.h>

//Ϊ�˷�ֹ��Ϸռ��CPU������Դ����
//#include "Timer.h"
//�������
//Timer timer; // ���ڸĽ�����ʱ
//Ȼ����Խ��з�����ʽ����ʱ���ڲ�ͬ���ܵļ������ͳһ��Ϸ�ٶ�


class Timer // �Ľ�����ʱ
{
private:
	LARGE_INTEGER clock;
	LONGLONG lastClock;
	int frequency;

public:
	Timer();

	void Sleep(int ms);
};