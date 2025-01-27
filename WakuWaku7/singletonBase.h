#pragma once

template <typename T>
class singletonBase
{
protected:
	static T* singleton;						//�̱��� �ν��Ͻ� ����

	singletonBase() {};
	~singletonBase() {};

public:
	static T* getSingleton();
	void releaseSingleton();
};

template <typename T>
T* singletonBase<T>::singleton = 0;				//�̱��� �ʱ�ȭ

template <typename T>
T* singletonBase<T>::getSingleton()
{
	if (!singleton) singleton = new T;
	return singleton;
}

template <typename T>
void singletonBase<T>::releaseSingleton()
{
	if (singleton)
	{
		delete singleton;
		singleton = 0;
	}
}