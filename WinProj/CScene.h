#pragma once
// abstract Ű����� �ش� Ŭ������ �߻� Ŭ�������� ����Ѵ�.
class CScene abstract
{
public:
	CScene();
	virtual ~CScene(); // ������� Ŭ������ ����Ҹ��ڸ� ������ ������ 8����Ʈ�� �޸𸮰� �������Եȴ�.

public:
	virtual void Init() PURE; // ���� �����Լ��� �����̸� �ش� Ŭ������ �ڽ�Ŭ�������� ������ ���ִ�.
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
};

