#include "stdafx.h"


bool Body = false;
bool Hair = false;
bool Clothe = false;
bool WearPage = false;
bool PartBG = false;

ChangeRoomScene::ChangeRoomScene()
{
}


ChangeRoomScene::~ChangeRoomScene()
{
}

void ChangeRoomScene::Init()
{
	m_Buttons[BUTTON_TITLE] = new CButton();
	m_Buttons[BUTTON_PART_BODY] = new CButton();
	m_Buttons[BUTTON_PART_HAIR] = new CButton();
	m_Buttons[BUTTON_PART_CLOTHE] = new CButton();

	m_Buttons[BUTTON_TITLE]->Init(IMAGE["HomeButton1"], IMAGE["HomeButton2"], IMAGE["HomeButton3"], { 10, 10 });
	m_Buttons[BUTTON_PART_BODY]->Init(IMAGE["PartButton1"], IMAGE["PartButton2"], IMAGE["PartButton3"], { 170,681 });
	m_Buttons[BUTTON_PART_HAIR]->Init(IMAGE["PartButton1"], IMAGE["PartButton2"], IMAGE["PartButton3"], { 240,681 });
	m_Buttons[BUTTON_PART_CLOTHE]->Init(IMAGE["PartButton1"], IMAGE["PartButton2"], IMAGE["PartButton3"], { 310,681 });
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

	if (m_Buttons[BUTTON_PART_BODY]->IsClicked())
	{
		Clothe = false;
		Hair = false;

		Body = true;
	}
	if (m_Buttons[BUTTON_PART_HAIR]->IsClicked())
	{
		Body = false;
		Clothe = false;

		Hair = true;
	}
	if (m_Buttons[BUTTON_PART_CLOTHE]->IsClicked())
	{
		Body = false;
		Hair = false;

		Clothe = true;
	}
}

void ChangeRoomScene::Render()
{
	IMAGE["CRBG"]->Render({ 0,0 }, RGB(0, 0, 0));
	IMAGE["CRBG"]->Render({ 0,0 }, RGB(0, 0, 0));
	IMAGE["PartBG"]->Render({ 0,671 }, RGB(1, 0, 0));
	if (Body)
		IMAGE["WearBG"]->Render({ 0,721 }, RGB(1, 0, 0));
	if (Hair)
		IMAGE["WearBG2"]->Render({ 0,721 }, RGB(1, 0, 0));
	if(Clothe)
		IMAGE["WearBG3"]->Render({ 0,721 }, RGB(1, 0, 0));

	m_Buttons[BUTTON_TITLE]->Render(RGB(255, 0, 255));
	m_Buttons[BUTTON_PART_BODY]->Render(RGB(255, 0, 255));
	m_Buttons[BUTTON_PART_HAIR]->Render(RGB(255, 0, 255));
	m_Buttons[BUTTON_PART_CLOTHE]->Render(RGB(255, 0, 255));
	
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
