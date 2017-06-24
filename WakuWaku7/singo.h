#pragma once
#include "player.h"



class singo
{
public:

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	void draw(void);




	singo();
	~singo();
};

