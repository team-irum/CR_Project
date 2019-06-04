#include "stdafx.h"
#include "CSans.h"


CSans::CSans()
{
}


CSans::~CSans()
{
}

void CSans::Init()
{
	m_pAnimation = new CAnimation(IMAGE["SANS"], 0.1f, 1, 1, 1);
	m_pReverse = new CAnimation(IMAGE["SANS_REVERSE"], 0.1f, 1, 1, 1);
	int Rand = rand() % 4;
	switch(Rand)
	{
	case 0:
		m_iDir = 0;
		m_vPos.x = (FLOAT)WINSIZEX;
		m_vPos.y = FLOAT(rand() % WINSIZEY);
		break;
	case 1:
		m_iDir = 1;
		m_vPos.x = -600;
		m_vPos.y = FLOAT(rand() % WINSIZEY);
		break;
	case 2:
		m_iDir = 2;
		m_vPos.x = FLOAT(rand() % WINSIZEX);
		m_vPos.y = FLOAT(WINSIZEY);
		break;
	case 3:
		m_iDir = 3;
		m_vPos.x = FLOAT(rand() % WINSIZEX);
		m_vPos.y = -600;
		break;
	}
	m_fMovespeed = 2000.f;
}

void CSans::Update()
{
	m_pAnimation->Update();
	m_pReverse->SetFrame(m_pAnimation->GetFrame());
	switch (m_iDir)
	{
	case 0:
		m_vPos.x += m_fMovespeed * SYSTEM.GetDeltaTime() * -1;
		if (m_vPos.x + m_pAnimation->GetFrameWidth() < 0)
		{
			m_bIsdead = true;
		}
		break;
	case 1:
		m_vPos.x += m_fMovespeed * SYSTEM.GetDeltaTime();
		if (m_vPos.x > WINSIZEX)
		{
			m_bIsdead = true;
		}
		break;
	case 2:
		m_vPos.y -= m_fMovespeed * SYSTEM.GetDeltaTime();
		if (m_vPos.y + m_pAnimation->GetFrameHeight() < 0)
		{
			m_bIsdead = true;
		}
		break;
	case 3:
		m_vPos.y += m_fMovespeed * SYSTEM.GetDeltaTime();
		 if (m_vPos.y > WINSIZEY)
		{
			m_bIsdead = true;
		}
		break;
	}


}

void CSans::Render()
{
	if (m_iDir == -1)
		m_pAnimation->Render(m_vPos,RGB(255,0,255));
	else
		m_pReverse->Render(m_vPos, RGB(255, 0, 255));
}

void CSans::Release()
{
	SAFE_DELETE(m_pAnimation);
	SAFE_DELETE(m_pReverse);
}
