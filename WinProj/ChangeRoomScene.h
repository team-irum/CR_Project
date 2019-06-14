#pragma once

class ChangeRoomScene : public CScene
{
private:
	enum SCENE_BUTTON_KIND
	{
		BUTTON_PART_BODY = 0,
		BUTTON_PART_HAIR,
		BUTTON_PART_CLOTHE,
		BUTTON_TITLE
	};

public:
	ChangeRoomScene();
	~ChangeRoomScene();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	map<SCENE_BUTTON_KIND, CButton *> m_Buttons;
};

