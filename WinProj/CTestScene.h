#pragma once
#include "CScene.h"
#include "CFish.h"
#include "CSans.h"
class CTestScene : public CScene
{
public:
	CTestScene();
	~CTestScene();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	
private:
	vector <CFish *> m_Fishes;
	list <CSans *> m_Sanses;
};

