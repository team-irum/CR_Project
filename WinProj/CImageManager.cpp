#include "stdafx.h"
#include "CImageManager.h"


CImageManager::CImageManager()
{
	m_hDC = GetDC(GetHWND); // �׸��� ����
	m_hMemDC = CreateCompatibleDC(m_hDC); // hMemDC �� ���� DC (hdc)�� �°� �� DC ����
	m_hBitmap = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY); // crt �԰ݴ�� ���� ����
	m_OldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap); // ���� ��ü

	m_hBrush = CreateSolidBrush(RGB(255, 255, 255));
	m_hOldBrush = (HBRUSH)SelectObject(m_hMemDC, m_hBrush);

	m_hMyPen = CreatePen(PS_SOLID, 0, RGB(255, 255, 255));
	m_hOldPen = (HPEN)SelectObject(m_hMemDC, m_hMyPen);

}


CImageManager::~CImageManager()
{
	for (auto iter : m_Textures)
	{
		SAFE_DELETE(iter.second);
	}
	m_Textures.clear();

	DeleteObject(SelectObject(m_hMemDC, m_OldBitmap)); // ���� ������� �� �� ����
	DeleteObject(SelectObject(m_hMemDC, m_hOldPen));
	DeleteObject(SelectObject(m_hMemDC, m_hOldBrush));
	DeleteDC(m_hMemDC); // hMemDC ����
	ReleaseDC(GetHWND, m_hDC);// �׸��� ����
}

void CImageManager::Begin()
{
	InvalidateRect(GetHWND, NULL, FALSE);

	Rectangle(m_hMemDC, 0, 0, WINSIZEX, WINSIZEY);
}
void CImageManager::Render(CTexture * _pTexture, const Vector2 & _vPos, COLORREF _ColorKey)
{
	INT w = _pTexture->GetWidth();
	INT h = _pTexture->GetHeight();
			TransparentBlt(
		m_hMemDC,
		_vPos.x,
		_vPos.y,
		w,
		h,
		_pTexture->GetDC(),
		0,
		0,
		w,
		h,
		_ColorKey);
	
}
void CImageManager::End()
{
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY); // �貸�׸���
}

CTexture * CImageManager::AddTexture(const string & _Key, const string & _Path)
{
	auto find = FindTexture(_Key);
	if (find == nullptr)
	{
		HBITMAP  hImage = (HBITMAP)LoadImageA(NULL, _Path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		if (hImage != nullptr)
		{
			m_Textures[_Key] = new CTexture(hImage);
			return m_Textures[_Key];
		}
		return nullptr;
	}
	else return find;
}

CTexture * CImageManager::FindTexture(const string & _Key)
{
	auto find = m_Textures.find(_Key);
	if (find == m_Textures.end())
		return nullptr;
	else
		return find->second;

}


void CImageManager::CropRender(CTexture * _pTexture, const Vector2 & _vPos, const Vector2 & _vCropPos, int _SrcW, int _SrcH, COLORREF _ColorKey)
{
	INT w = _pTexture->GetWidth();
	INT h = _pTexture->GetHeight();


		TransparentBlt(
			m_hMemDC,
			_vPos.x,
			_vPos.y,
			_SrcW,
			_SrcH,
			_pTexture->GetDC(),
			_vCropPos.x,
			_vCropPos.y,
			_SrcW,
			_SrcH,
			_ColorKey);
}

