#include "stdafx.h"

bool Credit = false;//크레딧화면
bool Sound = false;//사운드

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
	m_Buttons[BUTTON_WINDOWCLOSE] = new CButton();
	m_Buttons[BUTTON_SOUND] = new CButton();
	
	m_Buttons[BUTTON_START]->Init(IMAGE["StartButton1"], IMAGE["StartButton2"], IMAGE["StartButton3"], {240, 700});
	m_Buttons[BUTTON_CREDIT]->Init(IMAGE["CreditButton1"], IMAGE["CreditButton2"], IMAGE["CreditButton3"], { 450, 150 });
	m_Buttons[BUTTON_EXIT]->Init(IMAGE["ExitButton1"], IMAGE["ExitButton2"], IMAGE["ExitButton3"], { 440, 700 });
	m_Buttons[BUTTON_WINDOWCLOSE]->Init(IMAGE["CloseButton1"], IMAGE["CloseButton2"], IMAGE["CloseButton3"], { 300, 60 });
	m_Buttons[BUTTON_SOUND]->Init(IMAGE["SoundButton1"], IMAGE["SoundButton2"], IMAGE["SoundButton3"], { 450, 50 });

}

void CTitleScene::Update()
{
	for (auto& iter : m_Buttons)
	{
		iter.second->Update();
	}

	if (m_Buttons[BUTTON_START]->IsClicked())
	{
		SCENE.ChangeScene("ChangeRoomScene");
	}

	if (m_Buttons[BUTTON_CREDIT]->IsClicked())
	{
		Credit = true;
	}

	if (m_Buttons[BUTTON_WINDOWCLOSE]->IsClicked())
	{
		Credit = false;
	}
	
	if (m_Buttons[BUTTON_SOUND]->IsClicked())
	{
		if (Sound == true)
		{
			SOUND.Play("BG", true);
			Sound = false;
		}
		else if (Sound == false)
		{
			SOUND.Stop("BG");
			Sound = true;
		}
	}

	if (m_Buttons[BUTTON_EXIT]->IsClicked())
	{
		exit(0);
	}
}

void CTitleScene::Render()
{
	IMAGE["TitleBG"]->Render({ 0,0 }, RGB(0, 0, 0));
	m_Buttons[BUTTON_START]->Render(RGB(255, 0, 255));
	m_Buttons[BUTTON_CREDIT]->Render(RGB(255, 0, 255));
	m_Buttons[BUTTON_EXIT]->Render(RGB(255, 0, 255));
	m_Buttons[BUTTON_SOUND]->Render(RGB(255, 0, 255));

	if (Credit == true)
	{
		IMAGE["CreditWindow"]->Render({ 50,60 }, RGB(255, 0, 255));
		m_Buttons[BUTTON_WINDOWCLOSE]->Render(RGB(255, 0, 255));
	}
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
