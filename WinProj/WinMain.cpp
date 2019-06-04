// WinProj.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "WinProj.h"
#include "CSystem.h"
#include <crtdbg.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nShowCmd)
{
#if _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	AllocConsole();
	freopen("CONOUT$", "a", stdout);
	freopen("CONOUT$", "a", stderr);
	freopen("CONIN$", "r", stdin); 
#endif
	srand(timeGetTime());

	RECT rtSystemSize = { 1920/2 - WINSIZEX/2, 1080/2 - WINSIZEY/2, 1920/2 +WINSIZEX/2 , 1080/2 +WINSIZEY/2 };

	SYSTEM.WinInit(L"팀 영식쌤과하수인들");
	
	SYSTEM.WinCreate(L"팀 영식쌤과하수인들", L"百花燎亂", hInst, WS_OVERLAPPEDWINDOW, rtSystemSize);

	SYSTEM.Run();

	CSystem::ReleaseInst();

	FreeConsole();

	return 0;
}