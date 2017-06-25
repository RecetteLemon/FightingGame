#pragma once
#include "gameNode.h"
#include "progressBar.h"
#include <vector>

#define PLAYER_SPEED 5.0f
#define PLAYER_JUMPFORCE 15.0f
#define GRAVITY 0.5f;

class player : public gameNode
{
protected:

	//===========================================================커맨드 입력
	enum COMMAND
	{
		LEFT = 0b00000001,			  // 1
		RIGHT = 0b00000010,			  // 2
		UP = 0b00000100,			  // 4
		DOWN = 0b00001000,			  // 8
		PUNCH = 0b00010000,			  // 16
		KICK = 0b00100000			  // 32
	};
	


	//===========================================================플레이어 포지션
	enum POSITION
	{
		STAND_RIGHT, STAND_LEFT,
		WALK_RIGHT, WALK_LEFT,
		BACKWALK_RIGHT, BACKWALK_LEFT,
		DASH_RIGHT, DASH_LEFT,
		JUMP_RIGHT, JUMP_LEFT,
		DROP_RIGHT, DROP_LEFT,
		POS_END
	};
	


	//===========================================================플레이어 정보 변수
	
	POSITION _pos;

	bool			_onRight;

	float			_x, _y;
	float			_speed;
	float			_jumpForce;
	float			_gravity;

	RECT			_rc;
	RECT			_rcDamage;

	progressBar*	_hpBar;
	animation*		_ani;
	image**			_img;


	//===========================================================커맨드 변수들
	float _commandDelay;
	float _commandInputTime;

	vector<COMMAND>				_vCommand;
	vector<COMMAND>::iterator	_viCommand;


public:

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	//===========================================================커맨드 관리 함수
	virtual void command();
	virtual void control();
	virtual void action();
	virtual void inputCommand();
	
	//===========================================================

	virtual void draw();
	virtual void motionInit(POSITION pos, wchar_t* keyName, bool reverse, bool loop, int fps);

	player();
	~player();
};

