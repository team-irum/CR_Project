#include "stdafx.h"



ChangeRoomScene::ChangeRoomScene()
{
	m_Buttons[BUTTON_PART_BODY] = new CButton();
	m_Buttons[BUTTON_PART_HAIR] = new CButton();
	m_Buttons[BUTTON_PART_CLOTHE] = new CButton();
	m_Buttons[BUTTON_PART_BODY]->Init(IMAGE["PartButton1"], IMAGE["PartButton2"], IMAGE["PartButton3"], {30,681});
	m_Buttons[BUTTON_PART_HAIR]->Init(IMAGE["PartButton1"], IMAGE["PartButton2"], IMAGE["PartButton3"], {90,681});
	m_Buttons[BUTTON_PART_CLOTHE]->Init(IMAGE["PartButton1"], IMAGE["PartButton2"], IMAGE["PartButton3"], {150,681});
}


ChangeRoomScene::~ChangeRoomScene()
{
}

void ChangeRoomScene::Init()
{
	
}

void ChangeRoomScene::Update()
{
	for (auto& iter : m_Buttons)
	{
		iter.second->Update();
	}

	if (m_Buttons[BUTTON_PART_BODY]->IsClicked())
	{

	}
	if (m_Buttons[BUTTON_PART_HAIR]->IsClicked())
	{

	}
	if (m_Buttons[BUTTON_PART_CLOTHE]->IsClicked())
	{

	}
}

void ChangeRoomScene::Render()
{
	IMAGE["CRBG"]->Render({ 0,0 }, RGB(0, 0, 0));
	IMAGE["PartBG"]->Render({ 0,671 }, RGB(1, 0, 0));
	IMAGE["WearBG"]->Render({ 0,721 }, RGB(1, 0, 0));

	m_Buttons[BUTTON_PART_BODY]->Render(RGB(255, 0, 255));
	m_Buttons[BUTTON_PART_HAIR]->Render(RGB(255, 0, 255));
	m_Buttons[BUTTON_PART_CLOTHE]->Render(RGB(255, 0, 255));
	
}

void ChangeRoomScene::Release()
{

}
