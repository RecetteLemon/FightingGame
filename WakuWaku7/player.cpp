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

	return S_OK;
}
void player::release(void) 
{

}
void player::update(void)  
{

}
void player::render(void)  
{

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
				_playerPos = DASH_RIGHT;

				_vCommand.clear();
				break;
			}
			else if (*_viCommand == LEFT && *(_viCommand + 1) == LEFT)
			{
				_playerPos = DASH_LEFT;

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
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_vCommand.push_back(UP);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_vCommand.push_back(DOWN);
	}
}