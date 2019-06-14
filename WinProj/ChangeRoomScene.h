#pragma once

enum UIStatus
{
	 Body = 5,
	 Hair ,
	 Clothe ,
};

class ChangeRoomScene : public CScene
{
private:
	enum SCENE_BUTTON_KIND
	{
		BUTTON_PART_BODY = 5,
		BUTTON_PART_HAIR,
		BUTTON_PART_CLOTHE,
		BUTTON_TITLE = 9
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
	map<UIStatus, CTexture *> m_UI;
	map<SCENE_BUTTON_KIND, CButton *> m_Buttons;
};

