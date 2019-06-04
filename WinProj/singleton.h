#pragma once

template <typename T>
class singleton
{
public:
	singleton() {}
	virtual ~singleton() {}
private:
	static T* Inst;
public:
	static T * GetInst()
	{
		if (!Inst) Inst = new T();
		return Inst;
	}
	static void ReleaseInst()
	{
		delete Inst;
		Inst = nullptr;
	}
};

template <class T>
T * singleton<T>::Inst = nullptr;