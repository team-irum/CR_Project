#pragma once
class CTitleScene : public CScene
{
private:
	enum SCENE_BUTTON_KIND
	{
		BUTTON_START = 0,
		BUTTON_CREDIT,
		BUTTON_EXIT,
		BUTTON_WINDOWCLOSE,
		BUTTON_SOUND,
		BUTTON_TITLE,
		BUTTON_PART_LEFT,
		BUTTON_PART_RIGHT
	};
	
public:
	CTitleScene();
	~CTitleScene();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	map<SCENE_BUTTON_KIND, CButton *> m_Buttons;
};

