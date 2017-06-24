#pragma once
#include "gameNode.h"
#include "animation.h"

class introScene : public gameNode
{

private:

	image*	_introBackground;
	image*	_introMain;

	animation* _aniMain;

	float	_elapsedTime;
	int		_loopTime;

public:

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	introScene();
	~introScene();
};

