#pragma once
#include "CFish.h"
class CAngie :
	public CFish
{
public:
	CAngie();
	virtual ~CAngie();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

