#pragma once
#include "gameNode.h"
#include "playerManager.h"


class battleAreaScene : public gameNode
{
private:

	image* _background1;
	playerManager* _pM;


	float _elapsedTime;
public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);


	battleAreaScene();
	~battleAreaScene();
};
