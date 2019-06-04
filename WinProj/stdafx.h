// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 특정 포함 파일이 들어 있는
// 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <timeapi.h>
#include <ole2.h> 
#include <map>
#include <functional>
#include <vector>
#include <list>
#include <time.h>
#include <chrono>
#include <algorithm>
#include <string>
#include <mmsystem.h>
#include <Digitalv.h>
using namespace std;
using namespace chrono;

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "msimg32.lib")

const INT WINSIZEX = 640; // 창 넓이
const INT WINSIZEY = 960; // 창 높이

using Vector2 = POINTFLOAT;

using Second = chrono::duration<double>;
using TimePoint = system_clock::time_point;
#ifndef SAFE_DELETE
#define SAFE_DELETE(p)       { if (p) { delete (p);     (p)=NULL; } }
#endif    
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p);   (p)=NULL; } }
#endif    
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if (p) { (p)->Release(); (p)=NULL; } }
#endif

#define LP(obj) (*obj)
using namespace std;
// 여기서 프로그램에 필요한 추가 헤더를 참조합니다.
#include "Resource.h"

#include "singleton.h"
#include "CSystem.h"
#include "CTexture.h"
#include "CAnimation.h"
#include "CImageManager.h"
#include "CSceneManager.h"
#include "CInputManager.h"
#include "CSoundManager.h"
#include "CScene.h"
#include "CSound.h"
#include "CTimeManager.h"
#include "CTimer.h"
#include "CButton.h"

#include "CMainGame.h"

#include "CTitleScene.h"
#include "CTestSCene.h"