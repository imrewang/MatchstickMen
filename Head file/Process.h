#pragma once

#include "PlayMusicOnce.h"
#include "Timer.h"
#include "Player.h"
#include <time.h>
#include <conio.h>


// һЩȫ�ֱ���
extern Player player;  // ������ҿ��Ƶ���Ϸ��ɫ����
extern Scene scene;  // ���峡��ȫ�ֶ���
extern Timer timer;  // ���ھ�ȷ��ʱ

void startup();  // ��ʼ��

void show(); // ��ʾ

void updateWithoutInput(); // �������޹صĸ���

void updateWithInput(); // �������йصĸ���
