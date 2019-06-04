#include "stdafx.h"
#include "COctopus.h"


COctopus::COctopus()
{
}


COctopus::~COctopus()
{
}

void COctopus::Init()
{
	m_pAnimation = new CAnimation(IMAGE["OCTOPUS"], 0.1f, 10, 2, 1);
	m_pReverse = new CAnimation(IMAGE["OCTOPUS_REVERSE"], 0.1f, 10, 2, 1);
	m_vPos = { 100.f,(FLOAT)(WINSIZEY - m_pAnimation->GetFrameHeight() - 30) };

	m_fMovespeed = 30.f;
}

void COctopus::Update()
{
	m_pAnimation->Update();
	m_pReverse->SetFrame(m_pAnimation->GetFrame());
	m_vPos.x += m_fMovespeed * SYSTEM.GetDeltaTime() * m_iDir;

	if (m_vPos.x + m_pAnimation->GetFrameWidth() < 0)
	{
		m_iDir = 1;
	}
	else if (m_vPos.x > WINSIZEX)
	{
		m_iDir = -1;
	}
}

void COctopus::Render()
{
	if (m_iDir == -1)
		m_pAnimation->Render(m_vPos);
	else
		m_pReverse->Render(m_vPos);
}

void COctopus::Release()
{
	SAFE_DELETE(m_pAnimation);
	SAFE_DELETE(m_pReverse);
}
