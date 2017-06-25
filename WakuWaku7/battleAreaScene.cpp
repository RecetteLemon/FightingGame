#include "stdafx.h"
#include "battleAreaScene.h"


battleAreaScene::battleAreaScene()
{
}


battleAreaScene::~battleAreaScene()
{
}

HRESULT battleAreaScene::init(void)
{
	_background1 = IMAGEMANAGER->addFrameImage(L"Background1", L"Image/Background1.bmp", 24000, 800, 24, 1, true, true, RGB(255, 0, 255));

	_pM = new playerManager;
	_pM->init();

	_cameraX = 100;

	_elapsedTime = 0;
	return S_OK;
}

void battleAreaScene::release(void)
{
	_pM->release();
	IMAGEMANAGER->deleteImage(L"Background1");
}

void battleAreaScene::update(void)
{
	if (_elapsedTime >= 1.0f / 10.0f)
	{
		_background1->setFrameX(_background1->getFrameX() + 1);
		_elapsedTime = 0;
	}


	_pM->update();
	




	_elapsedTime += TIMEMANAGER->getElapsedTime();
}

void battleAreaScene::render(void)
{
	_background1->frameRender(getMemDC(), -_cameraX, -200, _background1->getFrameX(), _background1->getFrameY());
	_pM->render();
}
