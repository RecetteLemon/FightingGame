#pragma once
#include "gameNode.h"
#include "progressBar.h"
#include <vector>


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
		DASH_RIGHT, DASH_LEFT,
		JUMP_RIGHT, JUMP_LEFT,
		DROP_RIGHT, DROP_LEFT
	};
	


	//===========================================================플레이어 정보 변수
	struct tagPLAYER
	{
		float x, y;
		float speed;
		float jumpForce;
		float gravity;

		RECT rc;
		RECT rcDamage;

		tagPLAYER()
		{
			x = y = 0;
			speed = 0;
			jumpForce = 0;
			gravity = 0;
			rc = RectMake(0, 0, 0, 0);
			rcDamage = RectMake(0, 0, 0, 0);
		}
	};
	

	progressBar* _hpBar;
	POSITION _playerPos;



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
	virtual void inputCommand();
	
	//===========================================================
	player();
	~player();
};

