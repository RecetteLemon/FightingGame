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
		LEFT = 0b00000001,			  // 1		// 왼쪽
		RIGHT = 0b00000010,			  // 2		// 오른쪽
		UP = 0b00000100,			  // 4		// 위
		DOWN = 0b00001000,			  // 8		// 앉기
		PUNCH = 0b00010000,			  // 16		// 주먹
		KICK = 0b00100000			  // 32		// 발차기
	};
	


	//===========================================================플레이어 포지션
	enum POSITION
	{
		STAND_RIGHT, STAND_LEFT,	// 서있는 상태 왼, 오른
		WALK_RIGHT, WALK_LEFT,		// 걷는거 왼, 오른
		DASH_RIGHT, DASH_LEFT,		// 달리기 왼, 오른
		JUMP_RIGHT, JUMP_LEFT,		// 점프 왼, 오른
		DROP_RIGHT, DROP_LEFT		// 떨어지는거 왼 오른
	};
	


	//===========================================================플레이어 정보 변수
	struct tagPLAYER
	{
		float x, y;		// 플레이어 위치	
		float speed;	// 플레이어 스피드
		float jumpForce;// 점프 파워
		float gravity;	// 중력

		RECT rc;		// 플레이어 피격 렉트
		RECT rcDamage;	// 플레이어 공격 렉트

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
	

	progressBar* _hpBar; // 체력바
	POSITION _playerPos; // 플레이어 힘



	//===========================================================커맨드 변수들
	float _commandDelay;	 // 재입력 시간
	float _commandInputTime; // 입력 최대 시간

	vector<COMMAND>				_vCommand;	
	vector<COMMAND>::iterator	_viCommand;


public:

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	//===========================================================커맨드 관리 함수
	virtual void command();
	virtual void inputCommand();
	//===========================================================
	player();
	~player();
};

