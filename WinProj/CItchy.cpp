#include "stdafx.h"
#include "CItchy.h"


CItchy::CItchy()
{
}


CItchy::~CItchy()
{
}

void CItchy::Init()
{
	m_pAnimation = new CAnimation(IMAGE["ITCHY"], 0.1f, 10, 4, 1);
	m_pReverse = new CAnimation(IMAGE["ITCHY_REVERSE"], 0.1f, 10, 4, 1);
	m_vPos = { 100,200 };

	m_fMovespeed = 200.f;
}

void CItchy::Update()
{
	m_pAnimation->Update();
	m_pReverse->SetFrame(m_pAnimation->GetFrame());
	m_vPos.x += m_fMovespeed * SYSTEM.GetDeltaTime() * m_iDir;

	if (m_vPos.x + m_pAnimation->GetFrameWidth() < 0)
	{
		m_vPos.y = rand() % (WINSIZEY - m_pAnimation->GetFrameHeight() + 30);
		m_iDir = 1;
	}
	else if (m_vPos.x > WINSIZEX)
	{
		m_vPos.y = rand() % (WINSIZEY - m_pAnimation->GetFrameHeight() + 30);
		m_iDir = -1;
	}
}

void CItchy::Render()
{
	if (m_iDir == -1)
		m_pAnimation->Render(m_vPos);
	else
		m_pReverse->Render(m_vPos);
}

void CItchy::Release()
{
	SAFE_DELETE(m_pAnimation);
	SAFE_DELETE(m_pReverse);
}
