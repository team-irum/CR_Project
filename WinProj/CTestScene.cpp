#include "stdafx.h"
#include "CTestScene.h"
#include "CFish.h"
#include "CAmp.h"
#include "CAngie.h"
#include "COctopus.h"
#include "CBlip.h"
#include "CItchy.h"
#include "CGash.h"

CTestScene::CTestScene()
{

}


CTestScene::~CTestScene()
{
}

void CTestScene::Init()
{
	IMAGE.AddTexture("BACKGROUND", "./resource/Bg/CutyBG.bmp");
	IMAGE.AddTexture("AMP", "./resource/Fish/amp/amp.bmp");
	IMAGE.AddTexture("AMP_REVERSE", "./resource/Fish/amp/amp_reverse.bmp");
	IMAGE.AddTexture("ANGIE", "./resource/Fish/angie/angie.bmp");
	IMAGE.AddTexture("ANGIE_REVERSE", "./resource/Fish/angie/angie_reverse.bmp");
	IMAGE.AddTexture("OCTOPUS", "./resource/Fish/Octopus/Octopus.bmp");
	IMAGE.AddTexture("OCTOPUS_REVERSE", "./resource/Fish/Octopus/Octopus_reverse.bmp");
	IMAGE.AddTexture("BLIP", "./resource/Fish/Blip/Blip.bmp");
	IMAGE.AddTexture("BLIP_REVERSE", "./resource/Fish/Blip/Blip_reverse.bmp");
	IMAGE.AddTexture("ITCHY", "./resource/Fish/Itchy/Itchy.bmp");
	IMAGE.AddTexture("ITCHY_REVERSE", "./resource/Fish/Itchy/Itchy_reverse.bmp");
	IMAGE.AddTexture("GASH", "./resource/Fish/GASH/GASH.bmp");
	IMAGE.AddTexture("GASH_REVERSE", "./resource/Fish/GASH/GASH_reverse.bmp");
	IMAGE.AddTexture("SANS", "./resource/Fish/SANS/SANS.bmp");
	IMAGE.AddTexture("SANS_REVERSE", "./resource/Fish/SANS/SANS_reverse.bmp");

	m_Fishes.push_back(new CAmp());
	m_Fishes.push_back(new CAngie());
	m_Fishes.push_back(new COctopus());
	m_Fishes.push_back(new CBlip());
	m_Fishes.push_back(new CItchy());
	m_Fishes.push_back(new CGash());

	for (auto& iter : m_Fishes)
	{
		iter->Init();
	}
	TIME.AddTimer("INPUT", new CTimer(0.125f, [&]()->void {
		if (INPUT.KeyPress('2'))
			SYSTEM.SetSpeed(SYSTEM.GetSpeed() - 0.1f);
		if (INPUT.KeyPress('1'))
			SYSTEM.SetSpeed(SYSTEM.GetSpeed() + 0.1f); 
		}));

	TIME.AddTimer("SANS", new CTimer(2.5f, [&]()->void {
		if ((INT)SYSTEM.GetSpeed() == 2)
		{
			auto sans = new CSans();
			sans->Init();
			m_Sanses.push_back(sans);
		}}));
}

void CTestScene::Update()
{
	for (auto& iter : m_Fishes)
	{
		iter->Update();
	}

	for (auto iter = m_Sanses.begin(); iter != m_Sanses.end();)
	{
		LP(iter)->Update();
		if (LP(iter)->Isdead() == true)
		{
			SAFE_DELETE(LP(iter));
			iter = m_Sanses.erase(iter);
		}
		else iter++;
	}


}

void CTestScene::Render()
{
	IMAGE["BACKGROUND"]->Render({ 0,0 }, RGB(255, 0, 255));
	for (auto& iter : m_Fishes)
	{
		iter->Render();
	}
	for (auto& iter : m_Sanses)
	{
		iter->Render();
	}
	wstring outmsg[] =
	{
		L"속도 증가 = 1",
		L"속도 감소 = 2",
		L"현재속도 = " + to_wstring(SYSTEM.GetSpeed())
	};


	SetBkMode(IMAGE.GetMemDc(), TRANSPARENT);
	DrawText(IMAGE.GetMemDc(), outmsg[0].c_str(), outmsg[0].length(), &RECT({ 10,10,100,100 }), DT_CENTER | DT_NOCLIP );
	DrawText(IMAGE.GetMemDc(), outmsg[1].c_str(), outmsg[1].length(), &RECT({ 10,50,100,200 }), DT_CENTER | DT_NOCLIP);
	DrawText(IMAGE.GetMemDc(), outmsg[2].c_str(), outmsg[2].length()-5, &RECT({ 10,90,100,200 }), DT_CENTER | DT_NOCLIP);

}

void CTestScene::Release()
{
	for (auto& iter : m_Fishes)
	{
		iter->Release();
		SAFE_DELETE(iter);
	}
	m_Fishes.clear();

	for (auto& iter : m_Sanses)
	{
		iter->Release();
		SAFE_DELETE(iter);
	}
	m_Sanses.clear();
	TIME.RemoveTimer("INPUT");
	TIME.RemoveTimer("SANS");
}
