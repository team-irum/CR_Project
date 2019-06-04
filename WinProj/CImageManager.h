#pragma once
#include "singleton.h"
class CImageManager :
	public singleton< CImageManager>
{
public:
	CImageManager();
	~CImageManager();
private:
	
	HDC m_hDC;
	HDC	m_hMemDC; // HDC를 하나더 선언해준다. HDC는 '그리는 작업' 이다.

	HBITMAP m_hBitmap;
	HBITMAP	m_OldBitmap; // HBITMAP은 대략 종이를 의미한다. 종이 2장 선언
	
	PAINTSTRUCT m_Ps;
	HBITMAP	m_hBmpBuffer;
	
	HBRUSH m_hBrush;
	HBRUSH m_hOldBrush;

	HPEN	m_hMyPen;
	HPEN	m_hOldPen;
private:
	map<string, CTexture *> m_Textures;
public:
	void Begin();
	void End();

	HDC& GetMemDc() { return m_hMemDC; }

	CTexture * AddTexture(const string& _Key, const string& _Path);
	CTexture * FindTexture(const string& _Key);
	void Render(CTexture* _pTexture, const Vector2& _vPos, COLORREF _ColorKey);
	void CropRender(CTexture* _pTexture, const Vector2& _vPos,const Vector2& _vCropPos,int _SrcW, int _SrcH,COLORREF _ColorKey);
	//void CropRender();

	CTexture * operator [] (const string& _Key)
	{
		return m_Textures[_Key];
	}
};

#define IMAGE (*CImageManager::GetInst())