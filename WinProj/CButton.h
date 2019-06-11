#pragma once

enum ButtonStatus
{
	Normal,
	OnCursor,
	OnPress
};
class CButton
{
public:
	CButton();
	~CButton();
public:
	void Init(
		CTexture * _pNormal,
		CTexture * _pOnCursor,
		CTexture * _pOnPress,
		Vector2 _vPos);
	void Update();
	void Render(COLORREF _ColorKey = -1);
	void Release();

	bool IsClicked() { return m_bIsClicked; }
private: 
	map<ButtonStatus, CTexture*> m_Textures;
	ButtonStatus m_Status;
	Vector2 m_vPos;
	RECT m_reRect;

	bool m_bIsClicked;
};

