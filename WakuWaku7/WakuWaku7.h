#pragma once
#include "gameNode.h"
#include "introScene.h"
#include "selectScene.h"
#include "battleAreaScene.h"

class WakuWaku7 : public gameNode
{
private:

	
	
public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	WakuWaku7();
	~WakuWaku7();
};
