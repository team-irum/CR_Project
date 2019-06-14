#include "stdafx.h"


bool PartPage = false;//카테고리
bool WearPage = false;//의상


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

	m_Buttons[BUTTON_PART_LEFT] = new CButton();
	m_Buttons[BUTTON_PART_RIGHT] = new CButton();


	m_Buttons[BUTTON_TITLE]->Init(IMAGE["HomeButton1"], IMAGE["HomeButton2"], IMAGE["HomeButton3"], { 10, 10 });
	m_Buttons[BUTTON_PART_BODY]->Init(IMAGE["PartButton1"], IMAGE["PartButton2"], IMAGE["PartButton3"], { 170,681 });
	m_Buttons[BUTTON_PART_HAIR]->Init(IMAGE["PartButton1"], IMAGE["PartButton2"], IMAGE["PartButton3"], { 240,681 });
	m_Buttons[BUTTON_PART_CLOTHE]->Init(IMAGE["PartButton1"], IMAGE["PartButton2"], IMAGE["PartButton3"], { 310,681 });
	m_Buttons[BUTTON_PART_LEFT]->Init(IMAGE["LeftButton_Part1"], IMAGE["LeftButton_Part2"], IMAGE["LeftButton_Part3"], { 0,681 });
	m_Buttons[BUTTON_PART_RIGHT]->Init(IMAGE["RightButton_Part1"], IMAGE["RightButton_Part2"], IMAGE["RightButton_Part3"], { 540,681 });

	CurrentUI = UIStatus::Body;
	

	m_UI.insert(make_pair(UIStatus::Body, IMAGE["WearBG"]));
	m_UI.insert(make_pair(UIStatus::Hair, IMAGE["WearBG2"]));
	m_UI.insert(make_pair(UIStatus::Clothe, IMAGE["WearBG3"]));
	
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
		CurrentUI = (UIStatus)((int)BUTTON_PART_BODY);

	}
	if (m_Buttons[BUTTON_PART_HAIR]->IsClicked())
	{
		CurrentUI = (UIStatus)((int)BUTTON_PART_HAIR);

	}
	if (m_Buttons[BUTTON_PART_CLOTHE]->IsClicked())
	{
		CurrentUI = (UIStatus)((int)BUTTON_PART_CLOTHE);

	}
	if(m_Buttons[BUTTON_PART_LEFT]->IsClicked())
	{
		PartPage = false;
		
	}
	if (m_Buttons[BUTTON_PART_RIGHT]->IsClicked())
	{
		PartPage = true;
	}

}

void ChangeRoomScene::Render()
{
	IMAGE["CRBG"]->Render({ 0,0 }, RGB(0, 0, 0));
	IMAGE["PartBG"]->Render({ 0,671 }, RGB(1, 0, 0));

	m_UI[CurrentUI]->Render({ 0,721 }, RGB(1, 0, 0));

	m_Buttons[BUTTON_TITLE]->Render(RGB(255, 0, 255));
	if (!PartPage)
	{
		m_Buttons[BUTTON_PART_BODY]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_PART_HAIR]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_PART_CLOTHE]->Render(RGB(255, 0, 255));
	}
		m_Buttons[BUTTON_PART_LEFT]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_PART_RIGHT]->Render(RGB(255, 0, 255));
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
