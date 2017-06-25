#include "stdafx.h"
#include "keyAniManager.h"
#include "image.h"
#include "animation.h"


keyAniManager::keyAniManager()
{
}


keyAniManager::~keyAniManager()
{

}

HRESULT keyAniManager::init()
{
	return S_OK;
}

void keyAniManager::release()
{
	deleteAll();
}

void keyAniManager::update()
{
	iterAnimations iter = _mTotalAnimation.begin();

	for (iter; iter != _mTotalAnimation.end(); ++iter)
	{
		//�ִϸ��̼��� ��������� ������ ������� �ʴ´�
		if (!iter->second->isPlay()) continue;

		iter->second->frameUpdate(TIMEMANAGER->getElapsedTime() * 1.0f);
	}

}

void keyAniManager::render()
{

}


//����Ʈ �ִϸ��̼�
void keyAniManager::addDefaultFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int fps, bool reverse, bool loop)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<unsigned int, animation*>(animationKeyName, ani));

}

void keyAniManager::addDefaultFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop, (CALLBACK_FUNCTION)cbFunction);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<unsigned int, animation*>(animationKeyName, ani));
}

void keyAniManager::addDefaultFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction, void* obj)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop, (CALLBACK_FUNCTION_PARAMETER)cbFunction, obj);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<unsigned int, animation*>(animationKeyName, ani));
}


//�迭 �ִϸ��̼�
void keyAniManager::addArrayFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int* arr, int arrLen, int fps, bool loop)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(arr, arrLen, loop);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<unsigned int, animation*>(animationKeyName, ani));
}

void keyAniManager::addArrayFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(arr, arrLen, loop, CALLBACK_FUNCTION(cbFunction));
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<unsigned int, animation*>(animationKeyName, ani));
}

void keyAniManager::addArrayFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction, void* obj)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(arr, arrLen, loop, CALLBACK_FUNCTION_PARAMETER(cbFunction), obj);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<unsigned int, animation*>(animationKeyName, ani));
}


//���� �ִϸ��̼�
void keyAniManager::addCoordinateFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int start, int end, int fps, bool reverse, bool loop)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<unsigned int, animation*>(animationKeyName, ani));
}

void keyAniManager::addCoordinateFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop, CALLBACK_FUNCTION(cbFunction));
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<unsigned int, animation*>(animationKeyName, ani));
}

void keyAniManager::addCoordinateFrameAnimation(unsigned int animationKeyName, wchar_t* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction, void* obj)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop, CALLBACK_FUNCTION_PARAMETER(cbFunction), obj);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<unsigned int, animation*>(animationKeyName, ani));
}


void keyAniManager::start(unsigned int animationKeyName)
{
	iterAnimations iter = _mTotalAnimation.find(animationKeyName);
	iter->second->start();
}

void keyAniManager::stop(unsigned int animationKeyName)
{
	iterAnimations iter = _mTotalAnimation.find(animationKeyName);
	iter->second->stop();
}

void keyAniManager::pause(unsigned int animationKeyName)
{
	iterAnimations iter = _mTotalAnimation.find(animationKeyName);
	iter->second->pause();
}

void keyAniManager::resume(unsigned int animationKeyName)
{
	iterAnimations iter = _mTotalAnimation.find(animationKeyName);
	iter->second->resume();
}


animation* keyAniManager::findAnimation(unsigned int animationKeyName)
{
	iterAnimations iter = _mTotalAnimation.find(animationKeyName);

	if (iter != _mTotalAnimation.end())
	{
		return iter->second;
	}

	return NULL;
}


void keyAniManager::deleteAll()
{
	for (iterAnimations iter = _mTotalAnimation.begin(); iter != _mTotalAnimation.end();)
	{
		if (iter->second != NULL)
		{
			iter->second->release();
			SAFE_DELETE(iter->second);
			iter = _mTotalAnimation.erase(iter);
		}
		else ++iter;

	}

	_mTotalAnimation.clear();

}

