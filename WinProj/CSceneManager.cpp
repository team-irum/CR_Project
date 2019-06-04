#include "stdafx.h"
#include "CSceneManager.h"


CSceneManager::CSceneManager()
{
}


CSceneManager::~CSceneManager()
{
	if(m_pCurScene)m_pCurScene->Release();
	if (m_pNextScene) m_pNextScene->Release();
	for (auto iter : m_Scenes)
	{
		SAFE_DELETE(iter.second);
	}
}

void CSceneManager::AddScene(const string & _Key, CScene * pScene)
{
	auto find = m_Scenes.find(_Key);
	if (find == m_Scenes.end())
	{
		m_Scenes[_Key] = pScene;
	}
}

void CSceneManager::ChangeScene(const string & _Key)
{
	auto find = m_Scenes.find(_Key);
	if (find != m_Scenes.end())
	{
		m_pNextScene = m_Scenes[_Key];
	}
}

void CSceneManager::Update()
{
	if (m_pCurScene)
		m_pCurScene->Update();

	if (m_pNextScene)
	{
		if(m_pCurScene)
			m_pCurScene->Release();
		m_pNextScene->Init();
		m_pCurScene = m_pNextScene;
		m_pNextScene = nullptr;
	}
}

void CSceneManager::Render()
{
	if (m_pCurScene)
		m_pCurScene->Render();
}
