#pragma once
#include "player.h"


class singo : public player
{
public:
	COMMAND _command;
	POSITION _position;


	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	void draw(void);

	void command();
	void inputCommand();


	singo();
	~singo();
};

