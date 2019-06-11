#include "stdafx.h"



ChangeRoomScene::ChangeRoomScene()
{
}


ChangeRoomScene::~ChangeRoomScene()
{
}

void ChangeRoomScene::Init()
{
	m_Buttons[BUTTON_TITLE] = new CButton();

	m_Buttons[BUTTON_TITLE]->Init(IMAGE["HomeButton1"], IMAGE["HomeButton2"], IMAGE["HomeButton3"], { 10, 10 });
}

void ChangeRoomScene::Update()
{
	for (auto& iter : m_Buttons)
	{
		iter.second->Update();
	}

	if (m_Buttons[BUTTON_TITLE]->IsClicked())
	{
		SCENE.ChangeScene("TitleScene");
	}
}

void ChangeRoomScene::Render()
{
	IMAGE["CRBG"]->Render({ 0,0 }, RGB(0, 0, 0));
	
	m_Buttons[BUTTON_TITLE]->Render(RGB(255, 0, 255));
}

void ChangeRoomScene::Release()
{
	for (auto iter : m_Buttons)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	m_Buttons.clear();
}
