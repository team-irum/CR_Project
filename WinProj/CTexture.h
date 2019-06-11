#pragma once

class CTexture
{
public:
	CTexture(HBITMAP  _pTex);
	~CTexture();
private:
	HBITMAP  m_pTexture;
	HDC m_hDC;
	INT m_fWidth;
	INT m_fHeight;
public:
	INT GetWidth() { return       m_fWidth; }
	INT GetHeight() { return      m_fHeight;        }
	HBITMAP  GetBitmap() { return m_pTexture;  }
	HDC& GetDC() { return         m_hDC; }
	void Render(const Vector2& _vPos, COLORREF _ColorKey  = -1);
	void CropRender(const Vector2& _vPos,      const Vector2& _vCropPos, int _SrcW, int _SrcH,  COLORREF _ColorKey = -1);
};

