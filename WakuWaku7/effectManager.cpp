#include "stdafx.h"
#include "effectManager.h"
#include "effect.h"


effectManager::effectManager()
{
}


effectManager::~effectManager()
{
}

HRESULT effectManager::init()
{

	return S_OK;
}

void effectManager::release()
{
	iterTotalEffect vIter;
	iterEffects mIter;

	for (vIter = _vTotalEffect.begin(); vIter != _vTotalEffect.end(); ++vIter)
	{
		mIter = vIter->begin();

		for (; mIter != vIter->end();)
		{
			if (mIter->second.size() != 0)
			{
				iterEffect viArr = mIter->second.begin();
				for (; viArr != mIter->second.end(); )
				{
					(*viArr)->release();
					SAFE_DELETE(*viArr);
					viArr = mIter->second.erase(viArr);
				}
			}
			else
			{
				++mIter;
			}
		}
	}
}

void effectManager::update()
{
	iterTotalEffect vIter;
	iterEffects mIter;

	for (vIter = _vTotalEffect.begin(); vIter != _vTotalEffect.end(); ++vIter)
	{
		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{
			iterEffect viArr;
			for (viArr = mIter->second.begin(); viArr != mIter->second.end(); ++viArr)
			{
				(*viArr)->update();
			}
		}
	}
}

void effectManager::render(BOOL alpha, BYTE alphaPoint)
{
	iterTotalEffect vIter;
	iterEffects mIter;

	for (vIter = _vTotalEffect.begin(); vIter != _vTotalEffect.end(); ++vIter)
	{
		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{
			iterEffect viArr;
			for (viArr = mIter->second.begin(); viArr != mIter->second.end(); ++viArr)
			{
				(*viArr)->render(alpha, alphaPoint);
			}
		}
	}
}

void effectManager::addEffect(
	wstring effectName, const wchar_t* imageName,
	int imageWidth, int imageHeight, int effectWidth, int effectHeight,
	int fps, float elapsedTime, int buffer, BOOL alpha)
{
	image* img;
	arrEffect vEffectBuffer;
	arrEffects mArrEffect;

	if (IMAGEMANAGER->findImage(imageName))
	{
		img = IMAGEMANAGER->findImage(imageName);
	}
	else
	{
		img = IMAGEMANAGER->addFrameImage(
			effectName, imageName, imageWidth, imageHeight, imageWidth / effectWidth, imageHeight / effectHeight,
			alpha, true, RGB(255, 0, 255));
	}

	for (int i = 0; i < buffer; i++)
	{
		vEffectBuffer.push_back(new effect);
		vEffectBuffer[i]->init(img, effectWidth, effectHeight, fps, elapsedTime);
	}

	mArrEffect.insert(pair<wstring, arrEffect>(effectName, vEffectBuffer));

	_vTotalEffect.push_back(mArrEffect);
}

void effectManager::play(wstring effectName, int x, int y)
{
	iterTotalEffect vIter;
	iterEffects mIter;

	for (vIter = _vTotalEffect.begin(); vIter != _vTotalEffect.end(); ++vIter)
	{
		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{
			if (!(mIter->first == effectName)) break;

			iterEffect viArr;
			for (viArr = mIter->second.begin(); viArr != mIter->second.end(); ++viArr)
			{
				if ((*viArr)->getIsRunning()) continue;

				(*viArr)->startEffect(x, y);
				return;
			}
		}
	}
}