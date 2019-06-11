#include "stdafx.h"
#include "CTexture.h"

CTexture::CTexture(HBITMAP _pTex)
	: m_pTexture(_pTex)
{
	BITMAP bit;
	GetObject(_pTex, sizeof(BITMAP), &bit);
	m_fWidth = bit.bmWidth;
	m_fHeight = bit.bmHeight;
	m_hDC = CreateCompatibleDC(IMAGE.GetMemDc());
	SelectObject(m_hDC, _pTex);
}

CTexture::~CTexture()
{
	DeleteObject(m_pTexture);
	DeleteDC(m_hDC);
}

void CTexture::Render(const Vector2 & _vPos, COLORREF _ColorKey)
{	
	IMAGE.Render(this, _vPos, _ColorKey);
}

void CTexture::CropRender(const Vector2 & _vPos, const Vector2 & _vCropPos, int _SrcW, int _SrcH, COLORREF _ColorKey)
{
	IMAGE.CropRender(this, _vPos, _vCropPos, _SrcW, _SrcH,_ColorKey);
}

