#include "stdafx.h"
#include "CGash.h"


CGash::CGash()
{
}


CGash::~CGash()
{
}

void CGash::Init()
{
	m_pAnimation = new CAnimation(IMAGE["GASH"], 0.1f, 10, 3, 1);
	m_pReverse = new CAnimation(IMAGE["GASH_REVERSE"], 0.1f, 10, 3, 1);
	m_vPos = { 100,200 };

	m_fMovespeed = 150.f;
}

void CGash::Update()
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

void CGash::Render()
{
	if (m_iDir == -1)
		m_pAnimation->Render(m_vPos);
	else
		m_pReverse->Render(m_vPos);
}

void CGash::Release()
{
	SAFE_DELETE(m_pAnimation);
	SAFE_DELETE(m_pReverse);
}
