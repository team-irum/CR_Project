#pragma once
#include "CFish.h"
class COctopus :
	public CFish
{
public:
	COctopus();
	~COctopus();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

