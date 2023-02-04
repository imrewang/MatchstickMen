#include"PlayMusicOnce.h"


void PlayMusicOnce(const TCHAR fileName[80]) // 播放一次音乐函数
{
	TCHAR cmdString1[50];
	_stprintf_s(cmdString1, _T("open %s alias tmpmusic"), fileName); // 生成命令字符串
	mciSendString(_T("close tmpmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
	mciSendString(cmdString1, NULL, 0, NULL); // 打开音乐
	mciSendString(_T("play tmpmusic"), NULL, 0, NULL); // 仅播放一次
}
