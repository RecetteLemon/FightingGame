#pragma once
#include "player.h"

class Heidern : public player
{
private:

public:

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void control(void);




	Heidern();
	~Heidern();
};

