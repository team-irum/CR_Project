#include "stdafx.h"
#include "CButton.h"


CButton::CButton()
{
}


CButton::~CButton()
{
}




void CButton::Init(CTexture * _pNormal, CTexture * _pOnCursor, CTexture * _pOnPress, Vector2 _vPos)
{
	m_Status = Normal;
	m_Textures[Normal] = _pNormal;
	m_Textures[OnCursor] = _pOnCursor;
	m_Textures[OnPress] = _pOnPress;

	m_bIsClicked = false;
	m_vPos = _vPos;

	m_reRect =
	{
		(LONG)(m_vPos.x),
		(LONG)(m_vPos.y),
		(LONG)(m_vPos.x + _pNormal->GetWidth()),
		(LONG)(m_vPos.y + _pNormal->GetHeight()),
	};
}

void CButton::Update()
{
	POINT _vMousePos = { INPUT.GetMousePos().x,INPUT.GetMousePos().y };


	bool isCollision = PtInRect(&m_reRect, _vMousePos);

	if (!isCollision)
	{
		m_Status = Normal;
		m_bIsClicked = false;
	}
	else
	{
		switch (m_Status)
		{
		case Normal:
			m_bIsClicked = false;
			if (isCollision == true)
				m_Status = OnCursor;

			break;
		case OnCursor:
			m_bIsClicked = false;
			if (INPUT.KeyPress(VK_LBUTTON))
				m_Status = OnPress;
			break;
		case OnPress:
			m_bIsClicked = false;
			if (INPUT.KeyUp(VK_LBUTTON))
			{
				m_Status = Normal;
				m_bIsClicked = true;
			}
			break;
		}
	}
}

void CButton::Render(COLORREF _ColorKey)
{
	m_Textures[m_Status]->Render(m_vPos, _ColorKey);
}

void CButton::Release()
{

}
