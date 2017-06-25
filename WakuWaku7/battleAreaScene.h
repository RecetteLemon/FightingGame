#pragma once
#include "gameNode.h"
#include "playerManager.h"

class battleAreaScene : public gameNode
{
private:

	playerManager* _pM;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);


	battleAreaScene();
	~battleAreaScene();
};

