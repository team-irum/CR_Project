#pragma once

enum UIStatus
{
	Accessory =5,
	Bg,
	Body,
	Ear,
	Eye,
	EyeBrow,
	Hair1,
	Hair2,
	Mouth,
	Nose,
	Object,
	Pant,
	Shoes,
	Top,
};

class ChangeRoomScene : public CScene
{
private:
	enum SCENE_BUTTON_KIND
	{
		BUTTON_PART_ACCESSORY = 5,
		BUTTON_PART_BG,
		BUTTON_PART_BODY,
		BUTTON_PART_EAR,
		BUTTON_PART_EYE,
		BUTTON_PART_EYEBROW,
		BUTTON_PART_HAIR1,
		BUTTON_PART_HAIR2,
		BUTTON_PART_MOUTH,
		BUTTON_PART_NOSE,
		BUTTON_PART_OBJECT,
		BUTTON_PART_PANT,
		BUTTON_PART_SHOES,
		BUTTON_PART_TOP,
		BUTTON_TITLE = 20,
		BUTTON_SCROLL_LEFT,
		BUTTON_SCROLL_RIGHT,
		BUTTON_WEAR_LEFT,
		BUTTON_WEAR_RIGHT,
	};

public:
	ChangeRoomScene();
	~ChangeRoomScene();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	UIStatus CurrentUI;
	map<UIStatus, CTexture *> m_UI;	//----------------------------------------------Ãâ·Â
	map<SCENE_BUTTON_KIND, CButton *> m_Buttons;
};

