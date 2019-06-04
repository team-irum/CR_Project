#include "stdafx.h"
#include "CBlip.h"


CBlip::CBlip()
{
}


CBlip::~CBlip()
{

}

void CBlip::Init()
{
	m_pAnimation = new CAnimation(IMAGE["BLIP"], 0.1f, 10, 2, 1);
	m_pReverse = new CAnimation(IMAGE["BLIP_REVERSE"], 0.1f, 10, 2, 1);
	m_vPos = { 100,200 };

	m_fMovespeed = 150.f;
}

void CBlip::Update()
{
	m_pAnimation->Update();
	m_pReverse->SetFrame(m_pAnimation->GetFrame());
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

void CBlip::Render()
{
	if (m_iDir == -1)
		m_pAnimation->Render(m_vPos);
	else
		m_pReverse->Render(m_vPos);
}

void CBlip::Release()
{
	SAFE_DELETE(m_pAnimation);
	SAFE_DELETE(m_pReverse);
}
