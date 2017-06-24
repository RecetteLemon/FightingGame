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
	//===========신고 서있을때 이미지=============
	IMAGEMANAGER->addFrameImage(L"Singo_Stand", L"Character/singo/Singo_Stand.bmp", 0, 0, 1272, 530, 8, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Stand_Hit", L"Character/singo/Singo_StandHit.bmp", 0, 0, 1187, 530, 6, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Stand_Guard", L"Character/singo/Singo_StandGuard.bmp", 0, 0, 211, 456, 1, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Stand_Punch1", L"Character/singo/Singo_StandPunch1.bmp", 0, 0, 669, 518, 3, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Stand_Punch2", L"Character/singo/Singo_StandPunch2.bmp", 0, 0, 3014, 594, 11, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Stand_Kick1", L"Character/singo/Singo_StandKick1.bmp", 0, 0, 2415, 554, 7, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Stand_Kick2", L"Character/singo/Singo_StandKick2.bmp", 0, 0, 2960, 576, 10, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"singo_Run", L"Character/singo/Singo_Run.bmp", 0, 0, 1452, 464, 6, 2, true, true, RGB(255, 0, 255));

	//===========신고 앉아있을때 이미지=============
	IMAGEMANAGER->addFrameImage(L"Singo_Sit", L"Character/singo/Singo_Sit.bmp", 0, 0, 150, 344, 1, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Sit_hit", L"Character/singo/Singo_SitHit.bmp", 0, 0, 880, 366, 5, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Sit_Guard", L"Character/singo/Singo_SitGuard.bmp", 0, 0, 138, 358, 1, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Sit_Punch1", L"Character/singo/Singo_SitPunch1.bmp", 0, 0, 660, 344, 3, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Sit_Punch2", L"Character/singo/Singo_SitPunch2.bmp", 0, 0, 1568, 706, 7, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Sit_Kick1", L"Character/singo/Singo_SitKick1.bmp", 0, 0, 738, 344, 3, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Sit_Kick2", L"Character/singo/Singo_SitKick2.bmp", 0, 0, 3740, 426, 11, 2, true, true, RGB(255, 0, 255));

	//===========신고 이동할때 이미지=============
	IMAGEMANAGER->addFrameImage(L"singo_Retreat", L"Character/singo/Singo_Retreat.bmp", 0, 0, 876, 572, 6, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Forward", L"Character/singo/Singo_Forward.bmp", 0, 0, 700, 572, 5, 2, true, true, RGB(255, 0, 255));

	//===========신고 점프할때 이미지=============
	IMAGEMANAGER->addFrameImage(L"Singo_ForwardJump", L"Character/singo/Singo_ForwardJump.bmp", 0, 0, 2000, 708, 10, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_RetreatJump", L"Character/singo/Singo_RetreatJump.bmp", 0, 0, 1800, 708, 10, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Jump_Kick1", L"Character/singo/Singo_JumpKick1.bmp", 0, 0, 2000, 708, 10, 2, true, true, RGB(255, 0, 255));




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