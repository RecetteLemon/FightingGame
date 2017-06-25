#include "stdafx.h"
#include "player.h"


player::player():
	_commandDelay(0),
	_commandInputTime(2.5f)
{
}


player::~player()
{
}


HRESULT player::init(void) 
{
	_1P = true;
	_pos = STAND_RIGHT;
	_onRight = true;
	_x = 200;
	_y = 550;
	_speed = PLAYER_SPEED;
	_jumpForce = 0;
	_gravity = GRAVITY;

	if (!_ani[_pos].isPlay()) _ani[_pos].start();

	return S_OK;
}
void player::release(void) 
{

}
void player::update(void)  
{
	_ani[_pos].frameUpdate(TIMEMANAGER->getElapsedTime());

	this->inputCommand();
	this->command();
	this->control();

	_rc = RectMake(_x - _img[_pos]->getFrameWidth() / 2, _y - _img[_pos]->getFrameHeight(), _img[_pos]->getFrameWidth(), _img[_pos]->getFrameHeight());

	
}


void player::render(void)
{
	this->draw();
}

//==================================================================================
void player::draw(void)
{
	_img[_pos]->aniAlphaRender(getMemDC(), _rc.left - _cameraX, _rc.top, &_ani[_pos], 255);


#ifdef _DEBUG
	SelectObject(getMemDC(), GetStockObject(NULL_BRUSH));
	Rectangle(getMemDC(), _rc.left - _cameraX, _rc.top, _rc.right - _cameraX, _rc.bottom);
#endif
}


void player::command()
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
			if (*_viCommand == RIGHT && *(_viCommand + 1) == RIGHT)
			{
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

void player::inputCommand()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_vCommand.push_back(LEFT);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_vCommand.push_back(RIGHT);
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_vCommand.push_back(DOWN);
	}
}

void player::control()
{
	if (_1P)
	{
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && KEYMANAGER->isStayKeyDown(VK_LEFT) && _y >= 500)
		{
			if (_onRight)
			{
				_pos = STAND_RIGHT;
				if (!_ani[_pos].isPlay()) _ani[_pos].start();
			}
			else
			{
				_pos = STAND_LEFT;
				if (!_ani[_pos].isPlay()) _ani[_pos].start();
			}
		}
		else
		{

			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				if (_onRight)
				{
					_pos = WALK_RIGHT;
					if (!_ani[_pos].isPlay()) _ani[_pos].start();
				}
				else
				{
					_pos = BACKWALK_LEFT;
					if (!_ani[_pos].isPlay()) _ani[_pos].start();
				}
				_x += _speed;
			}
			else if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				if (!_onRight)
				{
					_pos = WALK_LEFT;
					if (!_ani[_pos].isPlay()) _ani[_pos].start();
				}
				else
				{
					_pos = BACKWALK_RIGHT;
					if (!_ani[_pos].isPlay()) _ani[_pos].start();
				}
				_x -= _speed;
			}
			else if (KEYMANAGER->isStayKeyDown(VK_DOWN))
			{
				if (_onRight)
				{
					_pos = SIT_RIGHT;
					if (!_ani[_pos].isPlay()) _ani[_pos].start();
					if (_ani[_pos].getIndex() >= 5) _ani[_pos].setIndex(1);
				}
				else
				{
					_pos = SIT_LEFT;
					if (!_ani[_pos].isPlay()) _ani[_pos].start();
					if (_ani[_pos].getIndex() >= 5) _ani[_pos].setIndex(1);
				}
			}

			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				_jumpForce = PLAYER_JUMPFORCE;
				_vCommand.push_back(UP);
			}

		}


		if (!KEYMANAGER->isOnceKeyDown(VK_UP) && !KEYMANAGER->isOnceKeyDown(VK_DOWN) &&
			!KEYMANAGER->isOnceKeyDown(VK_RIGHT) && !KEYMANAGER->isOnceKeyDown(VK_LEFT) &&
			!KEYMANAGER->isStayKeyDown(VK_RIGHT) && !KEYMANAGER->isStayKeyDown(VK_LEFT) &&
			!KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_ani[SIT_RIGHT].stop();
			_ani[SIT_LEFT].stop();
			if (_onRight)
			{
				_pos = STAND_RIGHT;
				if (!_ani[_pos].isPlay()) _ani[_pos].start();
			}
			else
			{
				_pos = STAND_LEFT;
				if (!_ani[_pos].isPlay()) _ani[_pos].start();
			}
		}
	}
	else
	{
		if (KEYMANAGER->isStayKeyDown('D') && KEYMANAGER->isStayKeyDown('A') && _y >= 500)
		{
			if (_onRight)
			{
				_pos = STAND_RIGHT;
				if (!_ani[_pos].isPlay()) _ani[_pos].start();
			}
			else
			{
				_pos = STAND_LEFT;
				if (!_ani[_pos].isPlay()) _ani[_pos].start();
			}
		}

		if (KEYMANAGER->isStayKeyDown('D'))
		{
			if (_onRight)
			{
				_pos = WALK_RIGHT;
				if (!_ani[_pos].isPlay()) _ani[_pos].start();
			}
			else
			{
				_pos = BACKWALK_LEFT;
				if (!_ani[_pos].isPlay()) _ani[_pos].start();
			}
			_x += _speed;
		}
		else if (KEYMANAGER->isStayKeyDown('A'))
		{
			if (!_onRight)
			{
				_pos = WALK_LEFT;
				if (!_ani[_pos].isPlay()) _ani[_pos].start();
			}
			else
			{
				_pos = BACKWALK_RIGHT;
				if (!_ani[_pos].isPlay()) _ani[_pos].start();
			}
			_x -= _speed;
		}

		if (!KEYMANAGER->isOnceKeyDown('D') && !KEYMANAGER->isOnceKeyDown('A') &&
			!KEYMANAGER->isStayKeyDown('D') && !KEYMANAGER->isStayKeyDown('A'))
		{
			_ani[SIT_RIGHT].stop();
			_ani[SIT_LEFT].stop();
			if (_onRight)
			{
				_pos = STAND_RIGHT;
				if (!_ani[_pos].isPlay()) _ani[_pos].start();
			}
			else
			{
				_pos = STAND_LEFT;
				if (!_ani[_pos].isPlay()) _ani[_pos].start();
			}
		}
	}

	

	if (_y > 550)
	{
		if (_onRight)
		{
			_pos = STAND_RIGHT;
			if (!_ani[_pos].isPlay()) _ani[_pos].start();
		}
		else
		{
			_pos = STAND_LEFT;
			if (!_ani[_pos].isPlay()) _ani[_pos].start();
		}

		_jumpForce = 0;
		_y = 550;
	}
}

void player::motionInit(POSITION pos, wchar_t* keyName, bool reverse, bool loop, int fps)
{
	_img[pos] = IMAGEMANAGER->findImage(keyName);
	_ani[pos].init(_img[pos]->getWidth(), _img[pos]->getHeight(), _img[pos]->getFrameWidth(), _img[pos]->getFrameHeight());
	_ani[pos].setDefPlayFrame(reverse, loop);
	_ani[pos].setFPS(fps);
}

