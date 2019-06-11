#include "stdafx.h"



ChangeRoomScene::ChangeRoomScene()
{
}


ChangeRoomScene::~ChangeRoomScene()
{
}

void ChangeRoomScene::Init()
{

}

void ChangeRoomScene::Update()
{

}

void ChangeRoomScene::Render()
{
	IMAGE["CRBG"]->Render({ 0,0 }, RGB(0, 0, 0));
	IMAGE["PartBG"]->Render({ 0,671 }, RGB(1, 0, 0));
	IMAGE["WearBG"]->Render({ 0,721 }, RGB(1, 0, 0));
}

void ChangeRoomScene::Release()
{

}
