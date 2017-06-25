#pragma once
#include "gameNode.h"
#include "player.h"

class may;
class dummy;

class playerManager : public gameNode
{
private:

	player* _may;
	player* _dummy;

public:

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	playerManager();
	~playerManager();
};

