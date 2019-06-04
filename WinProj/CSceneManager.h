#pragma once
#include "CScene.h"
#include "singleton.h"
class CSceneManager  :public singleton<CSceneManager>
{
public:
	CSceneManager();
	~CSceneManager();
private:
	map <string, CScene*> m_Scenes;

	CScene * m_pCurScene = nullptr;
	CScene * m_pNextScene = nullptr;
public:
	void AddScene(const string& _Key, CScene * pScene);
	void ChangeScene(const string& _Key);
	void Update();
	void Render();
};

#define SCENE (*CSceneManager::GetInst())

