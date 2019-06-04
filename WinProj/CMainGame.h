#pragma once
#include "CScene.h"
class CMainGame : public CScene
{
public:
	CMainGame();
	~CMainGame();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

