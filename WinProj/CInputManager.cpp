#include "stdafx.h"
#include "CInputManager.h"


CInputManager::CInputManager()
{
}


CInputManager::~CInputManager()
{
}

void CInputManager::Update()
{
	memcpy(m_bLastInput, m_bCurInput, sizeof(m_bCurInput));
	for (int i = 0; i < 256; i++)
	{
		if (GetAsyncKeyState(i))
			m_bCurInput[i] = true;
		else m_bCurInput[i] = false;
	}
}

bool CInputManager::KeyDown(int Key)
{
	return m_bCurInput[Key] && !m_bLastInput[Key];
}

bool CInputManager::KeyUp(int Key)
{
	return !m_bCurInput[Key] && m_bLastInput[Key];
}

bool CInputManager::KeyPress(int Key)
{
	//printf("%d\n",m_bCurInput[Key] && m_bLastInput[Key]);
	return m_bCurInput[Key] && m_bLastInput[Key];
}

Vector2 CInputManager::GetMousePos()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(SYSTEM.GetHwnd(), &pt);
	return { (FLOAT)pt.x, (FLOAT)pt.y };
}

