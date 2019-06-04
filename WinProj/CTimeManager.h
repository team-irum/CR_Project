#pragma once
#include "singleton.h"
#include "CTimer.h"
class CTimeManager :
	public singleton< CTimeManager>

{
public:
	CTimeManager();
	~CTimeManager();
public:
	FLOAT DeltaTime;
private:
	map<string, CTimer *> m_Timers;
	TimePoint m_NowTime;
public:
	CTimer * AddTimer(const string& _Key, CTimer * _pTimer);
	CTimer * FindTimer(const string& _Key);
	void RemoveTimer(const string& _Key);
	__inline TimePoint GetNowTime() { return m_NowTime; }

	void Update();
};

#define TIME (*CTimeManager::GetInst())
#define GetNowTimepoint chrono::system_clock::now()


