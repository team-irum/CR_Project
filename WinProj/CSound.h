#pragma once

class CSound
{
public:
	CSound(DWORD _DeviceID);
	~CSound();
private:
	DWORD m_DeviceID;

public:
	MCI_STATUS_PARMS     mciStatus; //������ ����
	DWORD GetDeviceID() { return m_DeviceID; }
};
