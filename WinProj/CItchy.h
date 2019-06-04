#pragma once
#include "CFish.h"
class CItchy :
	public CFish
{
public:
	CItchy();
	~CItchy();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

