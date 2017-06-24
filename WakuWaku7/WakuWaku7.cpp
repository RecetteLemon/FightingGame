#include "stdafx.h"
#include "WakuWaku7.h"

WakuWaku7::WakuWaku7() {}
WakuWaku7::~WakuWaku7() {}


HRESULT WakuWaku7::init(void)
{
	gameNode::init(true);

	SOUNDMANAGER->addSound(L"SelectCharacter", L"Sound/SelectCharacter.mp3", true, false);
	SOUNDMANAGER->addSound(L"WakuWaku7", L"Sound/WakuWaku7.mp3", false, false);
	

	SCENEMANAGER->addScene(L"IntroScene", new introScene);
	SCENEMANAGER->addScene(L"SelectScene", new selectScene);


	SCENEMANAGER->changeScene(L"IntroScene");
	return S_OK;
}

void WakuWaku7::release(void)
{
	
	
	gameNode::release();
}

void WakuWaku7::update(void)
{
	gameNode::update();
	
	SCENEMANAGER->update();
	
}


void WakuWaku7::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=============================================================================

	SCENEMANAGER->render();

	//=============================================================================
	TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}