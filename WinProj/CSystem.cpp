#include "stdafx.h"
#include "CSystem.h"

CSystem::CSystem()
{
	m_fFPSMax = 144.f;  // �ִ� FPS ����
	m_fGameSpeed = 1.f; // ���� �ӵ�
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
	//������ ���� ��ȸ ���� ���� ������ �ٽ� �����ϴ� ���� ������ ��� �ð�, �� ���� �ð��̴�.

	if ((1000.f / (float)m_dwElapsedTicks) > m_fFPSMax && dwInterval - m_dwElapsedTicks > 0)
	{
		Sleep(dwInterval - m_dwElapsedTicks);
	}
	//���� ���ǹ��� dwCurrentTicks�� �ʱ�ȭ ���� �ʰ� ���ʷ� ������ ���� �Ͽ��� ��� ��� �ð��� ������ ū ���� ���� Slepp()�� ���� ���� ������ �Ǿ� ��� ���� �� ���¿��� ��� ������ ���ϴ� ���� �����. ���� ���ǹ��� �̸� �����ϱ� ���� ���ǹ��̴�. 
    //�׷��� ó���� dwCurrentCount ���� 0���� �ʱ�ȭ �Ѵٰ� �ϴ��� �밳 dwElapsedTicks�� ���� 0�� �Ǳ� ������  1000/(float)dwElapsedTicks�� 1000/0.0�� �Ǿ� �� ��� ���� 0���� ���������� ���� ���� ���Ѵ�(1.#INF)�� �����Ƿ� �� ���ǹ��� ó�� �� ���� ��� �ð��� FPS�� ���� ��� �ð�(30FPS�϶� 33ms)���� ū ��츦 ���� �ϰ�� �Ź� ���� �Ǿ� Sleep() �Լ��� ȣ�� �ȴ�.


	//(1000/(float)dwElapsedTicks) : ���� ������ FPS�� ��Ÿ���� ��ǥ FPS�ʹ� ������.
	//1000/FPS:�ش� FPS�� �����ϱ� ���� ���� 1��ȸ �� �ҿ� �Ǿ�� �ϴ� ms �ð�----A
	//A�� ��� �� - ������ ���� �ð� : 30�����ӿ� ���߱� ���ؼ��� ���� 1��ȸ�� 33ms �� ���� �Ǿ�� �ϹǷ� ���� �ð��� ������ 33ms ���� �״�� ���
	//���� ������ ���� �ð��� 10ms�� ����ٸ� ������ �����ð��� 33ms�� ���߱� ���� 33ms-10ms�� ��� ���� 23ms ���ȸ� ��� ��Ų��.
	m_dwElapsedTicks = timeGetTime() - m_dwCurrentTicks;
	m_dwCurrentTicks += m_dwElapsedTicks;//Sleep()���� ������ �ð��� �ٽñ� ��� �ð��� ���� ��Ų��.


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

