#pragma once
#include "gameNode.h"

class may;

class playerManager : public gameNode
{
public:

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	playerManager();
	~playerManager();
};

