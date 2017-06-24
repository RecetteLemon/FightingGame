#include "stdafx.h"
#include "imageManager.h"

imageManager::imageManager(){}
imageManager::~imageManager(){}

HRESULT imageManager::init(void) 
{ 
	return S_OK; 
}

void imageManager::release(void)
{ 
	//deleteAll();
}

image* imageManager::addImage(wstring strKey, int width, int height)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;

	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}


image* imageManager::addImage(wstring strKey, const wchar_t* fileName,
	int width, int height,
	bool alpha, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;

	if (FAILED(img->init(fileName, width, height, alpha, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}


image* imageManager::addImage(wstring strKey, const wchar_t* fileName,
	float x, float y,
	int width, int height,
	bool alpha, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;

	if (FAILED(img->init(fileName, x, y, width, height, alpha, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* imageManager::addFrameImage(wstring strKey, const wchar_t*
	fileName, int width, int height,
	int frameX, int frameY,
	bool alpha, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;

	if (FAILED(img->init(fileName, width, height, frameX, frameY, alpha, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}


image* imageManager::addFrameImage(wstring strKey, const wchar_t* fileName,
	float x, float y,
	int width, int height,
	int frameX, int frameY,
	bool alpha, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;

	if (FAILED(img->init(fileName, x, y, width, height, frameX, frameY, alpha, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}


image* imageManager::findImage(wstring strKey)
{
	mapImageIterator key = _mImageList.find(strKey);

	if (key != _mImageList.end())
	{
		return key->second;
	}

	return NULL;
}

BOOL imageManager::deleteImage(wstring strKey)
{
	mapImageIterator key = _mImageList.find(strKey);

	if (key != _mImageList.end())
	{
		key->second->release();
		SAFE_DELETE(key->second);
		_mImageList.erase(key);

		return true;
	}

	return false;
}

BOOL imageManager::deleteAll(void)
{
	mapImageIterator iterator = _mImageList.begin();

	for (; iterator != _mImageList.end();)
	{
		if (iterator->second != NULL)
		{
			SAFE_DELETE(iterator->second);
			iterator = _mImageList.erase(iterator);
		}
		else
		{
			++iterator;
		}
	}

	_mImageList.clear();

	return TRUE;
}


void imageManager::render(wstring strKey, HDC hdc, int destX, int destY)
{
	image* img = findImage(strKey);

	if (img) img->render(hdc, destX, destY);
}

void imageManager::render(wstring strKey, HDC hdc,
	int destX, int destY,
	int sourX, int sourY,
	int sourWidth, int sourHeight)
{
	image* img = findImage(strKey);

	if (img) img->render(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight);
}
