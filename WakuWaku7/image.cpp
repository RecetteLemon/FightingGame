#include "stdafx.h"
#include "image.h"

#pragma comment(lib, "msimg32.lib")

image::image()
	: _imageInfo(NULL),
	_fileName(NULL),
	_trans(false),
	_transColor(RGB(0, 0, 0))
{}


image::~image() {}

//빈 비트맵 이미지 등록
HRESULT image::init(int width, int height)
{
	//이미지 정보가 남아있다면 날려준다
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	//이미지 정보 생성
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	_fileName = NULL;

	_trans = FALSE;
	_transColor = RGB(0, 0, 0);

	if (_imageInfo->hBit == 0)
	{
		release();

		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

//파일로 이미지 등록
//====================AlphaBlend_init========================================================

HRESULT image::init(const wchar_t* fileName, int width, int height,
	bool alpha, BOOL trans, COLORREF transColor)
{
	if (fileName == NULL) return E_FAIL;
	HDC hdc = GetDC(_hWnd);

	if (_imageInfo != NULL) release();

	_imageInfo = new IMAGE_INFO;
	_imageInfo->resID = 0;
	_imageInfo->width = width;
	_imageInfo->height = height;

	if (alpha)
	{
		_imageInfo->loadType = LOAD_EMPTY;
		_imageInfo->hMemDC = CreateCompatibleDC(hdc);
		_imageInfo->blendHMemDC = CreateCompatibleDC(hdc);
		_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
		_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
		_imageInfo->blendHBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
		_imageInfo->blendHOBit = (HBITMAP)SelectObject(_imageInfo->blendHMemDC, _imageInfo->blendHBit);

		_blendFunc.BlendFlags = 0;
		_blendFunc.AlphaFormat = 0;
		_blendFunc.BlendOp = AC_SRC_OVER;
	}
	else
	{
		_imageInfo->loadType = LOAD_FILE;
		_imageInfo->hMemDC = CreateCompatibleDC(hdc);
		_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
		_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	}

	int len = wcslen(fileName);

	_fileName = new wchar_t[len + 1];
	wcscpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	if (_imageInfo->hBit == 0)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const wchar_t* fileName, float x, float y, int width, int height,
	bool alpha, BOOL trans, COLORREF transColor)
{
	if (fileName == NULL) return E_FAIL;
	HDC hdc = GetDC(_hWnd);

	if (_imageInfo != NULL) release();

	_imageInfo = new IMAGE_INFO;
	_imageInfo->resID = 0;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->x = x;
	_imageInfo->y = y;

	if (alpha)
	{
		_imageInfo->loadType = LOAD_EMPTY;
		_imageInfo->hMemDC = CreateCompatibleDC(hdc);
		_imageInfo->blendHMemDC = CreateCompatibleDC(hdc);
		_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
		_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
		_imageInfo->blendHBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
		_imageInfo->blendHOBit = (HBITMAP)SelectObject(_imageInfo->blendHMemDC, _imageInfo->blendHBit);

		_blendFunc.BlendFlags = 0;
		_blendFunc.AlphaFormat = 0;
		_blendFunc.BlendOp = AC_SRC_OVER;
	}
	else
	{
		_imageInfo->loadType = LOAD_FILE;
		_imageInfo->hMemDC = CreateCompatibleDC(hdc);
		_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
		_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	}

	int len = wcslen(fileName);

	_fileName = new wchar_t[len + 1];
	wcscpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	if (_imageInfo->hBit == 0)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}


//===============================alphaBlend_frame_init=========================================
HRESULT image::init(const wchar_t* fileName, int width, int height,
	int frameX, int frameY, bool alpha, BOOL trans, COLORREF transColor)
{
	if (fileName == NULL) return E_FAIL;
	HDC hdc = GetDC(_hWnd);
	if (_imageInfo != NULL) release();
	_imageInfo = new IMAGE_INFO;
	_imageInfo->resID = 0;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;

	if (alpha)
	{
		_imageInfo->loadType = LOAD_EMPTY;
		_imageInfo->hMemDC = CreateCompatibleDC(hdc);
		_imageInfo->blendHMemDC = CreateCompatibleDC(hdc);
		_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
		_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
		_imageInfo->blendHBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
		_imageInfo->blendHOBit = (HBITMAP)SelectObject(_imageInfo->blendHMemDC, _imageInfo->blendHBit);

		_blendFunc.BlendFlags = 0;
		_blendFunc.AlphaFormat = 0;
		_blendFunc.BlendOp = AC_SRC_OVER;
	}
	else
	{
		_imageInfo->loadType = LOAD_FILE;
		_imageInfo->hMemDC = CreateCompatibleDC(hdc);
		_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
		_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	}

	int len = wcslen(fileName);

	_fileName = new wchar_t[len + 1];
	wcscpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	if (_imageInfo->hBit == 0)
	{
		release();

		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}



HRESULT image::init(const wchar_t* fileName, 
	float x, float y, 
	int width, int height,
	int frameX, int frameY, 
	bool alpha, BOOL trans, COLORREF transColor)
{
	if (fileName == NULL) return E_FAIL;
	HDC hdc = GetDC(_hWnd);
	if (_imageInfo != NULL) release();
	_imageInfo = new IMAGE_INFO;
	_imageInfo->resID = 0;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->x = x - (width / 2);
	_imageInfo->y = y - (height / 2);
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;

	if (alpha)
	{
		_imageInfo->loadType = LOAD_EMPTY;
		_imageInfo->hMemDC = CreateCompatibleDC(hdc);
		_imageInfo->blendHMemDC = CreateCompatibleDC(hdc);
		_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
		_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
		_imageInfo->blendHBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
		_imageInfo->blendHOBit = (HBITMAP)SelectObject(_imageInfo->blendHMemDC, _imageInfo->blendHBit);

		_blendFunc.BlendFlags = 0;
		_blendFunc.AlphaFormat = 0;
		_blendFunc.BlendOp = AC_SRC_OVER;
	}
	else
	{
		_imageInfo->loadType = LOAD_FILE;
		_imageInfo->hMemDC = CreateCompatibleDC(hdc);
		_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
		_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	}

	int len = wcslen(fileName);

	_fileName = new wchar_t[len + 1];
	wcscpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	if (_imageInfo->hBit == NULL)
	{
		release();

		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}



//=============================================================================================

void image::release(void)
{
	if (_imageInfo)
	{
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
		SelectObject(_imageInfo->blendHMemDC, _imageInfo->blendHOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteObject(_imageInfo->blendHBit);
		DeleteDC(_imageInfo->hMemDC);
		DeleteDC(_imageInfo->blendHMemDC);


		safeDelete(_fileName);
		safeDelete(_imageInfo);
		

		_trans = false;
		_transColor = RGB(0, 0, 0);
	}

	
}

void image::setTransColor(BOOL trans, COLORREF transColor)
{
	_trans = trans;
	_transColor = transColor;
}


void image::render(HDC hdc)
{
	if (_trans)
	{
		//특정 칼라 날려주는 함수
		GdiTransparentBlt(hdc,		//복사될 장소의 DC
			_imageInfo->x,			//복사될 좌표 시작점X(left)
			_imageInfo->y,			//복사될 좌표 시작점Y(top)
			_imageInfo->width,		//복사될 이미지 가로크기
			_imageInfo->height,		//복사될 이미지 세로크기
			_imageInfo->hMemDC,		//복사 대상 DC
			0, 0,					//복사될 시작지점
			_imageInfo->width,		//복사될 가로크기
			_imageInfo->height,		//복사될 세로크기
			_transColor);			//날려줄 칼라
	}
	else
	{
		BitBlt(hdc, _imageInfo->x, _imageInfo->y,
			_imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

//					뿌릴곳 X     뿌릴곳 Y
void image::render(HDC hdc, int destX, int destY)
{
	if (_trans)
	{
		//특정 칼라 날려주는 함수
		GdiTransparentBlt(hdc,		//복사될 장소의 DC
			destX,					//복사될 좌표 시작점X(left)
			destY,					//복사될 좌표 시작점Y(top)
			_imageInfo->width,		//복사될 이미지 가로크기
			_imageInfo->height,		//복사될 이미지 세로크기
			_imageInfo->hMemDC,		//복사 대상 DC
			0, 0,					//복사될 시작지점
			_imageInfo->width,		//복사될 가로크기
			_imageInfo->height,		//복사될 세로크기
			_transColor);			//날려줄 칼라
	}
	else
	{
		BitBlt(hdc, destX, destY,
			_imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}


}

void image::render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	if (_trans)
	{
		//특정 칼라 날려주는 함수
		GdiTransparentBlt(hdc,		//복사될 장소의 DC
			destX,					//복사될 좌표 시작점X(left)
			destY,					//복사될 좌표 시작점Y(top)
			sourWidth,				//복사될 이미지 가로크기
			sourHeight,				//복사될 이미지 세로크기
			_imageInfo->hMemDC,		//복사 대상 DC
			sourX, sourY,			//복사될 시작지점
			sourWidth,				//복사될 가로크기
			sourHeight,				//복사될 세로크기
			_transColor);			//날려줄 칼라
	}
	else
	{
		BitBlt(hdc, destX, destY,
			sourWidth, sourHeight,
			_imageInfo->hMemDC, sourX, sourY, SRCCOPY);
	}
}

void image::frameRender(HDC hdc, int destX, int destY)
{
	if (_trans)
	{
		//특정 칼라 날려주는 함수
		GdiTransparentBlt(hdc,			//복사될 장소의 DC
			destX,						//복사될 좌표 시작점X(left)
			destY,						//복사될 좌표 시작점Y(top)
			_imageInfo->frameWidth,		//복사될 이미지 가로크기
			_imageInfo->frameHeight,	//복사될 이미지 세로크기
			_imageInfo->hMemDC,			//복사 대상 DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,		//복사될 가로크기
			_imageInfo->frameHeight,	//복사될 세로크기
			_transColor);				//날려줄 칼라
	}
	else
	{
		BitBlt(hdc, destX, destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			SRCCOPY);
	}
}

void image::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;

	if (_trans)
	{
		//특정 칼라 날려주는 함수
		GdiTransparentBlt(hdc,			//복사될 장소의 DC
			destX,						//복사될 좌표 시작점X(left)
			destY,						//복사될 좌표 시작점Y(top)
			_imageInfo->frameWidth,		//복사될 이미지 가로크기
			_imageInfo->frameHeight,	//복사될 이미지 세로크기
			_imageInfo->hMemDC,			//복사 대상 DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,		//복사될 가로크기
			_imageInfo->frameHeight,	//복사될 세로크기
			_transColor);				//날려줄 칼라
	}
	else
	{
		BitBlt(hdc, destX, destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			SRCCOPY);
	}
}



//====================alphaRendler=======================
void image::alphaRender(HDC hdc, BYTE alpha)
{
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)
	{
		BitBlt(_imageInfo->blendHMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, (int)_imageInfo->x, (int)_imageInfo->y, SRCCOPY);

		GdiTransparentBlt(_imageInfo->blendHMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		AlphaBlend(hdc, (int)_imageInfo->x, (int)_imageInfo->y, _imageInfo->width, _imageInfo->height,
			_imageInfo->blendHMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, (int)_imageInfo->x, (int)_imageInfo->y, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}

void image::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)
	{
		BitBlt(_imageInfo->blendHMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_imageInfo->blendHMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_imageInfo->blendHMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}

void image::alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)
	{
		BitBlt(_imageInfo->blendHMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_imageInfo->blendHMemDC, 0, 0, sourWidth, sourHeight,
			_imageInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, _transColor);

		AlphaBlend(hdc, destX, destY, sourWidth, sourHeight,
			_imageInfo->blendHMemDC, 0, 0, sourWidth, sourHeight, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, destX, destY, sourWidth, sourHeight,
			_imageInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, _blendFunc);
	}
}

//====================================================================================================
//===========================================alphaFrameRender=========================================
void image::alphaFrameRender(HDC hdc, int destX, int destY, BYTE alpha)
{
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)
	{
		BitBlt(_imageInfo->blendHMemDC, 0, 0,
			_imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_imageInfo->blendHMemDC, 0, 0,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			(int)_imageInfo->currentFrameX * _imageInfo->frameWidth,
			(int)_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth, _imageInfo->frameHeight, _transColor);

		AlphaBlend(hdc, destX, destY,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->blendHMemDC,
			0, 0,
			_imageInfo->frameWidth, _imageInfo->frameHeight, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, destX, destY,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			(int)_imageInfo->currentFrameX * _imageInfo->frameWidth,
			(int)_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth, _imageInfo->frameHeight, _blendFunc);
	}
}

void image::alphaFrameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha)
{
	_blendFunc.SourceConstantAlpha = alpha;

	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;

	if (_trans)
	{
		BitBlt(_imageInfo->blendHMemDC, 0, 0,
			_imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_imageInfo->blendHMemDC, 0, 0,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			(int)_imageInfo->currentFrameX * _imageInfo->frameWidth,
			(int)_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth, _imageInfo->frameHeight, _transColor);

		AlphaBlend(hdc, destX, destY,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->blendHMemDC,
			0, 0,
			_imageInfo->frameWidth, _imageInfo->frameHeight, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, destX, destY,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			(int)_imageInfo->currentFrameX * _imageInfo->frameWidth,
			(int)_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth, _imageInfo->frameHeight, _blendFunc);
	}
}

//이미지 1장으로 하는 루프렌더
void image::loopRender(HDC hdc, const LPRECT drawArea, int offSetX, int offSetY, bool alpha, BYTE alphaPoint)
{
	//  -200					600				     -200   % 600
	if (offSetX < 0) offSetX = _imageInfo->width + (offSetX % _imageInfo->width);
	if (offSetY < 0) offSetY = _imageInfo->height + (offSetY % _imageInfo->height);

	//오프셋 영역 받아올 변수
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	//그려주는 영역
	RECT rcDest;

	//화면에 그려주는 영역 지정
	int drawAreaX = drawArea->left;						//Left
	int drawAreaY = drawArea->top;						//Top
	int drawAreaW = drawArea->right - drawArea->left;	//Width
	int drawAreaH = drawArea->bottom - drawArea->top;	//Height

														//Y Axis
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		rcSour.top = (y + offSetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;

		sourHeight = rcSour.bottom - rcSour.top;

		//그려지는 영역의 높이값보다 ?? 크면
		if (y + sourHeight > drawAreaH)
		{
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		//뿌려주는 영역 
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		//X Axis
		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			rcSour.left = (x + offSetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;

			sourWidth = rcSour.right - rcSour.left;

			if (x + sourWidth > drawAreaW)
			{
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			if (!alpha)
			{
				render(hdc, rcDest.left,				//뿌릴 X
					rcDest.top,					//뿌릴 Y
					rcSour.left, rcSour.top,	//뿌려올 X, Y
					rcSour.right - rcSour.left,	//뿌려올 이미지 가로크기
					rcSour.bottom - rcSour.top);//뿌려올 이미지 세로크기
			}
			else
			{
				alphaRender(hdc, rcDest.left,				//뿌릴 X
					rcDest.top,					//뿌릴 Y
					rcSour.left, rcSour.top,	//뿌려올 X, Y
					rcSour.right - rcSour.left,	//뿌려올 이미지 가로크기
					rcSour.bottom - rcSour.top, alphaPoint);//뿌려올 이미지 세로크기
			}
		}
	}
}

void image::aniRender(HDC hdc, int destX, int destY, animation* ani)
{
	this->render(hdc, destX, destY, ani->getFramePos().x, ani->getFramePos().y, ani->getFrameWidth(), ani->getFrameHeight());
}

void image::aniAlphaRender(HDC hdc, int destX, int destY, animation* ani, BYTE alpha)
{
	this->alphaRender(hdc, destX, destY, ani->getFramePos().x, ani->getFramePos().y, ani->getFrameWidth(), ani->getFrameHeight(), alpha);
}