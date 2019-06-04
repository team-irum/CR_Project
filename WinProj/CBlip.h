#pragma once
#include "CFish.h"
class CBlip : public CFish
{
public:
	CBlip();
	~CBlip();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

