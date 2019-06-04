#pragma once
// abstract 키워드는 해당 클래스가 추상 클래스임을 명시한다.
class CScene abstract
{
public:
	CScene();
	virtual ~CScene(); // 상속해줄 클래스는 가상소멸자를 해주지 않으면 8바이트의 메모리가 누수나게된다.

public:
	virtual void Init() PURE; // 가상 순수함수의 형태이며 해당 클래스의 자식클래스에서 정의할 수있다.
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
};

