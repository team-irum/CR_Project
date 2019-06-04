#pragma once
class CFish abstract
{
public:
	CFish();
	virtual ~CFish();
public:
	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
protected:
	Vector2 m_vPos;
	CAnimation * m_pAnimation = nullptr;
	CAnimation * m_pReverse = nullptr;
	int m_iDir = -1;
	FLOAT m_fMovespeed;

};

