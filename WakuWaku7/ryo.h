#pragma once
#include "player.h"

class ryo : public player
{
private:
	image* _ryoImage;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void imageSetting();
	virtual void keyMove();

	ryo();
	~ryo();
};

