#include"PlayMusicOnce.h"


void PlayMusicOnce(const TCHAR fileName[80]) // ����һ�����ֺ���
{
	TCHAR cmdString1[50];
	_stprintf_s(cmdString1, _T("open %s alias tmpmusic"), fileName); // ���������ַ���
	mciSendString(_T("close tmpmusic"), NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
	mciSendString(cmdString1, NULL, 0, NULL); // ������
	mciSendString(_T("play tmpmusic"), NULL, 0, NULL); // ������һ��
}
