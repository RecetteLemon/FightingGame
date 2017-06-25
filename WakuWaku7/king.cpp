#include "stdafx.h"
#include "king.h"


king::king()
{
}


king::~king()
{
}

HRESULT king::init(void)
{
	_img = new image*[POS_END];
	_ani = new animation[POS_END];
	ZeroMemory(_img, sizeof(image*) * (int)POS_END);
	ZeroMemory(_ani, sizeof(animation) * (int)POS_END);

	IMAGEMANAGER->addFrameImage(L"king_idle_L", L"Character/King/KOF03_King_idle_L.bmp", 840, 260, 6, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"king_idle_R", L"Character/King/KOF03_King_idle_R.bmp", 840, 260, 6, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"king_moveForward_L", L"Character/King/KOF03_King_moveForward_L.bmp", 660, 252, 5, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"king_moveForward_R", L"Character/King/KOF03_King_moveForward_R.bmp", 660, 252, 5, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"king_sit_L", L"Character/King/KOF03_King_sit_L.bmp", 260, 225, 2, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"king_sit_R", L"Character/King/KOF03_King_sit_R.bmp", 260, 225, 2, 1, true, true, RGB(255, 0, 255));


	this->motionInit(STAND_LEFT, L"king_idle_L", false, true, 6);
	this->motionInit(STAND_RIGHT, L"king_idle_R", false, true, 6);
	this->motionInit(WALK_LEFT, L"king_moveForward_L", false, true, 6);
	this->motionInit(WALK_RIGHT, L"king_moveForward_R", false, true, 6);
	this->motionInit(SIT_LEFT, L"king_sit_L", false, false, 10);
	this->motionInit(SIT_RIGHT, L"king_sit_R", false, false, 10);

	_pos = STAND_RIGHT;
	_ani[_pos].start();

	player::init();



	return S_OK;
}

void king::release(void)
{
	SAFE_DELETE_ARRAY(_img);
	SAFE_DELETE_ARRAY(_ani);
}

void king::update(void)
{
	player::update();

	control();

}

void king::render(void)
{
	this->draw();
}

void king::control()
{
//	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
//	{
//		_pos = WALK_RIGHT;
//		_ani[_pos].start();
//	}
//
//	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
//	{
//		_pos = WALK_LEFT;
//		_ani[_pos].start();
//	}


	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 2.0f;
		_pos = WALK_RIGHT;
		if (!_ani[_pos].isPlay()) _ani[_pos].start();
	}
	else if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 2.0f;
		_pos = WALK_LEFT;
		if (!_ani[_pos].isPlay()) _ani[_pos].start();
	}
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (_pos == WALK_LEFT || _pos == STAND_LEFT)
		{
			_pos = SIT_LEFT;
			_ani[_pos].start();
		}
		if (_pos == WALK_RIGHT || _pos == STAND_RIGHT)
		{
			_pos = SIT_RIGHT;
			_ani[_pos].start();
		}
	}
	else
	{
		if (_pos == WALK_LEFT || _pos == SIT_LEFT) _pos = STAND_LEFT;
		if (_pos == WALK_RIGHT || _pos == SIT_RIGHT) _pos = STAND_RIGHT;

		if (!_ani[_pos].isPlay()) _ani[_pos].start();
	}


}