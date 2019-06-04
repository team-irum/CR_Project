#pragma once
#include "CFish.h"
class CSans
:	public CFish 
{
public:
	CSans();
	~CSans();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
private:
	bool m_bIsdead;

public:
	bool Isdead() { return m_bIsdead; }
};

