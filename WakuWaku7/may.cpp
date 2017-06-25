#include "stdafx.h"
#include "may.h"


may::may()
{
}


may::~may()
{
}


HRESULT may::init(void)
{
	_img = new image*[POS_END];
	_ani = new animation[POS_END];
	ZeroMemory(_img, sizeof(image*) * (int)POS_END);
	ZeroMemory(_ani, sizeof(animation) * (int)POS_END);

	IMAGEMANAGER->addFrameImage(L"MayStandRight", L"Character/May/MayStandRight.bmp", 3150, 238, 15, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"MayStandLeft", L"Character/May/MayStandLeft.bmp", 3150, 238, 15, 1, true, true, RGB(255, 0, 255));

	
	this->motionInit(STAND_RIGHT, L"MayStandRight", false, true, 15);
	this->motionInit(STAND_LEFT, L"MayStandLeft", false, true, 15);

	
	player::init();
	

	
	return S_OK;
}

void may::release(void)
{
	SAFE_DELETE_ARRAY(_img);
	SAFE_DELETE_ARRAY(_ani);
}

void may::update(void)
{
	player::update();
	
	

}

void may::render(void)
{
	this->draw();
}