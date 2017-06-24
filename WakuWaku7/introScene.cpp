#include "stdafx.h"
#include "introScene.h"



introScene::introScene()
{
}


introScene::~introScene()
{
}


HRESULT introScene::init(void)
{
	_introBackground = IMAGEMANAGER->addImage(L"IntroBackground", L"Image/IntroBackground.bmp", 922, 811, true, true, RGB(255, 0, 255));
	_introMain = IMAGEMANAGER->addFrameImage(L"IntroMain", L"Image/WakuWaku7Intro.bmp", 6960, 400, 12, 1, true, true, RGB(255, 0, 255));


	_aniMain = new animation;
	_aniMain->init(_introMain->getWidth(), _introMain->getHeight(), _introMain->getFrameWidth(), _introMain->getFrameHeight());
	_aniMain->setDefPlayFrame(false, true);
	_aniMain->setFPS(10);
	_aniMain->start();

	_loopTime = 0;
	_elapsedTime = 0;

	SOUNDMANAGER->play(L"WakuWaku7");

	return S_OK;
}
void introScene::release(void)
{
	SAFE_DELETE(_aniMain);

	IMAGEMANAGER->deleteImage(L"IntroBackground");
	IMAGEMANAGER->deleteImage(L"IntroMain");

	_introBackground = NULL;
	_introMain = NULL;
}
void introScene::update(void)
{

	if (_elapsedTime >= 1.0f / 30.0f)
	{
		_loopTime++;
		_elapsedTime = 0;
	}

	_elapsedTime += TIMEMANAGER->getElapsedTime();

	_aniMain->frameUpdate(TIMEMANAGER->getElapsedTime());

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SCENEMANAGER->changeScene(L"SelectScene");
		SOUNDMANAGER->stop(L"WakuWaku7");
		SOUNDMANAGER->play(L"SelectCharacter");
	}
}
void introScene::render(void)
{
	_introBackground->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), _loopTime, _loopTime, false, 255);
	_introMain->aniRender(getMemDC(), WINSIZEX / 2 - _introMain->getFrameWidth() / 2 + 20, 80, _aniMain);
}