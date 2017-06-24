#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>

class effect;

class effectManager : public singletonBase<effectManager>
{
private:
	typedef vector<effect*> arrEffect;
	typedef vector<effect*>::iterator iterEffect;

	typedef map<wstring, arrEffect> arrEffects;
	typedef map<wstring, arrEffect>::iterator iterEffects;

	typedef vector<arrEffects> arrTotalEffect;
	typedef vector<arrEffects>::iterator iterTotalEffect;

	arrTotalEffect _vTotalEffect;

public:
	HRESULT init();
	void release();
	void update();
	void render(BOOL alpha, BYTE alphaPoint);

	void addEffect(
		wstring effectName, const wchar_t* imageName,
		int imageWidth, int imageHeight, int effectWidth, int effectHeight,
		int fps, float elapsedTime, int buffer, BOOL alpha);

	void play(wstring effectName, int x, int y);

	effectManager();
	~effectManager();
};

