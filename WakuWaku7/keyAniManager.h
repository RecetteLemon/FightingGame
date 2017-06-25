#pragma once
#include "singletonBase.h"
#include <map>

class image;
class animation;


class keyAniManager : public singletonBase<keyAniManager>
{
private:
	typedef map<unsigned int, animation*> arrAnimation;
	typedef map<unsigned int, animation*>::iterator iterAnimations;

private:
	arrAnimation _mTotalAnimation;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	//디폴트 애니메이션
	void addDefaultFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int fps, bool reverse, bool loop);
	void addDefaultFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction);
	void addDefaultFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction, void* obj);

	//배열 애니메이션
	void addArrayFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int* arr, int arrLen, int fps, bool loop);
	void addArrayFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction);
	void addArrayFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction, void* obj);

	//구간 애니메이션
	void addCoordinateFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int start, int end, int fps, bool reverse, bool loop);
	void addCoordinateFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction);
	void addCoordinateFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction, void* obj);

	void start(unsigned int animationKeyName);
	void stop(unsigned int animationKeyName);
	void pause(unsigned int animationKeyName);
	void resume(unsigned int animationKeyName);

	animation* findAnimation(unsigned int animationKeyName);

	void deleteAll();

	keyAniManager();
	~keyAniManager();
};

