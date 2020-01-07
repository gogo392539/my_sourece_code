#include "stdafx.h"
#include "C_TIME.h"

void C_TIME::getCurrentTime(char *pTime, const int nLen)
{
	char szTime[100] = { 0, };
	errno_t errNo = 0;
	time_t tTimer = 0;
	struct tm sTimer = { 0, };

	tTimer = time(NULL);
	errNo = localtime_s(&sTimer, &tTimer);

	cout << "초 : " << tTimer << endl;
	cout <<sTimer.tm_year + 1900 << "년-" <<sTimer.tm_mon + 1 << "월-" <<sTimer.tm_mday << "일 " <<sTimer.tm_hour << "시:" <<sTimer.tm_min << "분:" <<sTimer.tm_sec << "초" << endl;

	sprintf_s(szTime, 100, "%d년-%d월-%d일 %d시:%d분:%d초", sTimer.tm_year + 1900, sTimer.tm_mon + 1, sTimer.tm_mday, sTimer.tm_hour, sTimer.tm_min, sTimer.tm_sec);

	strcpy_s(pTime, nLen, szTime);
}

void C_TIME::getCurrentTime2(char *pTime, const int nLen)
{
	char szTime[100] = { 0, };
	errno_t errNo = 0;
	time_t tTimer = 0;
	struct tm sTimer = { 0, };

	time(&tTimer);
	errNo = localtime_s(&sTimer, &tTimer);

	strftime(szTime, sizeof(szTime), "%Y-%m-%d %H:%M:%S", &sTimer);

	cout << szTime << endl;

	strcpy_s(pTime, nLen, szTime);
}
