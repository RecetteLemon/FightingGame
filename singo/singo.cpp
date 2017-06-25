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
	_commandInputTime = 0.4f;

	_img = new image*[POS_END];
	_ani = new animation[POS_END];
	ZeroMemory(_img, sizeof(image*) * (int)POS_END);
	ZeroMemory(_ani, sizeof(animation) * (int)POS_END);


	//===========신고 서있을때 이미지=============
	IMAGEMANAGER->addFrameImage(L"Singo_Right_Stand", L"Character/singo/Singo_Right_Stand.bmp", 0, 0, 1272, 265, 8, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_StandHit", L"Character/singo/Singo_Right_Standhit.bmp", 0, 0, 1187, 265, 6, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_StandGuard", L"Character/singo/Singo_Right_Standguard.bmp", 0, 0, 211, 228, 1, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_StandPunch1", L"Character/singo/Singo_Right_Standpunch1.bmp", 0, 0, 669, 259, 3, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_StandPunch2", L"Character/singo/Singo_Right_Standpunch2.bmp", 0, 0, 3014, 297, 11, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_StandKick1", L"Character/singo/Singo_Right_Standkick1.bmp", 0, 0, 2415, 277, 7, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_StandKick2", L"Character/singo/Singo_Right_Standkick2.bmp", 0, 0, 2960, 288, 10, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_Run", L"Character/singo/Singo_Right_Run.bmp", 0, 0, 1452, 232, 6, 1, true, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage(L"Singo_Left_Stand", L"Character/singo/Singo_Left_Stand.bmp", 0, 0, 1272, 265, 8, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_StandHit", L"Character/singo/Singo_Left_Standhit.bmp", 0, 0, 1187, 265, 6, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_StandGuard", L"Character/singo/Singo_Left_Standguard.bmp", 0, 0, 211, 228, 1, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_StandPunch1", L"Character/singo/Singo_Left_Standpunch1.bmp", 0, 0, 669, 259, 3, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_StandPunch2", L"Character/singo/Singo_Left_Standpunch2.bmp", 0, 0, 3014, 297, 11, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_StandKick1", L"Character/singo/Singo_Left_Standkick1.bmp", 0, 0, 2415, 277, 7, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_StandKick2", L"Character/singo/Singo_Left_Standkick2.bmp", 0, 0, 2960, 288, 10, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_Run", L"Character/singo/Singo_Left_Run.bmp", 0, 0, 1452, 232, 6, 1, true, true, RGB(255, 0, 255));

	//===========신고 앉아있을때 이미지=============
	IMAGEMANAGER->addFrameImage(L"Singo_Right_Sit", L"Character/singo/Singo_Right_sit.bmp", 0, 0, 150, 172, 1, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_Sithit", L"Character/singo/Singo_Right_Sithit.bmp", 0, 0, 880, 183, 5, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_SitGuard", L"Character/singo/Singo_Right_Sitguard.bmp", 0, 0, 138, 179, 1, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_SitPunch1", L"Character/singo/Singo_Right_Sitpunch1.bmp", 0, 0, 660, 172, 3, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_SitPunch2", L"Character/singo/Singo_Right_Sitpunch2.bmp", 0, 0, 1568, 353, 7, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_SitKick1", L"Character/singo/Singo_Right_Sitkick1.bmp", 0, 0, 738, 172, 3, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_SitKick2", L"Character/singo/Singo_Right_Sitkick2.bmp", 0, 0, 3740, 213, 11, 1, true, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage(L"Singo_Left_Sit", L"Character/singo/Singo_Left_sit.bmp", 0, 0, 150, 172, 1, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_Sithit", L"Character/singo/Singo_Left_Sithit.bmp", 0, 0, 880, 183, 5, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_SitGuard", L"Character/singo/Singo_Left_Sitguard.bmp", 0, 0, 138, 179, 1, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_SitPunch1", L"Character/singo/Singo_Left_Sitpunch1.bmp", 0, 0, 660, 172, 3, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_SitPunch2", L"Character/singo/Singo_Left_Sitpunch2.bmp", 0, 0, 1568, 353, 7, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_SitKick1", L"Character/singo/Singo_Left_Sitkick1.bmp", 0, 0, 738, 172, 3, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_SitKick2", L"Character/singo/Singo_Left_Sitkick2.bmp", 0, 0, 3740, 213, 11, 1, true, true, RGB(255, 0, 255));

	//===========신고 이동할때 이미지=============
	IMAGEMANAGER->addFrameImage(L"Singo_Right_Retreat", L"Character/singo/Singo_Right_Retreat.bmp", 0, 0, 876, 286, 6, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_Forward", L"Character/singo/Singo_Right_Forward.bmp", 0, 0, 700, 286, 5, 1, true, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage(L"Singo_Left_Retreat", L"Character/singo/Singo_Left_Retreat.bmp", 0, 0, 876, 286, 6, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_Forward", L"Character/singo/Singo_Left_Forward.bmp", 0, 0, 700, 286, 5, 1, true, true, RGB(255, 0, 255));

	//===========신고 점프할때 이미지=============
	IMAGEMANAGER->addFrameImage(L"Singo_Right_MidJump", L"Character/singo/Singo_Right_Midjump.bmp", 0, 0, 2106, 354, 9, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_ForwardJump", L"Character/singo/Singo_Right_Frowardjump.bmp", 0, 0, 2000, 354, 10, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_RetreatJump", L"Character/singo/Singo_Right_Retreatjump.bmp", 0, 0, 1800, 354, 10, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_Jump_Kick1", L"Character/singo/Singo_Right_Jumpkick1.bmp", 0, 0, 952, 215, 4, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_Jump_Kick2", L"Character/singo/Singo_Right_Jumpkick2.bmp", 0, 0, 1152, 203, 4, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_JumpPunch2", L"Character/singo/Singo_Right_Punch1.bmp", 0, 0, 744, 239, 4, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_JumpPunch1", L"Character/singo/Singo_Right_Punch2.bmp", 0, 0, 796, 216, 4, 1, true, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage(L"Singo_Left_MidJump", L"Character/singo/Singo_Left_Midjump.bmp", 0, 0, 2106, 354, 9, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_ForwardJump", L"Character/singo/Singo_Left_Frowardjump.bmp", 0, 0, 2000, 354, 10, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_RetreatJump", L"Character/singo/Singo_Left_Retreatjump.bmp", 0, 0, 1800, 354, 10, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_Jump_Kick1", L"Character/singo/Singo_Left_Jumpkick1.bmp", 0, 0, 952, 215, 4, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_Jump_Kick2", L"Character/singo/Singo_Left_Jumpkick2.bmp", 0, 0, 1152, 203, 4, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_JumpPunch2", L"Character/singo/Singo_Left_Punch1.bmp", 0, 0, 744, 239, 4, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_JumpPunch1", L"Character/singo/Singo_Left_Punch2.bmp", 0, 0, 796, 216, 4, 1, true, true, RGB(255, 0, 255));

	//===========신고 넉다운 이미지==============
	IMAGEMANAGER->addFrameImage(L"Singo_Right_KnockDown", L"Character/singo/Singo_Right_Knockdown.bmp", 0, 0, 2163, 210, 4, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_StandUp", L"Character/singo/Singo_Right_Standup.bmp", 0, 0, 996, 365, 6, 1, true, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage(L"Singo_Left_KnockDown", L"Character/singo/Singo_Left_Knockdown.bmp", 0, 0, 2163, 210, 4, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_StandUp", L"Character/singo/Singo_Left_Standup.bmp", 0, 0, 996, 365, 6, 1, true, true, RGB(255, 0, 255));

	//===========신고 기술 이미지================
	IMAGEMANAGER->addFrameImage(L"Singo_Right_Skill1", L"Character/singo/Singo_Right_Skill1.bmp", 0, 0, 5696, 324, 16, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Right_Skill2", L"Character/singo/Singo_Right_Skill2.bmp", 0, 0, 1404, 302, 6, 1, true, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage(L"Singo_Left_Skill1", L"Character/singo/Singo_Left_Skill1.bmp", 0, 0, 5696, 324, 16, 1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(L"Singo_Left_Skill2", L"Character/singo/Singo_Left_Skill2.bmp", 0, 0, 1404, 302, 6, 1, true, true, RGB(255, 0, 255));



	//===========신고 모션별 이미지=============
	this->motionInit(STAND_RIGHT, L"Singo_Right_Stand", false, true, 10);
	this->motionInit(STAND_LEFT, L"Singo_Left_Stand", false, true, 10);
	this->motionInit(WALK_RIGHT, L"Singo_Right_Forward", false, false, 8);
	this->motionInit(WALK_LEFT, L"Singo_Left_Forward", false, false, 8);
	this->motionInit(BACKWALK_RIGHT, L"Singo_Right_Retreat", false, false, 8);
	this->motionInit(BACKWALK_LEFT, L"Singo_Left_Retreat", false, false, 8);
	this->motionInit(DASH_RIGHT, L"Singo_Right_Run", false, false, 6);
	this->motionInit(DASH_LEFT, L"Singo_Left_Run", false, false, 6);
	this->motionInit(JUMP_RIGHT, L"Singo_Right_ForwardJump", false, false, 10);
	this->motionInit(JUMP_MID, L"Singo_Right_MidJump", false, false, 8);
	this->motionInit(JUMP_LEFT, L"Singo_Left_RetreatJump", false, false, 10);
	this->motionInit(PUNCH1_RIGHT, L"Singo_Right_StandPunch1", false, false, 9);
	this->motionInit(PUNCH2_RIGHT, L"Singo_Right_StandPunch2", false, false, 12);
	this->motionInit(KICK1_RIGHT, L"Singo_Right_StandKick1", false, false, 14);
	this->motionInit(KICK2_RIGHT, L"Singo_Right_StandKick2", false, false, 13);
	this->motionInit(SIT_RIGHT, L"Singo_Right_Sit", false, false, 10);
	this->motionInit(JUMP_PUNCH1_RIGHT, L"Singo_Right_JumpPunch1", false, false, 8);
	this->motionInit(JUMP_PUNCH2_RIGHT, L"Singo_Right_JumpPunch2", false, false, 8);
	this->motionInit(JUMP_KICK1_RIGHT, L"Singo_Right_Jump_Kick1", false, false, 8);
	this->motionInit(JUMP_KICK2_RIGHT, L"Singo_Right_Jump_Kick2", false, false, 7);
	this->motionInit(SIT_PUNCH1_RIGHT, L"Singo_Right_SitPunch1", false, false, 7);
	this->motionInit(SIT_PUNCH2_RIGHT, L"Singo_Right_SitPunch2", false, false, 7);
	this->motionInit(SIT_KICK1_RIGHT, L"Singo_Right_SitKick1", false, false, 7);
	this->motionInit(SIT_KICK2_RIGHT, L"Singo_Right_SitKick2", false, false, 7);

	//============ 신고 사운드 ==============
	SOUNDMANAGER->addSound(L"신고작은공격", L"Sound/singo/Singoattack1.mp3", false, false);
	SOUNDMANAGER->addSound(L"신고큰공격", L"Sound/singo/Singoattack2.mp3", false, false);
	

	_x = 700;
	

	player::init();

	_pos = STAND_RIGHT;
	if (!_ani[_pos].isPlay()) _ani[_pos].start();

	return S_OK;
}
void singo::release(void)
{
	SAFE_DELETE_ARRAY(_img);
	SAFE_DELETE_ARRAY(_ani);

}
void singo::update(void)
{

	player::update();

	switch (_pos)
	{
	case player::STAND_RIGHT:
		break;
	case player::STAND_LEFT:
		break;
	case player::WALK_RIGHT:
		break;
	case player::WALK_LEFT:
		break;
	case player::BACKWALK_RIGHT:
		break;
	case player::BACKWALK_LEFT:
		break;
	case player::DASH_RIGHT:
		_x += PLAYER_SPEED;
		break;
	case player::DASH_LEFT:
		break;
	case player::JUMP_RIGHT:
		break;
	case player::JUMP_MID:
		break;
	case player::JUMP_LEFT:
		break;
	case player::DROP_RIGHT:
		break;
	case player::DROP_LEFT:
		break;
	case player::PUNCH1_RIGHT:
		
		break;
	case player::PUNCH2_RIGHT:
		break;
	case player::JUMP_PUNCH1_RIGHT:
		break;
	case player::JUMP_PUNCH2_RIGHT:
		break;
	case player::KICK1_RIGHT:
		break;
	case player::KICK2_RIGHT:
		break;
	case player::JUMP_KICK1_RIGHT:
		break;
	case player::JUMP_KICK2_RIGHT:
		break;
	case player::SIT_RIGHT:
		break;
	case player::SIT_PUNCH1_RIGHT:
		break;
	case player::SIT_PUNCH2_RIGHT:
		break;
	case player::SIT_KICK1_RIGHT:
		break;
	case player::SIT_KICK2_RIGHT:
		break;
	case player::POS_END:
		break;
	default:
		break;
	}


	inputCommand();
	
}
void singo::render(void)
{
	if (_vCommand.size() != NULL)
	{
		for (int i = 0; i < _vCommand.size(); ++i)
		{
			if (_vCommand[i] == LEFT)
			{
				TextOut(getMemDC(), 50, 100 + i * 25, TEXT("LEFT"), strlen("LEFT"));
			}
			else if (_vCommand[i] == DOWN)
			{
				TextOut(getMemDC(), 50, 100 + i * 25, TEXT("DOWN"), strlen("DOWN"));
			}
			else if (_vCommand[i] == RIGHT)
			{
				TextOut(getMemDC(), 50, 100 + i * 25, TEXT("RIGHT"), strlen("RIGHT"));
			}
			else if (_vCommand[i] == UP)
			{
				TextOut(getMemDC(), 50, 100 + i * 25, TEXT("UP"), strlen("UP"));
			}
		
		}
	}

	this->draw();
}


void singo::command()
{
	if (_vCommand.size() > 0) _commandDelay += TIMEMANAGER->getElapsedTime();
	if (_commandDelay > _commandInputTime)
	{
		_commandDelay = 0;
		_vCommand.clear();
	}

	if (_vCommand.size() > 1)
	{
		for (_viCommand = _vCommand.begin(); _viCommand != _vCommand.end() - 1; ++_viCommand)
		{
			if (*_viCommand == RIGHT /*&& *(_viCommand + 1) == RIGHT*/)
			{
				_pos = DASH_RIGHT;
				if (!_ani[_pos].isPlay()) _ani[_pos].start();
				_vCommand.clear();
				break;
			}
			else if (*_viCommand == LEFT && *(_viCommand + 1) == LEFT)
			{


				_vCommand.clear();
				break;
			}
		}
	}
}
void singo::control()
{
	//============방향키조작=============
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT) || KEYMANAGER->isOnceKeyUp(VK_LEFT)
		|| KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_pos = STAND_RIGHT;
		if (!_ani[_pos].isPlay()) _ani[_pos].start();
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _pos != JUMP_MID )
	{
		_x += PLAYER_SPEED - 2;
		_pos = WALK_RIGHT;
		if (!_ani[_pos].isPlay()) _ani[_pos].start();

		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_pos = JUMP_RIGHT;
			if (!_ani[_pos].isPlay()) _ani[_pos].start();
			_jumpForce = PLAYER_JUMPFORCE;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= PLAYER_SPEED - 2;
		_pos = BACKWALK_RIGHT;
		if (!_ani[_pos].isPlay()) _ani[_pos].start();
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_pos = SIT_RIGHT;
		if (!_ani[_pos].isPlay()) _ani[_pos].start();
	}


	
	if (KEYMANAGER->isOnceKeyDown('A') && _pos != PUNCH1_RIGHT && _pos != PUNCH2_RIGHT &&
		_pos != JUMP_PUNCH1_RIGHT && _pos != JUMP_PUNCH2_RIGHT && _pos != KICK1_RIGHT && _pos != KICK2_RIGHT &&
		_pos != JUMP_KICK1_RIGHT && _pos != JUMP_KICK2_RIGHT)
	{
		if ((int)_ani[_pos].getFramePos().x >= _img[_pos]->getMaxFrameX())
		{
			_pos = STAND_RIGHT;
			_ani[_pos].start();
		}

		if (_pos == STAND_RIGHT || _pos == WALK_RIGHT)
		{
			_pos = PUNCH1_RIGHT;
			if (!_ani[_pos].isPlay()) _ani[_pos].start();
		}
		else if (_pos == JUMP_RIGHT || _pos == JUMP_MID || _pos == JUMP_LEFT)
		{
			_pos = JUMP_PUNCH1_RIGHT;
			if (!_ani[_pos].isPlay()) _ani[_pos].start();
		}
		else if (_pos == SIT_RIGHT)
		{
			_pos = SIT_PUNCH1_RIGHT;
			if (!_ani[_pos].isPlay()) _ani[_pos].start();
		}
		if(_ani[_pos].isPlay()) SOUNDMANAGER->play(L"신고작은공격");

		
	
	}
	if (KEYMANAGER->isOnceKeyDown('S') && _pos != PUNCH1_RIGHT && _pos != PUNCH2_RIGHT &&
		_pos != JUMP_PUNCH1_RIGHT && _pos != JUMP_PUNCH2_RIGHT && _pos != KICK1_RIGHT && _pos != KICK2_RIGHT &&
		_pos != JUMP_KICK1_RIGHT && _pos != JUMP_KICK2_RIGHT)
	{
		if (_pos == STAND_RIGHT ||_pos == WALK_RIGHT)
		{
			_pos = PUNCH2_RIGHT;
			if (!_ani[_pos].isPlay()) _ani[_pos].start();
		}
		else if (_pos == JUMP_RIGHT || _pos == JUMP_MID || _pos == JUMP_LEFT)
		{
			_pos = JUMP_PUNCH2_RIGHT;
			if (!_ani[_pos].isPlay()) _ani[_pos].start();
		}

		if (_ani[_pos].isPlay()) SOUNDMANAGER->play(L"신고큰공격");
	}
	if (KEYMANAGER->isOnceKeyDown('D') && _pos != PUNCH1_RIGHT && _pos != PUNCH2_RIGHT &&
		_pos != JUMP_PUNCH1_RIGHT && _pos != JUMP_PUNCH2_RIGHT && _pos != KICK1_RIGHT && _pos != KICK2_RIGHT &&
		_pos != JUMP_KICK1_RIGHT && _pos != JUMP_KICK2_RIGHT)
	{
		if (_pos == STAND_RIGHT ||_pos == WALK_RIGHT)
		{
			_pos = KICK1_RIGHT;
			if (!_ani[_pos].isPlay()) _ani[_pos].start();
		}
		else if (_pos == JUMP_RIGHT || _pos == JUMP_MID || _pos == JUMP_LEFT)
		{
			_pos = JUMP_KICK1_RIGHT;
			if (!_ani[_pos].isPlay()) _ani[_pos].start();
		}

		if (_ani[_pos].isPlay()) SOUNDMANAGER->play(L"신고작은공격");
	}
	if (KEYMANAGER->isOnceKeyDown('F') && _pos != PUNCH1_RIGHT && _pos != PUNCH2_RIGHT &&
		_pos != JUMP_PUNCH1_RIGHT && _pos != JUMP_PUNCH2_RIGHT && _pos != KICK1_RIGHT && _pos != KICK2_RIGHT &&
		_pos != JUMP_KICK1_RIGHT && _pos != JUMP_KICK2_RIGHT)
	{
		if (_pos == STAND_RIGHT ||_pos == WALK_RIGHT)
		{
			_pos = KICK2_RIGHT;
			if (!_ani[_pos].isPlay()) _ani[_pos].start();
		}
		else if (_pos == JUMP_RIGHT || _pos == JUMP_MID || _pos == JUMP_LEFT )
		{
			_pos = JUMP_KICK2_RIGHT;
			if (!_ani[_pos].isPlay()) _ani[_pos].start();
		}
		if (_ani[_pos].isPlay()) SOUNDMANAGER->play(L"신고큰공격");
	}
	
	

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_pos = JUMP_MID;
		if (!_ani[_pos].isPlay()) _ani[_pos].start();
		_jumpForce = PLAYER_JUMPFORCE;
		_vCommand.push_back(UP);
	}


	_y -= _jumpForce;
	_jumpForce -= _gravity;

	if (_y >= 500)
	{
		
		_jumpForce = 0;
		_y = 500;
	}

}
void singo::action() 
{

}
void singo::inputCommand()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_vCommand.push_back(RIGHT);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_vCommand.push_back(LEFT);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_vCommand.push_back(DOWN);
	}

}