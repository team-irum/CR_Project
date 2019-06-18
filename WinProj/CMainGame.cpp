#include "stdafx.h"

CMainGame::CMainGame()
{

}


CMainGame::~CMainGame()
{

}

void CMainGame::Init()
{
	SOUND.AddSound("BG", "./Sound/Bg.mp3");
	SOUND.AddSound("INGAME", "./Sound/InGame.mp3");

	//TitleScene
	IMAGE.AddTexture("CreditWindow", "./resource/Credit/CreditWindow.bmp");
	IMAGE.AddTexture("TitleBG", "./resource/Bg/Title/StartBG.bmp");

	IMAGE.AddTexture("StartButton1", "./resource/Button/Title/1.bmp");
	IMAGE.AddTexture("StartButton2", "./resource/Button/Title/2.bmp");
	IMAGE.AddTexture("StartButton3", "./resource/Button/Title/3.bmp");
	IMAGE.AddTexture("CreditButton1", "./resource/Button/Title/c_1.bmp");
	IMAGE.AddTexture("CreditButton2", "./resource/Button/Title/c_2.bmp");
	IMAGE.AddTexture("CreditButton3", "./resource/Button/Title/c_3.bmp");
	IMAGE.AddTexture("ExitButton1", "./resource/Button/Title/e_1.bmp");
	IMAGE.AddTexture("ExitButton2", "./resource/Button/Title/e_2.bmp");
	IMAGE.AddTexture("ExitButton3", "./resource/Button/Title/e_3.bmp");
	IMAGE.AddTexture("SoundButton1", "./resource/Button/Title/s_1.bmp");
	IMAGE.AddTexture("SoundButton2", "./resource/Button/Title/s_2.bmp");
	IMAGE.AddTexture("SoundButton3", "./resource/Button/Title/s_3.bmp");
	IMAGE.AddTexture("CloseButton1", "./resource/Button/Title/Close_1.bmp");
	IMAGE.AddTexture("CloseButton2", "./resource/Button/Title/Close_2.bmp");
	IMAGE.AddTexture("CloseButton3", "./resource/Button/Title/Close_3.bmp");

	//ChangeRoomScene
	IMAGE.AddTexture("CRBG", "./resource/Bg/InGame/Test.bmp");
	IMAGE.AddTexture("UIBG", "./resource/Bg/InGame/InGameUI.bmp");
	IMAGE.AddTexture("WearBG", "./resource/Bg/InGame/WearUI.bmp");
	IMAGE.AddTexture("WearBG2", "./resource/Bg/InGame/WearUI2.bmp");
	IMAGE.AddTexture("WearBG3", "./resource/Bg/InGame/WearUI3.bmp");
	IMAGE.AddTexture("PartBG", "./resource/Bg/InGame/PartUI.bmp");

	IMAGE.AddTexture("HomeButton1", "./resource/Button/InGame/ui_Back.bmp");
	IMAGE.AddTexture("HomeButton2", "./resource/Button/InGame/ui_Back.bmp");
	IMAGE.AddTexture("HomeButton3", "./resource/Button/InGame/ui_Back.bmp");
	IMAGE.AddTexture("LeftButton_Scroll1", "./resource/Button/InGame/ui_Scroll_Left.bmp");
	IMAGE.AddTexture("LeftButton_Scroll2", "./resource/Button/InGame/ui_Scroll_Left.bmp");
	IMAGE.AddTexture("LeftButton_Scroll3", "./resource/Button/InGame/ui_Scroll_Left.bmp");
	IMAGE.AddTexture("RightButton_Scroll1", "./resource/Button/InGame/ui_Scroll_Right.bmp");
	IMAGE.AddTexture("RightButton_Scroll2", "./resource/Button/InGame/ui_Scroll_Right.bmp");
	IMAGE.AddTexture("RightButton_Scroll3", "./resource/Button/InGame/ui_Scroll_Right.bmp");
	IMAGE.AddTexture("LeftButton_Wear1", "./resource/Button/InGame/ui_Wear_Left.bmp");
	IMAGE.AddTexture("LeftButton_Wear2", "./resource/Button/InGame/ui_Wear_Left.bmp");
	IMAGE.AddTexture("LeftButton_Wear3", "./resource/Button/InGame/ui_Wear_Left.bmp");
	IMAGE.AddTexture("RightButton_Wear1", "./resource/Button/InGame/ui_Wear_Right.bmp");
	IMAGE.AddTexture("RightButton_Wear2", "./resource/Button/InGame/ui_Wear_Right.bmp");
	IMAGE.AddTexture("RightButton_Wear3", "./resource/Button/InGame/ui_Wear_Right.bmp");
	IMAGE.AddTexture("AccessoryButton1", "./resource/Button/InGame/ui_Accessory.bmp");
	IMAGE.AddTexture("BGButton1", "./resource/Button/InGame/ui_BG.bmp");
	IMAGE.AddTexture("BodyButton1", "./resource/Button/InGame/ui_Body.bmp");
	IMAGE.AddTexture("EarButton1", "./resource/Button/InGame/ui_Ear.bmp");
	IMAGE.AddTexture("EyeButton1", "./resource/Button/InGame/ui_Eye.bmp");
	IMAGE.AddTexture("EyeBrowButton1", "./resource/Button/InGame/ui_EyeBrow.bmp");
	IMAGE.AddTexture("Hair1Button1", "./resource/Button/InGame/ui_Hair1.bmp");
	IMAGE.AddTexture("Hair2Button1", "./resource/Button/InGame/ui_Hair2.bmp");
	IMAGE.AddTexture("MouthButton1", "./resource/Button/InGame/ui_Mouth.bmp");
	IMAGE.AddTexture("NoseButton1", "./resource/Button/InGame/ui_Nose.bmp");
	IMAGE.AddTexture("ObjectButton1", "./resource/Button/InGame/ui_Object.bmp");
	IMAGE.AddTexture("PantButton1", "./resource/Button/InGame/ui_Pant.bmp");
	IMAGE.AddTexture("ShoesButton1", "./resource/Button/InGame/ui_Shoes.bmp");
	IMAGE.AddTexture("TopButton1", "./resource/Button/InGame/ui_Top.bmp");


	SCENE.AddScene("TitleScene", new CTitleScene()); // ¾À Ãß°¡
	SCENE.AddScene("TestScene", new CTestScene());
	SCENE.AddScene("ChangeRoomScene", new ChangeRoomScene());
	SCENE.ChangeScene("TitleScene"); // ¾À º¯°æ




}

void CMainGame::Update()
{
	TIME.Update();

	INPUT.Update();

	SCENE.Update();

}

void CMainGame::Render()
{
	IMAGE.Begin();

	SCENE.Render();

	IMAGE.End();
}
void CMainGame::Release()
{
	CImageManager::ReleaseInst();
	CSceneManager::ReleaseInst();
	CInputManager::ReleaseInst();
	CSoundManager::ReleaseInst();
	CTimeManager::ReleaseInst();
}