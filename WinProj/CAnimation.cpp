#include "stdafx.h"
#include "CAnimation.h"

CAnimation::CAnimation(CTexture * _pTexture, FLOAT _fDelay, INT _iMaxframe, INT _iLine, INT _iFrameline)
	: m_pTexture(_pTexture),m_fDelay(_fDelay),m_iMaxFrame(_iMaxframe)
{
	m_iCurrentTime = timeGetTime();
	m_iOldTime = timeGetTime();
	m_iFrameWidth = _pTexture->GetWidth() / _iMaxframe;
	m_iFrameHeight = _pTexture->GetHeight() / _iLine;

	m_vFramePos = { 0.f,(FLOAT)((_iFrameline - 1) * m_iFrameHeight) };
}

CAnimation::~CAnimation()
{
}

void CAnimation::Update()
{
	m_iCurrentTime = timeGetTime();
	/*if (m_iCurrentTime - m_iOldTime > m_fDelay * 1000)
	{
		m_iOldTime = m_iCurrentTime;
		m_iCurrentFrame++;
		m_vFramePos.x += m_iFrameWidth;
		if (m_iCurrentFrame == m_iMaxFrame)
		{
			m_vFramePos.x = 0;
			m_iCurrentFrame = 0;
		}
	}*/
	
	if (m_fTime >= m_fDelay)
	{
		m_fTime = 0.f;
		m_iCurrentFrame++;
		m_vFramePos.x += m_iFrameWidth;
		if (m_iCurrentFrame == m_iMaxFrame)
		{
			m_vFramePos.x = 0;
			m_iCurrentFrame = 0;
		}
	}
	else m_fTime += SYSTEM.GetDeltaTime();
}

void CAnimation::Render(const Vector2 & _vPos, COLORREF _ColorKey)
{
	m_pTexture->CropRender(
		_vPos,
		m_vFramePos,
		m_iFrameWidth,
		m_iFrameHeight,
		_ColorKey
	);

}
