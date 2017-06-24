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
	IMAGEMANAGER->addFrameImage(L"Singo_MidJump", L"Character/singo/Singo_MidJump.bmp", 0, 0, 2106, 708, 9, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_ForwardJump", L"Character/singo/Singo_ForwardJump.bmp", 0, 0, 2000, 708, 10, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_RetreatJump", L"Character/singo/Singo_RetreatJump.bmp", 0, 0, 1800, 708, 10, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Jump_Kick1", L"Character/singo/Singo_JumpKick1.bmp", 0, 0, 952, 430, 4, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Jump_Kick2", L"Character/singo/Singo_JumpKick2.bmp", 0, 0, 1152, 406, 4, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Jump_Punch1", L"Character/singo/Singo_JumpPunch1.bmp", 0, 0, 744, 478, 4, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Jump_Punch2", L"Character/singo/Singo_JumpPunch2.bmp", 0, 0, 796, 432, 4, 2, true, true, RGB(255, 0, 255));

	//===========신고 넉다운 이미지==============
	IMAGEMANAGER->addFrameImage(L"Singo_KnockDown", L"Character/singo/Singo_KnockDown.bmp", 0, 0, 2163, 420, 4, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_StandUp", L"Character/singo/Singo_StandUp.bmp", 0, 0, 996, 730, 6, 2, true, true, RGB(255, 0, 255));

	//===========신고 기술 이미지================
	IMAGEMANAGER->addFrameImage(L"Singo_Kick", L"Character/singo/Singo_Skill1.bmp", 0, 0, 5696, 648, 16, 2, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_chkang", L"Character/singo/Singo_Skill2.bmp", 0, 0, 1404, 604, 6, 2, true, true, RGB(255, 0, 255));

	return S_OK;
}
void singo::release(void)
{
	IMAGEMANAGER->deleteImage(L"Singo_chkang");
	IMAGEMANAGER->deleteImage(L"Singo_Kick");
	IMAGEMANAGER->deleteImage(L"Singo_StandUp");
	IMAGEMANAGER->deleteImage(L"Singo_KnockDown");
	IMAGEMANAGER->deleteImage(L"Singo_Jump_Punch2");
	IMAGEMANAGER->deleteImage(L"Singo_Jump_Punch1");
	IMAGEMANAGER->deleteImage(L"Singo_Jump_Kick2");
	IMAGEMANAGER->deleteImage(L"Singo_Jump_Kick1");
	IMAGEMANAGER->deleteImage(L"Singo_RetreatJump");
	IMAGEMANAGER->deleteImage(L"Singo_ForwardJump");
	IMAGEMANAGER->deleteImage(L"Singo_MidJump");
	IMAGEMANAGER->deleteImage(L"Singo_Forward");
	IMAGEMANAGER->deleteImage(L"singo_Retreat");
	IMAGEMANAGER->deleteImage(L"Singo_Sit_Kick2");
	IMAGEMANAGER->deleteImage(L"Singo_Sit_Kick1");
	IMAGEMANAGER->deleteImage(L"Singo_Sit_Punch2");
	IMAGEMANAGER->deleteImage(L"Singo_Sit_Punch1");
	IMAGEMANAGER->deleteImage(L"Singo_Sit_Guard");
	IMAGEMANAGER->deleteImage(L"Singo_Sit_hit");
	IMAGEMANAGER->deleteImage(L"Singo_Sit");
	IMAGEMANAGER->deleteImage(L"singo_Run");
	IMAGEMANAGER->deleteImage(L"Singo_Stand_Kick2");
	IMAGEMANAGER->deleteImage(L"Singo_Stand_Kick1");
	IMAGEMANAGER->deleteImage(L"Singo_Stand_Punch2");
	IMAGEMANAGER->deleteImage(L"Singo_Stand_Punch1");
	IMAGEMANAGER->deleteImage(L"Singo_Stand_Guard");
	IMAGEMANAGER->deleteImage(L"Singo_Stand_Hit");
	IMAGEMANAGER->deleteImage(L"Singo_Stand");

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

void singo::command(void)
{

}
void singo::inputCommand(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_vCommand.push_back(LEFT);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_vCommand.push_back(RIGHT);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_vCommand.push_back(UP);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_vCommand.push_back(DOWN);
	}

}