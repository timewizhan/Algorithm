#include "CheckTool.h"

std::vector<ST_QUEUE> vecQueue;
HANDLE hEvent;

CCheckTool::CCheckTool() : m_hThread(NULL)
{
}

CCheckTool::~CCheckTool()
{
}

DWORD CCheckTool::GetTimeAsSecond()
{
	if (!m_stCTTool.bStart)
		return 0;
	if (!m_stCTTool.bEnd)
		return 0;

	return (m_stCTTool.bEnd - m_stCTTool.bStart) / CLOCKS_PER_SEC;
}

DWORD CCheckTool::StartCTThread()
{
	hEvent = CreateEvent(NULL, TRUE, TRUE, NULL);
	if (!hEvent) {
		return 0;
	}

	m_hThread = (HANDLE)_beginthreadex(NULL, 0, CheckMemoryThread, NULL, 0, NULL);
	if (!m_hThread)
		return 0;

	return 1;
}

DWORD CCheckTool::EndCTThread()
{
	SetEvent(hEvent);
	WaitForSingleObject(m_hThread, INFINITE);

	return 1;
}

CCheckThread::CCheckThread()
{
}

CCheckThread::~CCheckThread()
{
}

DWORD CCheckThread::MainLoop()
{
	BOOL bContinued = TRUE;
	MEMORYSTATUSEX stMemory;
	stMemory.dwLength = sizeof(stMemory);

	DWORD dwWaitResult;
	while (bContinued) {
		dwWaitResult = WaitForSingleObject(hEvent, INFINITE);
		if (dwWaitResult != WAIT_OBJECT_0) {
			bContinued = FALSE;
			continue;
		}

		CheckMemory(stMemory);
		::Sleep(100);
	}

	return 0;
}

DWORD CCheckThread::CheckMemory(MEMORYSTATUSEX &refstMemory)
{	
	DWORDLONG ullRemainedValue;
	ullRemainedValue = refstMemory.ullTotalVirtual - refstMemory.ullAvailVirtual;

	ST_QUEUE stQueue;
	stQueue.ullMemory = ullRemainedValue;
	vecQueue.push_back(stQueue);

	return 1;
}

unsigned int WINAPI CheckMemoryThread(void *pArg)
{
	CCheckThread CheckThread;
	
	try
	{
		CheckThread.MainLoop();
	}
	catch (std::exception &e) {
		printf("%s\n", e.what());
	}

	return 0;
}