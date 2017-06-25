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
	_pM = new playerManager;
	_pM->init();
	return S_OK;
}

void battleAreaScene::release(void)
{

}

void battleAreaScene::update(void)
{
	_pM->update();
}

void battleAreaScene::render(void)
{
	_pM->render();
}
