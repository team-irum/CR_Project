#pragma once
#include "CMainGame.h"
class CSystem :public singleton<CSystem>
{
public:
	CSystem();
	~CSystem();
	HWND g_hWnd;
	bool m_bIsActive = true;
public:
	BOOL WinInit(const wstring& pWinName);
	void WinCreate(const wstring& pClassName, const wstring& pWindowName, HINSTANCE hInst, int nWindowStyle, RECT rtWindowSize);
	VOID MsgLoop();

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void Run();
	float GetDeltaTime() { return m_fDeltaTime * m_fGameSpeed; }
	float GetFPS() { return m_fFPS; }
	float GetFPSMax() { return m_fFPSMax; }
	HWND& GetHwnd() { return g_hWnd; }
	VOID SetSpeed(float _fSpeed) { 
		m_fGameSpeed = _fSpeed; }
	float GetSpeed() { return m_fGameSpeed; }
private:
	CMainGame * m_pMainGame = nullptr;
	DWORD m_iCurTime;
	DWORD m_iLastTime;
	DWORD m_iOldTime;
	FLOAT m_fDeltaTime = 0.f; // 프레임과의 시간차이
	FLOAT m_fFPS; // FPS
	DWORD m_iFramecount; 
	FLOAT m_fTimeElapsed = 0.f;
	FLOAT m_fFPSMax; // 최대 FPS
	FLOAT m_fGameSpeed ; // 게임속도

	DWORD m_dwElapsedTicks = 0;
	DWORD m_dwCurrentTicks = 0;

private:
	void UpdateFPS();
	bool OnCreate();
	bool OnTimer();
	bool OnDestroy();
	bool OnMouseMove(WPARAM wParam, LPARAM lParam);
};


#define SYSTEM (*CSystem::GetInst())
#define GetHWND SYSTEM.GetHwnd() 