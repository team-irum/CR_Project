#include "stdafx.h"
#include "CAngie.h"


CAngie::CAngie()
{
}


CAngie::~CAngie()
{
}

void CAngie::Init()
{
	m_pAnimation = new CAnimation(IMAGE["ANGIE"], 0.1f, 10, 2, 1);
	m_pReverse = new CAnimation(IMAGE["ANGIE_REVERSE"], 0.1f, 10, 2, 1);
	m_vPos = { 100,200 };

	m_fMovespeed = 100.f;
}

void CAngie::Update()
{
	m_pAnimation->Update();
	m_pReverse->SetFrame(m_pAnimation->GetFrame());

	if (INPUT.KeyDown(VK_SPACE))
		m_iDir = -m_iDir;

	m_vPos.x += m_fMovespeed * SYSTEM.GetDeltaTime() * m_iDir;

	if (m_vPos.x + m_pAnimation->GetFrameWidth() < 0)
	{
		m_vPos.y = rand() % (WINSIZEY - m_pAnimation->GetFrameHeight()+30);
		m_iDir = 1;
	}
	else if (m_vPos.x > WINSIZEX)
	{
		m_vPos.y = rand() % (WINSIZEY - m_pAnimation->GetFrameHeight()+30);
		m_iDir = -1;
	}
}

void CAngie::Render()
{
	if (m_iDir == -1)
		m_pAnimation->Render(m_vPos);
	else
		m_pReverse->Render(m_vPos);
}

void CAngie::Release()
{
	SAFE_DELETE(m_pAnimation);
	SAFE_DELETE(m_pReverse);
}
