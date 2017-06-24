#pragma once
#include "gameNode.h"

class animation;

class effect : public gameNode
{
protected:
	int			_x, _y;

	image*		_effectImage;
	animation*	_effectAnimation;
	BOOL		_isRunning;
	float		_elapsedTime;

public:

	virtual HRESULT init(image* effectImage, int frameW, int frameH, int fps, float elapsedTime);
	virtual void release();
	virtual void update();
	virtual void render(BOOL alpha, BYTE alphaPoint);

	void startEffect(int x, int y);

	virtual void killEffect();

	BOOL getIsRunning() { return _isRunning; }

	effect();
	~effect();
};

