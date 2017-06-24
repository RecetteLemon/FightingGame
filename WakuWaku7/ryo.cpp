#include "stdafx.h"
#include "ryo.h"


ryo::ryo()
{
}


ryo::~ryo()
{
}

HRESULT ryo::init()
{
	imageSetting();

	return S_OK;
}

void ryo::release()
{
}

void ryo::update()
{

}

void ryo::render()
{

}

void ryo::imageSetting()
{
	IMAGEMANAGER->addFrameImage(L"ryo_stay", L"Character/ryo/Ryo_stay.bmp",
		1218, 496, 11, 2, true, true, RGB(0xff, 0, 0xff));
	IMAGEMANAGER->addFrameImage(L"ryo_move", L"Character/ryo/Ryo_move.bmp",
		828, 496, 6, 2, true, true, RGB(0xff, 0, 0xff));
	IMAGEMANAGER->addFrameImage(L"ryo_backMove", L"Character/ryo/Ryo_backMove.bmp",
		810, 496, 6, 2, true, true, RGB(0xff, 0, 0xff));
	IMAGEMANAGER->addFrameImage(L"ryo_punch", L"Character/ryo/Ryo_punch.bmp",
		1368, 496, 6, 2, true, true, RGB(0xff, 0, 0xff));
	IMAGEMANAGER->addFrameImage(L"ryo_kick", L"Character/ryo/Ryo_kick.bmp",
		1704, 496, 6, 2, true, true, RGB(0xff, 0, 0xff));
	IMAGEMANAGER->addFrameImage(L"ryo_jump", L"Character/ryo/Ryo_jump.bmp",
		96, 496, 1, 2, true, true, RGB(0xff, 0, 0xff));
	IMAGEMANAGER->addFrameImage(L"ryo_drop", L"Character/ryo/Ryo_drop.bmp",
		96, 496, 1, 2, true, true, RGB(0xff, 0, 0xff));
	IMAGEMANAGER->addFrameImage(L"ryo_jumpPunch", L"Character/ryo/Ryo_jump_punch",
		1302, 496, 6, 2, true, true, RGB(0xff, 0, 0xff));
	IMAGEMANAGER->addFrameImage(L"ryo_jumpKick", L"Character/ryo/Ryo_jump_kick",
		1925, 496, 7, 2, true, true, RGB(0xff, 0, 0xff));
	IMAGEMANAGER->addFrameImage(L"ryo_hitPunch", L"Character/ryo/Ryo_hit_punch",
		1602, 496, 6, 2, true, true, RGB(0xff, 0, 0xff));
	IMAGEMANAGER->addFrameImage(L"ryo_hitKick", L"Character/ryo/Ryo_hit_kick",
		1680, 496, 7, 2, true, true, RGB(0xff, 0, 0xff));
	IMAGEMANAGER->addFrameImage(L"Ryo_specialSkill", L"Character/ryo/Ryo_specialSkill.bmp",
		44100, 976, 90, 2, true, true, RGB(0xff, 0, 0xff));
}

void ryo::keyMove()
{

}
