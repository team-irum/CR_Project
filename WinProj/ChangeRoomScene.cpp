#include "stdafx.h"


int PartPage = 1;//카테고리
bool WearPage = false;//의상
extern bool Sound;

ChangeRoomScene::ChangeRoomScene()
{
}


ChangeRoomScene::~ChangeRoomScene()
{
}

void ChangeRoomScene::Init()
{
	SOUND.Stop("BG");
	if(!Sound)
	SOUND.Play("INGAME", true);

	m_Buttons[BUTTON_TITLE] = new CButton();
	m_Buttons[BUTTON_PART_ACCESSORY] = new CButton();
	m_Buttons[BUTTON_PART_BG] = new CButton();
	m_Buttons[BUTTON_PART_BODY] = new CButton();
	m_Buttons[BUTTON_PART_EAR] = new CButton();
	m_Buttons[BUTTON_PART_EYE] = new CButton();
	m_Buttons[BUTTON_PART_EYEBROW] = new CButton();
	m_Buttons[BUTTON_PART_HAIR1] = new CButton();
	m_Buttons[BUTTON_PART_HAIR2] = new CButton();
	m_Buttons[BUTTON_PART_MOUTH] = new CButton();
	m_Buttons[BUTTON_PART_NOSE] = new CButton();
	m_Buttons[BUTTON_PART_OBJECT] = new CButton();
	m_Buttons[BUTTON_PART_PANT] = new CButton();
	m_Buttons[BUTTON_PART_SHOES] = new CButton();
	m_Buttons[BUTTON_PART_TOP] = new CButton();

	m_Buttons[BUTTON_SCROLL_LEFT] = new CButton();
	m_Buttons[BUTTON_SCROLL_RIGHT] = new CButton();
	m_Buttons[BUTTON_WEAR_LEFT] = new CButton();
	m_Buttons[BUTTON_WEAR_RIGHT] = new CButton();


	m_Buttons[BUTTON_TITLE]->Init(IMAGE["HomeButton1"], IMAGE["HomeButton2"], IMAGE["HomeButton3"], { 2, 9 });

	m_Buttons[BUTTON_PART_ACCESSORY]->Init(IMAGE["AccessoryButton1"], IMAGE["AccessoryButton1"], IMAGE["AccessoryButton1"], { 213, 621 });
	m_Buttons[BUTTON_PART_BG]->Init(IMAGE["BGButton1"], IMAGE["BGButton1"], IMAGE["BGButton1"], { 383, 621 });
	m_Buttons[BUTTON_PART_BODY]->Init(IMAGE["BodyButton1"], IMAGE["BodyButton1"], IMAGE["BodyButton1"], { 131,621 });
	m_Buttons[BUTTON_PART_EAR]->Init(IMAGE["EarButton1"], IMAGE["EarButton1"], IMAGE["EarButton1"], { 301,621 });
	m_Buttons[BUTTON_PART_EYE]->Init(IMAGE["EyeButton1"], IMAGE["EyeButton1"], IMAGE["EyeButton1"], { 383,621 });
	m_Buttons[BUTTON_PART_EYEBROW]->Init(IMAGE["EyeBrowButton1"], IMAGE["EyeBrowButton1"], IMAGE["EyeBrowButton1"], { 466,621 });
	m_Buttons[BUTTON_PART_HAIR1]->Init(IMAGE["Hair1Button1"], IMAGE["Hair1Button1"], IMAGE["Hair1Button1"], { 213,621 });
	m_Buttons[BUTTON_PART_HAIR2]->Init(IMAGE["Hair2Button1"], IMAGE["Hair2Button1"], IMAGE["Hair2Button1"], { 301,621 });
	m_Buttons[BUTTON_PART_MOUTH]->Init(IMAGE["MouthButton1"], IMAGE["MouthButton1"], IMAGE["MouthButton1"], { 213,621 });
	m_Buttons[BUTTON_PART_NOSE]->Init(IMAGE["NoseButton1"], IMAGE["NoseButton1"], IMAGE["NoseButton1"], { 131,621 });
	m_Buttons[BUTTON_PART_OBJECT]->Init(IMAGE["ObjectButton1"], IMAGE["ObjectButton1"], IMAGE["ObjectButton1"], { 301,621 });
	m_Buttons[BUTTON_PART_PANT]->Init(IMAGE["PantButton1"], IMAGE["PantButton1"], IMAGE["PantButton1"], { 466,621 });
	m_Buttons[BUTTON_PART_SHOES]->Init(IMAGE["ShoesButton1"], IMAGE["ShoesButton1"], IMAGE["ShoesButton1"], { 131,621 });
	m_Buttons[BUTTON_PART_TOP]->Init(IMAGE["TopButton1"], IMAGE["TopButton1"], IMAGE["TopButton1"], { 383,621 });

	m_Buttons[BUTTON_SCROLL_LEFT]->Init(IMAGE["LeftButton_Scroll1"], IMAGE["LeftButton_Scroll2"], IMAGE["LeftButton_Scroll3"], { 60,621 });
	m_Buttons[BUTTON_SCROLL_RIGHT]->Init(IMAGE["RightButton_Scroll1"], IMAGE["RightButton_Scroll2"], IMAGE["RightButton_Scroll3"], { 531,621 });
	m_Buttons[BUTTON_WEAR_LEFT]->Init(IMAGE["LeftButton_Wear1"], IMAGE["LeftButton_Wear2"], IMAGE["LeftButton_Wear3"], { -40,791 });
	m_Buttons[BUTTON_WEAR_RIGHT]->Init(IMAGE["RightButton_Wear1"], IMAGE["RightButton_Wear2"], IMAGE["RightButton_Wear3"], { 531,791 });

	CurrentUI = UIStatus::Body;
	

	m_UI.insert(make_pair(UIStatus::Body, IMAGE["WearBG"]));
	//m_UI.insert(make_pair(UIStatus::Hair, IMAGE["WearBG2"]));
	//m_UI.insert(make_pair(UIStatus::Clothe, IMAGE["WearBG3"]));
	
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

	if (m_Buttons[BUTTON_PART_ACCESSORY]->IsClicked())
		CurrentUI = (UIStatus)((int)Accessory);
	if (m_Buttons[BUTTON_PART_BG]->IsClicked())
		CurrentUI = (UIStatus)((int)Bg);
	if (m_Buttons[BUTTON_PART_BODY]->IsClicked())
		CurrentUI = (UIStatus)((int)Body);
	if (m_Buttons[BUTTON_PART_EAR]->IsClicked())
		CurrentUI = (UIStatus)((int)Ear);
	if (m_Buttons[BUTTON_PART_EYE]->IsClicked())
		CurrentUI = (UIStatus)((int)Eye);
	if (m_Buttons[BUTTON_PART_EYEBROW]->IsClicked())
		CurrentUI = (UIStatus)((int)EyeBrow);
	if (m_Buttons[BUTTON_PART_HAIR1]->IsClicked())
		CurrentUI = (UIStatus)((int)Hair1);
	if (m_Buttons[BUTTON_PART_HAIR2]->IsClicked())
		CurrentUI = (UIStatus)((int)Hair2);
	if (m_Buttons[BUTTON_PART_MOUTH]->IsClicked())
		CurrentUI = (UIStatus)((int)Mouth);
	if (m_Buttons[BUTTON_PART_NOSE]->IsClicked())
		CurrentUI = (UIStatus)((int)Nose);
	if (m_Buttons[BUTTON_PART_OBJECT]->IsClicked())
		CurrentUI = (UIStatus)((int)Object);
	if (m_Buttons[BUTTON_PART_PANT]->IsClicked())
		CurrentUI = (UIStatus)((int)Pant);
	if (m_Buttons[BUTTON_PART_SHOES]->IsClicked())
		CurrentUI = (UIStatus)((int)Shoes);
	if (m_Buttons[BUTTON_PART_TOP]->IsClicked())
		CurrentUI = (UIStatus)((int)Top);

	if(m_Buttons[BUTTON_SCROLL_LEFT]->IsClicked())
	{
		if (PartPage >= 2)
		{
			if (PartPage == 2)
				PartPage = 1;

			else if (PartPage == 3)
				PartPage = 2;
		}
		
	}
	if (m_Buttons[BUTTON_SCROLL_RIGHT]->IsClicked())
	{
		if (PartPage >= 1)
		{
			if (PartPage == 1)
				PartPage = 2;

			else if (PartPage == 2)
				PartPage = 3;
		}
	}

}

void ChangeRoomScene::Render()
{
	IMAGE["CRBG"]->Render({ 0,0 }, RGB(0, 0, 0));
	IMAGE["UIBG"]->Render({ 0,0 }, RGB(255, 0, 255));
	//IMAGE["PartBG"]->Render({ 0,671 }, RGB(1, 0, 0));

	//m_UI[CurrentUI]->Render({ 0,721 }, RGB(1, 0, 0));

	m_Buttons[BUTTON_TITLE]->Render(RGB(255, 0, 255));
	if (PartPage == 1)
	{
		m_Buttons[BUTTON_PART_BODY]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_PART_HAIR1]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_PART_HAIR2]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_PART_EYE]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_PART_EYEBROW]->Render(RGB(255, 0, 255));
	}
	else if (PartPage == 2)
	{
		m_Buttons[BUTTON_PART_NOSE]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_PART_MOUTH]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_PART_EAR]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_PART_TOP]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_PART_PANT]->Render(RGB(255, 0, 255));
	}
	else if (PartPage == 3)
	{
		m_Buttons[BUTTON_PART_SHOES]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_PART_ACCESSORY]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_PART_OBJECT]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_PART_BG]->Render(RGB(255, 0, 255));
	}
		m_Buttons[BUTTON_SCROLL_LEFT]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_SCROLL_RIGHT]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_WEAR_LEFT]->Render(RGB(255, 0, 255));
		m_Buttons[BUTTON_WEAR_RIGHT]->Render(RGB(255, 0, 255));
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
