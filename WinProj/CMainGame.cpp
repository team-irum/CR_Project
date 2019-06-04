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

	IMAGE.AddTexture("TitleBG", "./resource/Bg/StartBG.bmp");
	IMAGE.AddTexture("StartButton1", "./resource/Button/1.bmp");
	IMAGE.AddTexture("StartButton2", "./resource/Button/2.bmp");
	IMAGE.AddTexture("StartButton3", "./resource/Button/3.bmp");
	IMAGE.AddTexture("CreditButton1", "./resource/Button/c_1.bmp");
	IMAGE.AddTexture("CreditButton2", "./resource/Button/c_2.bmp");
	IMAGE.AddTexture("CreditButton3", "./resource/Button/c_3.bmp");
	IMAGE.AddTexture("ExitButton1", "./resource/Button/e_1.bmp");
	IMAGE.AddTexture("ExitButton2", "./resource/Button/e_2.bmp");
	IMAGE.AddTexture("ExitButton3", "./resource/Button/e_3.bmp");
	IMAGE.AddTexture("CloseButton1", "./resource/Button/Close_1.bmp");
	IMAGE.AddTexture("CloseButton2", "./resource/Button/Close_2.bmp");
	IMAGE.AddTexture("CloseButton3", "./resource/Button/Close_3.bmp");
	IMAGE.AddTexture("CreditWindow", "./resource/Credit/CreditWindow.bmp");

	SCENE.AddScene("TitleScene", new CTitleScene()); // ¾À Ãß°¡
	SCENE.AddScene("TestScene", new CTestScene()); // ¾À Ãß°¡
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
