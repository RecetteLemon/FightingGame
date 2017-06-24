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
	if (_vCommand.size() > 0) _commandDelay += TIMEMANAGER->getElapsedTime(); // 커맨드 입력시 커맨드 입력 시간은 늘어난다
	if (_commandDelay > _commandInputTime) // 만약 커맨드 입력 시간이 입력해야되는 시간보다 많아지면 커맨드 입력 실패
	{
		_commandDelay = 0;
		_vCommand.clear();
	}

	if (_vCommand.size() > 1) // 커맨드 입력이 2개 이상
	{
		for (_viCommand = _vCommand.begin(); _viCommand != _vCommand.end() - 1; ++_viCommand)
		{
			if (*_viCommand == RIGHT && *(_viCommand + 1) == RIGHT) // 오른쪽 누르고 다음 커맨드에 상태값이 오른쪽이면 오른쪽 대쉬
			{
				_playerPos = DASH_RIGHT;

				_vCommand.clear();
				break;
			}
			else if (*_viCommand == LEFT && *(_viCommand + 1) == LEFT) // 왼쪽 누르고 다음 커맨드에 상태값이 왼쪽이면 왼쪽 대쉬
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
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) // 왼쪽 누를시 커맨드에 왼쪽 상태값을 넣는다
	{
		_vCommand.push_back(LEFT);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) // 오른쪽 누를시 커맨드에 오른쪽 상태값을 넣는다
	{
		_vCommand.push_back(RIGHT);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP)) // 위를 누를시 커맨드에 위 상태값을 넣는다
	{
		_vCommand.push_back(UP);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN)) // 아래를 누를시 커맨드에 아래 상태값을 넣는다
	{
		_vCommand.push_back(DOWN);
	}
}