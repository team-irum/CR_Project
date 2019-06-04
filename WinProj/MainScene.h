#pragma once
#include "CScene.h"

class MainScene : public CScene
{
public:
	MainScene();
	~MainScene();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

