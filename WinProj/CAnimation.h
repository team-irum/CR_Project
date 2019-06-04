#pragma once
#include "CTimeManager.h"
class CAnimation
{
public:
	CAnimation(CTexture * _pTexture ,FLOAT _fDelay, INT _iMaxframe,INT _iLine,INT _iFrameline);
	~CAnimation();
public:
	void Update();
	void Render(const Vector2& _vPos, COLORREF _ColorKey = RGB(0, 0, 0));
private:
	CTexture * m_pTexture = nullptr;
	CTimer * m_pTimer = nullptr;
private:
	Vector2 m_vFramePos;
	int m_iFrameWidth;
	int m_iFrameHeight;

	float m_fDelay;
	float m_fTime = 0.f;
	int m_iCurrentFrame = 0;
	int m_iMaxFrame;

	DWORD m_iCurrentTime;
	DWORD m_iOldTime;
public:
	void SetFrame(int _iFrame) { m_vFramePos.x = m_iFrameWidth * m_iCurrentFrame; m_iCurrentFrame = _iFrame; }
	int GetFrame() { return m_iCurrentFrame; }
	int GetFrameWidth() { return m_iFrameWidth; }
	int GetFrameHeight() { return m_iFrameHeight; }
};

