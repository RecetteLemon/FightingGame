#include "stdafx.h"
#include "dummy.h"


dummy::dummy()
{
}


dummy::~dummy()
{
}


HRESULT dummy::init(void)
{
	_img = new image*[POS_END];
	_ani = new animation[POS_END];
	ZeroMemory(_img, sizeof(image*) * (int)POS_END);
	ZeroMemory(_ani, sizeof(animation) * (int)POS_END);

	_img[STAND_RIGHT] = IMAGEMANAGER->addFrameImage(L"ErzaStandRight", L"Character/Erza/ErzaStandRight.bmp", 400, 180, 5, 1, true, true, RGB(255, 0, 255));
	_img[STAND_LEFT] = IMAGEMANAGER->addFrameImage(L"ErzaStandLeft", L"Character/Erza/ErzaStandLeft.bmp", 400, 180, 5, 1, true, true, RGB(255, 0, 255));


	this->motionInit(STAND_RIGHT, L"ErzaStandRight", false, true, 15);
	this->motionInit(STAND_LEFT, L"ErzaStandLeft", false, true, 15);


	player::init();


	_x = 400;
	return S_OK;
}

void dummy::release(void)
{
	SAFE_DELETE_ARRAY(_img);
}

void dummy::update(void)
{
	player::update();

	control();

}

void dummy::render(void)
{
	this->draw();
}

void dummy::control()
{

}