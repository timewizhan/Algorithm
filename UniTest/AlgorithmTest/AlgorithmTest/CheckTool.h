#ifndef CHECK_TOOL
#define CHECK_TOOL

#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include <process.h>
#include <iostream>
#include <vector>

struct ST_QUEUE
{
	DWORDLONG ullMemory;
};

struct ST_CTTool
{
	BOOL bStart;
	BOOL bEnd;

	DWORDLONG ullStartTime;
	DWORDLONG ullEndTime;

	ST_CTTool() : bStart(FALSE), bEnd(FALSE), ullStartTime(0), ullEndTime(0) {}
};

class CCheckTool
{
	ST_CTTool	m_stCTTool;
	HANDLE		m_hThread;
public:
	CCheckTool();
	~CCheckTool();

	/*
		Below is Timer methods
	*/
	DWORD StartTimer() {
		m_stCTTool.bStart = TRUE;
		m_stCTTool.ullStartTime = clock();
	}
	DWORD EndTimer() {
		m_stCTTool.bEnd = FALSE;
		m_stCTTool.ullEndTime = clock();
	}
	DWORD GetTimeAsSecond();

	/*
		Below is Memory Check Thread
	*/
	DWORD StartCTThread();
	DWORD EndCTThread();
};

class CCheckThread
{
	DWORD CheckMemory(MEMORYSTATUSEX &refstMemory);
public:
	CCheckThread();
	~CCheckThread();

	DWORD MainLoop();
};

unsigned int WINAPI CheckMemoryThread(void *pArg);


#endif