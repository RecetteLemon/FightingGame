#include "stdafx.h"
#include "Heidern.h"


Heidern::Heidern()
{
}


Heidern::~Heidern()
{
}

HRESULT Heidern::init()
{
	player::init();

	_img = new image*[POS_END];
	_ani = new animation[POS_END];
	ZeroMemory(_img, sizeof(image*) * (int)POS_END);
	ZeroMemory(_ani, sizeof(animation*) * (int)POS_END);
	
	//하이데른 스탠드 이미지
	IMAGEMANAGER->addFrameImage(L"HeidernStandR", L"Character/Heidern/Heidern_Rightstand.bmp", 600, 260, 4, 1, true, true, RGB(255, 0, 255));
	this->motionInit(STAND_RIGHT, L"HeidernStandR", false, true, 4);
	
	IMAGEMANAGER->addFrameImage(L"HeidernStandL", L"Character/Heidern/Heidern_Leftstand.bmp", 600, 260, 4, 1, true, true, RGB(255, 0, 255));
	this->motionInit(STAND_LEFT, L"HeidernStandL", false, true, 4);
	
	//하이데른 백스텝 이미지
	IMAGEMANAGER->addFrameImage(L"HeidernBackwardL", L"Character/Heidern/Heidern_LeftBackward.bmp", 900, 260, 6, 1, true, true, RGB(255, 0, 255));
	this->motionInit(BACKWALK_LEFT, L"HeidernBackwardL", false, true, 6);
	
	IMAGEMANAGER->addFrameImage(L"HeidernBackwardR", L"Character/Heidern/Heidern_RightBackward.bmp", 900, 260, 6, 1, true, true, RGB(255, 0, 255));
	this->motionInit(BACKWALK_RIGHT, L"HeidernBackwardR", false, true, 6);
	
	//하이데른 전진 이미지
	IMAGEMANAGER->addFrameImage(L"HeidernForwardL", L"Character/Heidern/Heidern_LeftForward.bmp", 1050, 260, 7, 1, true, true, RGB(255, 0, 255));
	this->motionInit(WALK_LEFT, L"HeidernBackwardL", false, true, 7);
	
	IMAGEMANAGER->addFrameImage(L"HeidernForwardR", L"Character/Heidern/Heidern_RightForward.bmp", 1050, 260, 7, 1, true, true, RGB(255, 0, 255));
	this->motionInit(WALK_RIGHT, L"HeidernBackwardR", false, true, 7);
	
	//하이데른 제자리 점프 이미지
	IMAGEMANAGER->addFrameImage(L"HeidernMidJumpL", L"Character/Heidern/Heidern_LeftMidJump.bmp", 1050, 300, 7, 1, true, true, RGB(255, 0, 255));
	this->motionInit(JUMP_LEFT, L"HeidernMidJumpL", false, true, 7);
	
	IMAGEMANAGER->addFrameImage(L"HeidernMidJumpR", L"Character/Heidern/Heidern_RightMidJump.bmp", 1050, 300, 7, 1, true, true, RGB(255, 0, 255));
	this->motionInit(JUMP_RIGHT, L"HeidernMidJumpR", false, true, 7);
	
	//하이데른 앞 점프 이미지
	IMAGEMANAGER->addFrameImage(L"HeidernFowardJumpL", L"Character/Heidern/Heidern_LeftFowardJump.bmp", 1600, 300, 8, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"HeidernFowardJumpR", L"Character/Heidern/Heidern_RightFowardJump.bmp", 1600, 300, 8, 1, true, true, RGB(255, 0, 255));

	//하이데른 백점프 이미지
	IMAGEMANAGER->addFrameImage(L"HeidernBackJumpL", L"Character/Heidern/Heidern_LeftBackJump.bmp", 1800, 300, 9, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"HeidernBackJumpR", L"Character/Heidern/Heidern_RightBackJump.bmp", 1800, 300, 9, 1, true, true, RGB(255, 0, 255));
	
	//하이데른 앉기
	IMAGEMANAGER->addImage(L"HeidernsitL", L"Character/Heidern/Heidern_Leftsit.bmp", 150, 260, 1, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(L"HeidernsitR", L"Character/Heidern/Heidern_Rightsit.bmp", 150, 260, 1, 1, true, true, RGB(255, 0, 255));
	
	//하이데른 점프어택
	IMAGEMANAGER->addFrameImage(L"HeidernJumpAttkL", L"Character/Heidern/Heidern_LeftJumpAttk.bmp", 630, 260, 3, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"HeidernJumpAttkR", L"Character/Heidern/Heidern_RightJumpAttk.bmp", 630, 260, 3, 1, true, true, RGB(255, 0, 255));
	
	//하이데른 제자리어택
	IMAGEMANAGER->addFrameImage(L"HeidernStandAttkL", L"Character/Heidern/Heidern_LeftStandAttk.bmp", 645, 260, 3, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"HeidernStandAttkR", L"Character/Heidern/Heidern_RightStandAttk.bmp", 645, 260, 3, 1, true, true, RGB(255, 0, 255));
	
	//하이데른 점프킥
	IMAGEMANAGER->addFrameImage(L"HeidernJumpKickL", L"Character/Heidern/Heidern_LeftJumpKick.bmp", 1540, 260, 3, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"HeidernJumpKickR", L"Character/Heidern/Heidern_RightJumpKick.bmp", 1540, 260, 3, 1, true, true, RGB(255, 0, 255));
	
	//하이데른 제자리킥
	IMAGEMANAGER->addFrameImage(L"HeidernStandKickL", L"Character/Heidern/Heidern_LeftStandKick.bmp", 1150, 260, 3, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"HeidernStandKickR", L"Character/Heidern/Heidern_RightStandKick.bmp", 1150, 260, 3, 1, true, true, RGB(255, 0, 255));
	
	_onRight = true;

	

	return S_OK;
}


void Heidern::release()
{
	SAFE_DELETE_ARRAY(_img);
	SAFE_DELETE_ARRAY(_ani);
}

void Heidern::update()
{
	player::update();
}


void Heidern::render()
{
	this->draw();
	control();
}


void Heidern::control()
{
	_y -= _jumpForce;
	_jumpForce -= _gravity;

	if (_y >= 500)
	{
		_jumpForce = 0;
		_y = 500;
	}


	//키매니저
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_pos = STAND_LEFT;
		if (!_ani[_pos].isPlay()) _ani[_pos].start();
	}
	 
	
    if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_pos = STAND_RIGHT;
		if (!_ani[_pos].isPlay()) _ani[_pos].start();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_pos = JUMP_RIGHT;
		_jumpForce = PLAYER_JUMPFORCE;
		_vCommand.push_back(UP);
		if (!_ani[_pos].isPlay()) _ani[_pos].start();
	}


}
