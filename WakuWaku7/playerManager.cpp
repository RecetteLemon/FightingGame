#include "stdafx.h"
#include "playerManager.h"
#include "may.h"
#include "dummy.h"


playerManager::playerManager()
{
}


playerManager::~playerManager()
{
}


HRESULT playerManager::init(void)	  
{
	_may = new may;
	_may->init();

	_dummy = new dummy;
	_dummy->init();

	return S_OK;
}

void playerManager::release(void)	  
{

}
void playerManager::update(void)	  
{
	_may->update();
	_dummy->update();
}

void playerManager::render(void)	  
{
	_may->render();
	_dummy->render();
}