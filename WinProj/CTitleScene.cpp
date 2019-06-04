#include "stdafx.h"

bool Credit = false;//Å©·¹µ÷È­¸é

CTitleScene::CTitleScene()
{
	
}

CTitleScene::~CTitleScene()
{
}

void CTitleScene::Init()
{
	
	m_Buttons[BUTTON_START] = new CButton();
	m_Buttons[BUTTON_CREDIT] = new CButton();
	m_Buttons[BUTTON_EXIT] = new CButton();
	
	m_Buttons[BUTTON_START]->Init(IMAGE["StartButton1"], IMAGE["StartButton2"], IMAGE["StartButton3"], {40, 600});
	m_Buttons[BUTTON_CREDIT]->Init(IMAGE["CreditButton1"], IMAGE["CreditButton2"], IMAGE["CreditButton3"], { 240, 600 });
	m_Buttons[BUTTON_EXIT]->Init(IMAGE["ExitButton1"], IMAGE["ExitButton2"], IMAGE["ExitButton3"], { 440, 600 });

}

void CTitleScene::Update()
{
	for (auto& iter : m_Buttons)
	{
		iter.second->Update();
	}

	if (m_Buttons[BUTTON_START]->IsClicked())
	{
		SCENE.ChangeScene("TestScene");
	}

	if (m_Buttons[BUTTON_CREDIT]->IsClicked())
	{
		Credit = true;
	}

	if (m_Buttons[BUTTON_EXIT]->IsClicked())
	{
		exit(0);
	}
}

void CTitleScene::Render()
{
	IMAGE["TitleBG"]->Render({ 0,0 }, RGB(0, 0, 0));
	for (auto& iter : m_Buttons)
	{
		iter.second->Render(RGB(255, 0, 255));
	}

	if(Credit == true)
	IMAGE["CreditWindow"]->Render({ 50,60 }, RGB(255, 0, 255));
	m_Buttons[BUTTON_START]->Render(RGB(255, 0, 255));
}

void CTitleScene::Release()
{
	for (auto iter : m_Buttons)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	m_Buttons.clear();
	
}
