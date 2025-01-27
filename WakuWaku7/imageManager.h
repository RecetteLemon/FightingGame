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
	//==========이미지 추가==========//

	//빈 이미지
	image* addImage(wstring strKey, int width, int height);

	//파일 이미지
	image* addImage(wstring strKey, const wchar_t* fileName, 
		int width, int height, 
		bool alpha, bool trans, COLORREF transColor);
	image* addImage(wstring strKey, const wchar_t* fileName, 
		float x, float y, 
		int width, int height, 
		bool alpha, bool trans, COLORREF transColor);


	//==========프레임 이미지 추가==========//
	image* addFrameImage(wstring strKey, const wchar_t* fileName, 
		int width, int height, 
		int frameX, int frameY, 
		bool alpha, bool trans, COLORREF transColor);
	image* addFrameImage(wstring strKey, const wchar_t* fileName, 
		float x, float y, 
		int width, int height, 
		int frameX, int frameY, 
		bool alpha, bool trans, COLORREF transColor);

	//키 값으로 이미지 찾아오는 함수
	image* findImage(wstring strKey);

	//이미지 지워주는 함수
	BOOL deleteImage(wstring strKey);

	//이미지 전체적으로 지워주는 함수
	BOOL deleteAll(void);

	//void render(string strKey, HDC hdc);
	void render(wstring strKey, HDC hdc, int destX, int destY);
	void render(wstring strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);


	imageManager();
	~imageManager();
};

