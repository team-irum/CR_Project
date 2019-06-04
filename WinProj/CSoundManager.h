#pragma once
#include "singleton.h"
#include "CSound.h"
class CSoundManager :
	public singleton< CSoundManager>
{
public:
	CSoundManager();
	~CSoundManager();
private:
	MCI_OPEN_PARMSA      mciOpen;
	MCI_PLAY_PARMS       mciPlay; //파일을 재생


	map <string, CSound*> m_Sounds;
public:
	CSound * AddSound(const string& _Key, const string& _Path);
	CSound * FindSound(const string& _Key);

	void Play(const string& _Key, bool _bLoop);
	void Stop(const string& _Key);

};

#define SOUND (*CSoundManager::GetInst())

