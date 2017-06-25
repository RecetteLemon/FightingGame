#include "stdafx.h"
#include "playerManager.h"
#include "may.h"
#include "heidern.h"
#include "singo.h"
#include "king.h"
#include "dummy.h"


playerManager::playerManager()
{
}


playerManager::~playerManager()
{
}


HRESULT playerManager::init(void)	  
{
	
	_dummy = NULL;

	vector<wstring> vStr;
	vStr = TXTDATA->txtLoad(L"SelectChara1.txt");
	_chara1 = (CHARACTER)(_wtoi(vStr[0].c_str()));

	vStr = TXTDATA->txtLoad(L"SelectChara2.txt");
	_chara2 = (CHARACTER)(_wtoi(vStr[0].c_str()));

	switch (_chara1)
	{
	case MAY:
		_player1 = new may;
		_player1->init();
		break;

	case HEIDERN:
		_player1 = new heidern;
		_player1->init();
		break;

	case SINGO:
		_player1 = new singo;
		_player1->init();
		break;

	case KING:
		_player1 = new king;
		_player1->init();
		break;
	}
	

	switch (_chara2)
	{
	case MAY:
		_player2 = new may;
		_player2->init();
		break;

	case HEIDERN:
		_player2 = new heidern;
		_player2->init();
		break;

	case SINGO:
		_player2 = new singo;
		_player2->init();
		break;

	case KING:
		_player2 = new king;
		_player2->init();
		break;
	}


	_player2->setX(600);
	_player2->set1P(false);

	_dummy = new dummy;
	_dummy->init();

	return S_OK;
}

void playerManager::release(void)	  
{
	SAFE_RELEASE(_player1);
	SAFE_RELEASE(_player2);

	SAFE_DELETE(_player1);
	SAFE_DELETE(_player2);
}
void playerManager::update(void)	  
{
	if (_player1->getPos() == STAND_RIGHT || _player1->getPos() == STAND_LEFT)
	{
		if (_player1->getX() <=  _player2->getX()) _player1->setRight(true);
		else _player1->setRight(false);
	}

	if (_player2->getPos() == STAND_RIGHT || _player2->getPos() == STAND_LEFT)
	{
		if (_player1->getX() > _player2->getX()) _player2->setRight(true);
		else _player2->setRight(false);
	}

	_player1->update();
	_player2->update();
	
}

void playerManager::render(void)
{
	_player1->render();
	_player2->render();

	// 플레이어 1
	if (_player1->getX() - 50 <= _cameraX && 
		_player2->getX() + 50 <= WINSIZEX + _cameraX &&
		_cameraX >= 0)
	{
		_cameraX = _player1->getX() - 50;
	}

	if (_player1->getX() + 50 >= WINSIZEX + _cameraX &&
		_player2->getX() - 50 >= _cameraX &&
		_cameraX <= 200)
	{
		_cameraX = (_player1->getX() + 50) - WINSIZEX;
	}

	// 플레이어 2
	if (_player2->getX() - 50 <= _cameraX &&
		_player1->getX() + 50 <= WINSIZEX + _cameraX &&
		_cameraX >= 0)
	{
		_cameraX = _player2->getX() - 50;
	}

	if (_player2->getX() + 50 >= WINSIZEX + _cameraX &&
		_player1->getX() - 50 >= _cameraX &&
		_cameraX <= 200)
	{
		_cameraX = (_player2->getX() + 50) - WINSIZEX;
	}

	if (_cameraX < 0) _cameraX = 0;
	if (_cameraX > 200) _cameraX = 200;

	
}