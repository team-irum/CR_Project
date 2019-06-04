#pragma once
#include "CFish.h"
class CGash : public CFish
{
public:
	CGash();
	~CGash();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

