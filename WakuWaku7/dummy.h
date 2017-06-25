#pragma once
#include "player.h"

class dummy : public player
{
public:

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	virtual void control();

	dummy();
	~dummy();
};

