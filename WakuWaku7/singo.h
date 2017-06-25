#pragma once
#include "player.h"


class singo : public player
{
public:



	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	virtual void command();
	virtual void control();
	virtual void action();



	singo();
	~singo();
};

