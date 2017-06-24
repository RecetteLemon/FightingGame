#pragma once
#include "singletonBase.h"
#include <map>

class image;
class animation;


class keyAniManager : public singletonBase<keyAniManager>
{
private:
	typedef map<wstring, animation*> arrAnimation;
	typedef map<wstring, animation*>::iterator iterAnimations;

private:
	arrAnimation _mTotalAnimation;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	//디폴트 애니메이션
	void addDefaultFrameAnimation(wstring animationKeyName, wchar_t* imageKeyName, int fps, bool reverse, bool loop);
	void addDefaultFrameAnimation(wstring animationKeyName, wchar_t* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction);
	void addDefaultFrameAnimation(wstring animationKeyName, wchar_t* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction, void* obj);

	//배열 애니메이션
	void addArrayFrameAnimation(wstring animationKeyName, wchar_t* imageKeyName, int* arr, int arrLen, int fps, bool loop);
	void addArrayFrameAnimation(wstring animationKeyName, wchar_t* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction);
	void addArrayFrameAnimation(wstring animationKeyName, wchar_t* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction, void* obj);

	//구간 애니메이션
	void addCoordinateFrameAnimation(wstring animationKeyName, wchar_t* imageKeyName, int start, int end, int fps, bool reverse, bool loop);
	void addCoordinateFrameAnimation(wstring animationKeyName, wchar_t* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction);
	void addCoordinateFrameAnimation(wstring animationKeyName, wchar_t* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction, void* obj);

	void start(wstring animationKeyName);
	void stop(wstring animationKeyName);
	void pause(wstring animationKeyName);
	void resume(wstring animationKeyName);

	animation* findAnimation(wstring animationKeyName);

	void deleteAll();

	keyAniManager();
	~keyAniManager();
};

