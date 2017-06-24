#pragma once
#include "singletonBase.h"
#include "image.h"
#include <map>

class imageManager : public singletonBase<imageManager>
{
private:
	typedef map<wstring, image*> mapImageList;
	typedef map<wstring, image*>::iterator mapImageIterator;

private:
	mapImageList _mImageList;

public:
	HRESULT init();
	void release();
	//==========�̹��� �߰�==========//

	//�� �̹���
	image* addImage(wstring strKey, int width, int height);

	//���� �̹���
	image* addImage(wstring strKey, const wchar_t* fileName, 
		int width, int height, 
		bool alpha, bool trans, COLORREF transColor);
	image* addImage(wstring strKey, const wchar_t* fileName, 
		float x, float y, 
		int width, int height, 
		bool alpha, bool trans, COLORREF transColor);


	//==========������ �̹��� �߰�==========//
	image* addFrameImage(wstring strKey, const wchar_t* fileName, 
		int width, int height, 
		int frameX, int frameY, 
		bool alpha, bool trans, COLORREF transColor);
	image* addFrameImage(wstring strKey, const wchar_t* fileName, 
		float x, float y, 
		int width, int height, 
		int frameX, int frameY, 
		bool alpha, bool trans, COLORREF transColor);

	//Ű ������ �̹��� ã�ƿ��� �Լ�
	image* findImage(wstring strKey);

	//�̹��� �����ִ� �Լ�
	BOOL deleteImage(wstring strKey);

	//�̹��� ��ü������ �����ִ� �Լ�
	BOOL deleteAll(void);

	//void render(string strKey, HDC hdc);
	void render(wstring strKey, HDC hdc, int destX, int destY);
	void render(wstring strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);


	imageManager();
	~imageManager();
};

