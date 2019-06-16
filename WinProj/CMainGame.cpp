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
	SOUND.Play("BG", true);

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
	IMAGE.AddTexture("WearBG", "./resource/Bg/InGame/WearUI.bmp");
	IMAGE.AddTexture("WearBG2", "./resource/Bg/InGame/WearUI2.bmp");
	IMAGE.AddTexture("WearBG3", "./resource/Bg/InGame/WearUI3.bmp");
	IMAGE.AddTexture("PartBG", "./resource/Bg/InGame/PartUI.bmp");

	IMAGE.AddTexture("HomeButton1", "./resource/Button/InGame/h_1.bmp");
	IMAGE.AddTexture("HomeButton2", "./resource/Button/InGame/h_2.bmp");
	IMAGE.AddTexture("HomeButton3", "./resource/Button/InGame/h_3.bmp");
	IMAGE.AddTexture("PartButton1", "./resource/Button/InGame/Part_1.bmp");
	IMAGE.AddTexture("PartButton2", "./resource/Button/InGame/Part_2.bmp");
	IMAGE.AddTexture("PartButton3", "./resource/Button/InGame/Part_3.bmp");
	IMAGE.AddTexture("LeftButton_Part1", "./resource/Button/InGame/LeftButton_1.bmp");
	IMAGE.AddTexture("LeftButton_Part2", "./resource/Button/InGame/LeftButton_2.bmp");
	IMAGE.AddTexture("LeftButton_Part3", "./resource/Button/InGame/LeftButton_3.bmp");
	IMAGE.AddTexture("RightButton_Part1", "./resource/Button/InGame/RightButton_1.bmp");
	IMAGE.AddTexture("RightButton_Part2", "./resource/Button/InGame/RightButton_2.bmp");
	IMAGE.AddTexture("RightButton_Part3", "./resource/Button/InGame/RightButton_3.bmp");


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