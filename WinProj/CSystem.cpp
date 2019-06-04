#include "stdafx.h"
#include "CSystem.h"

CSystem::CSystem()
{
	m_fFPSMax = 144.f;  // 최대 FPS 제한
	m_fGameSpeed = 1.f; // 게임 속도
}


CSystem::~CSystem()
{
}

BOOL CSystem::WinInit(const wstring& pWinName)
{
	WNDCLASSEX wcex;

	HINSTANCE hInstance = GetModuleHandle(NULL);

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.hCursor = LoadCursor(0, IDC_ARROW);
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYICON));
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_MYICON));
	wcex.lpfnWndProc = this->WndProc;
	wcex.lpszClassName = pWinName.c_str();
	wcex.lpszMenuName = NULL;
	wcex.style = CS_HREDRAW | CS_VREDRAW;

	if (RegisterClassExW(&wcex) == NULL)	return FALSE;

	return TRUE;
}

void CSystem::WinCreate(const wstring& pClassName, const wstring& pWindowName, HINSTANCE hInst, int nWindowStyle, RECT rtWindowSize)
{
	g_hWnd = CreateWindowW(pClassName.c_str(), pWindowName.c_str(),
		nWindowStyle,
		rtWindowSize.left, rtWindowSize.top, rtWindowSize.right - rtWindowSize.left, rtWindowSize.bottom - rtWindowSize.top,
		NULL, NULL, hInst, NULL);

	ShowWindow(g_hWnd, SW_SHOW);
	UpdateWindow(g_hWnd);

}

VOID CSystem::MsgLoop()
{
	MSG		msg;

	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void CSystem::UpdateFPS()
{
	m_fDeltaTime = (m_iCurTime - m_iLastTime) * 0.001f;
	m_fTimeElapsed += m_fDeltaTime;
	m_iFramecount++;

	if (m_fTimeElapsed >= 1.f)
	{
		m_fFPS = (double)m_iFramecount / m_fTimeElapsed;
		printf("%d\n", (int)GetFPS());
		m_iFramecount = 0;
		m_fTimeElapsed = 0.f;
	}

	double dwInterval = 1000.f / m_fFPSMax;
	m_dwElapsedTicks = timeGetTime() - m_dwCurrentTicks;
	//마지막 루프 순회 직후 부터 루프를 다시 시작하는 시점 까지의 경과 시간, 즉 공백 시간이다.

	if ((1000.f / (float)m_dwElapsedTicks) > m_fFPSMax && dwInterval - m_dwElapsedTicks > 0)
	{
		Sleep(dwInterval - m_dwElapsedTicks);
	}
	//위의 조건문은 dwCurrentTicks을 초기화 하지 않고서 최초로 루프에 진입 하였을 경우 경과 시간이 굉장히 큰 값이 나와 Slepp()의 인자 값이 음수가 되어 기약 없이 블럭 상태에서 헤어 나오지 못하는 일이 생긴다. 위의 조건문은 이를 방지하기 위한 조건문이다. 
    //그러나 처음에 dwCurrentCount 값을 0으로 초기화 한다고 하더라도 대개 dwElapsedTicks의 값이 0이 되기 때문에  1000/(float)dwElapsedTicks은 1000/0.0이 되어 그 결과 값은 0으로 나눴을때의 에러 값인 무한대(1.#INF)가 나오므로 이 조건문은 처음 한 번과 경과 시간이 FPS를 위한 대기 시간(30FPS일때 33ms)보다 큰 경우를 제외 하고는 매번 참이 되어 Sleep() 함수가 호출 된다.


	//(1000/(float)dwElapsedTicks) : 지금 현재의 FPS를 나타내며 목표 FPS와는 별개다.
	//1000/FPS:해당 FPS를 유지하기 위해 루프 1순회 당 소요 되어야 하는 ms 시간----A
	//A식 결과 값 - 루프간 공백 시간 : 30프레임에 맞추기 위해서는 루프 1순회당 33ms 씩 지연 되어야 하므로 공백 시간이 없으면 33ms 동안 그대로 대기
	//만약 루프간 공백 시간이 10ms가 생겼다면 정해진 지연시간인 33ms를 맞추기 위해 33ms-10ms의 결과 값인 23ms 동안만 대기 시킨다.
	m_dwElapsedTicks = timeGetTime() - m_dwCurrentTicks;
	m_dwCurrentTicks += m_dwElapsedTicks;//Sleep()에서 지연된 시간을 다시금 경과 시간에 누적 시킨다.


}

bool CSystem::OnCreate()
{
	m_iLastTime = timeGetTime();
	m_iCurTime = timeGetTime();
	m_iOldTime = timeGetTime();
	m_fFPS = m_fFPSMax;
	m_iFramecount = 0;
	m_fTimeElapsed = 0.f; 
	m_bIsActive = true;
	return true;
}

bool CSystem::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	//ptMouse.x = LOWORD(lParam);
	//ptMouse.y = HIWORD(lParam);

	return 1;
}

bool CSystem::OnTimer()
{
	
	return 1;
}

bool CSystem::OnDestroy()
{
	m_bIsActive = false;
	return true;
}

LRESULT CALLBACK CSystem::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		return SYSTEM.OnCreate();

	case WM_TIMER:
		return SYSTEM.OnTimer();

	case WM_MOUSEMOVE:
		return SYSTEM.OnMouseMove(wParam, lParam);

	case WM_PAINT:
	{
		break;
	}
	case WM_CLOSE:
	case WM_DESTROY:
		return SYSTEM.OnDestroy();
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void CSystem::Run()
{
	MSG	msg;

	msg.message = NULL;
	m_pMainGame = new CMainGame();
	m_pMainGame->Init();
	while (m_bIsActive)
	{


		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (m_bIsActive == true)
		{
			m_iCurTime = timeGetTime();

			UpdateFPS();
			m_pMainGame->Update();
			m_pMainGame->Render();

			m_iLastTime = m_iCurTime;

		}


	}
	m_pMainGame->Release();
	delete m_pMainGame;
	m_pMainGame = nullptr;

}

