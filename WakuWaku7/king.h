#pragma once
#include "player.h"

class king : public player
{
public:

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
	void control();

	king();
	~king();
};

