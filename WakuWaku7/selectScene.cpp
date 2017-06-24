#include "stdafx.h"
#include "selectScene.h"


selectScene::selectScene()
{
	
}


selectScene::~selectScene()
{
}


HRESULT selectScene::init(void)
{
	
	_selectBackground = IMAGEMANAGER->addImage(L"SelectBackground", L"Image/SelectBackground.bmp", 764, 622, true, true, RGB(255, 0, 255));
	_selectChara = IMAGEMANAGER->addImage(L"SelectChara", L"Image/SelectCharacter.bmp", 474, 56, true, true, RGB(255, 0, 255));
	_vs = IMAGEMANAGER->addImage(L"VS", L"Image/VS.bmp", 218, 197, true, true, RGB(255, 0, 255));


	_selectChara->setX(WINSIZEX / 2 - _selectChara->getWidth() / 2);
	_selectChara->setY(-300);

	_vs->setX(WINSIZEX / 2 - _vs->getWidth() / 2);
	_vs->setY(_selectChara->getY() + 100);

	ZeroMemory(_elapsedTime, sizeof(_elapsedTime));
	_loopTime = 0;
	_vibCount = 0;

	_startSelect = false;
	_vib = false;

	return S_OK;
}
void selectScene::release(void)
{
	IMAGEMANAGER->deleteImage(L"SelectBackground");
	IMAGEMANAGER->deleteImage(L"SelectChara");
	IMAGEMANAGER->deleteImage(L"VS");

	_selectBackground = NULL;
	_selectChara = NULL;
	_vs = NULL;
}
void selectScene::update(void)
{
	if (!_startSelect)
	{
		_loopTime -= 50;
		if (_elapsedTime[START_SELECT] >= 1.5f) _startSelect = true;
	}
	else
	{
		if (_elapsedTime[START_SELECT] >= 1.0f / 30.0f)
		{
			_loopTime--;
			_elapsedTime[START_SELECT] = 0;
		}
	}


	if (_startSelect)
	{
		if (_selectChara->getY() <= 20)
		{
			_selectChara->setY(_selectChara->getY() + 20);
			_vs->setY(_selectChara->getY() + 150);
		}
		else
		{
			_vib = true;
		}

		this->imageVib();
		
	}

	_elapsedTime[START_SELECT] += TIMEMANAGER->getElapsedTime();
	_elapsedTime[VIB] += TIMEMANAGER->getElapsedTime();
}
void selectScene::render(void)
{
	_selectBackground->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), _loopTime, -_loopTime, false, 255);
	_selectChara->render(getMemDC());
	_vs->render(getMemDC());
}


void selectScene::imageVib()
{
	if (_vib && _vibCount <= 10)
	{
		if (_elapsedTime[VIB] >= 1.0f / 30.0f)
		{
			if (_selectChara->getY() >= 20)
			{
				_selectChara->setY(_selectChara->getY() - 10);
				_vs->setY(_vs->getY() - 10);
			}
			else
			{
				_selectChara->setY(_selectChara->getY() + 10);
				_vs->setY(_vs->getY() + 10);
			}

			_vibCount++;
			_elapsedTime[VIB] = 0;
		}
	}
}