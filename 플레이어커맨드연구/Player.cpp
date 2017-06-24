#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

HRESULT Player::init()
{
	keyTimer = 0;
	_currentInput = NOT;
	_prevInput = NOT;


	return S_OK;
}

void Player::release()
{

}

void Player::update()
{
	keyInput();

	if (_vCommand.size() != NULL)
	{
		keyTimer += TIMEMANAGER->getElapsedTime();

		if (keyTimer >= 0.2f)
		{
			_vCommand.clear();
			_prevInput = NOT;
			keyTimer = 0;
		}
	}
}

void Player::render()
{
	if (_vCommand.size() != NULL)
	{
		for (int i = 0; i < _vCommand.size(); ++i)
		{
			if (_vCommand[i] == LEFT)
			{
				TextOut(getMemDC(), 50, 100 + i * 25, TEXT("LEFT"), strlen("LEFT"));
			}
			else if (_vCommand[i] == LEFT_DOWN)
			{
				TextOut(getMemDC(), 50, 100 + i * 25, TEXT("LEFT_DOWN"), strlen("LEFT_DOWN"));
			}
			else if (_vCommand[i] == DOWN)
			{
				TextOut(getMemDC(), 50, 100 + i * 25, TEXT("DOWN"), strlen("DOWN"));
			}
			else if (_vCommand[i] == RIGHT_DOWN)
			{
				TextOut(getMemDC(), 50, 100 + i * 25, TEXT("RIGHT_DOWN"), strlen("RIGHT_DOWN"));
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


}

void Player::keyInput()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && 
		!KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_currentInput = LEFT;
		if (_prevInput != _currentInput)
		{
			_prevInput = _currentInput;
			_vCommand.push_back(LEFT);
			keyTimer = 0;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && 
		KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_currentInput = LEFT_DOWN;
		if (_prevInput != _currentInput)
		{
			_prevInput = _currentInput;
			_vCommand.push_back(LEFT_DOWN);
			keyTimer = 0;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && 
		KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_currentInput = RIGHT_DOWN;
		if (_prevInput != _currentInput)
		{
			_prevInput = _currentInput;
			_vCommand.push_back(RIGHT_DOWN);
			keyTimer = 0;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) &&
		!KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_currentInput = RIGHT;
		if (_prevInput != _currentInput)
		{
			_prevInput = _currentInput;
			_vCommand.push_back(RIGHT);
			keyTimer = 0;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && 
		!KEYMANAGER->isStayKeyDown(VK_LEFT) && 
		!KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_currentInput = DOWN;
		if (_prevInput != _currentInput)
		{
			_prevInput = _currentInput;
			_vCommand.push_back(DOWN);
			keyTimer = 0;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_currentInput = UP;
		if (_prevInput != _currentInput)
		{
			_prevInput = _currentInput;
			_vCommand.push_back(UP);
			keyTimer = 0;
		}
	}
	
}