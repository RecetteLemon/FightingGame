#pragma once
#include "gameNode.h"

enum KEYINPUT
{
	LEFT,
	LEFT_DOWN,
	DOWN,
	RIGHT_DOWN,
	RIGHT,
	UP,
	A,
	S,
	NOT
};

class Player : public gameNode
{
protected:

	vector<KEYINPUT> _vCommand;
	vector<KEYINPUT>::iterator _viCommand;

	KEYINPUT _currentInput;
	KEYINPUT _prevInput;
	float keyTimer;

protected:
	
	float _x, _y;
	float _jumpForce;
	float _gravity;

	RECT _hitRc;
	RECT _atkRc;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void keyInput();

	Player();
	~Player();
};

