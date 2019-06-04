#pragma once
#include "CFish.h"
class CAmp :
	public CFish
{
public:
	CAmp();
	~CAmp();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

