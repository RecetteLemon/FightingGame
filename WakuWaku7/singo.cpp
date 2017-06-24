#include "stdafx.h"
#include "singo.h"


singo::singo()
{
}


singo::~singo()
{
}


HRESULT singo::init(void)
{

	IMAGEMANAGER->addFrameImage(L"singo_stand", L"Character/singo/Singo_Stand.bmp", 0, 0, 1272, 530, 8, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"singo_stand_hit", L"Character/singo/Singo_StandHit.bmp", 0, 0, 1187, 530, 6, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"singo_stand_Punch1", L"Character/singo/Singo_StandPunch1.bmp", 0, 0, 669, 518, 3, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"singo_stand_Punch2", L"Character/singo/Singo_StandPunch2.bmp", 0, 0, 3014, 594, 11, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"singo_stand_Kick1", L"Character/singo/Singo_StandHit.bmp", 0, 0, 1187, 530, 6, 2, true, true, RGB(255, 0, 255));

	return S_OK;
}
void singo::release(void)
{
}
void singo::update(void)
{
}
void singo::render(void)
{


	draw();
}



void singo::draw(void)
{

}