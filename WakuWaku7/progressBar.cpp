#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{
}


HRESULT progressBar::init(
	int gaugeX, int gaugeY, int gaugeWidth, int gaugeHeight,
	int coverX, int coverY, int coverWidth, int coverHeight,
	const wchar_t* gaugeFile, const wchar_t* coverFile,
	bool alpha, bool trans)
{
	_gaugePos.x = gaugeX;
	_gaugePos.y = gaugeY;

	_coverPos.x = coverX;
	_coverPos.y = gaugeY;

	_rcGauge = RectMake(gaugeX, gaugeY, gaugeWidth, gaugeHeight);
	_rcCover = RectMake(coverX, coverY, coverWidth, coverHeight);

	_gaugeImg = new image;
	_gaugeImg->init(gaugeFile, gaugeWidth, gaugeHeight, alpha, trans, RGB(255, 0, 255));

	_coverImg = new image;
	_coverImg->init(coverFile, coverWidth, coverHeight, alpha, trans, RGB(255, 0, 255));

	_width = _maxWidth = _rcGauge.right - _rcGauge.left;

	return S_OK;
}


void progressBar::release()
{
	SAFE_RELEASE(_gaugeImg);
	SAFE_RELEASE(_coverImg);

	SAFE_DELETE(_gaugeImg);
	SAFE_DELETE(_coverImg);
}

void progressBar::update()
{
	_rcGauge = RectMake(_gaugePos.x, _gaugePos.y, _gaugeImg->getWidth(), _gaugeImg->getHeight());
	_rcCover = RectMake(_coverPos.x, _coverPos.y, _coverImg->getWidth(), _coverImg->getHeight());
}

void progressBar::render(bool alpha, unsigned short alphaPoint)
{
	if (alpha)
	{
		_gaugeImg->alphaRender(getMemDC(), _rcGauge.left, _rcGauge.top, 0, 0, _width, _gaugeImg->getHeight(), alphaPoint);
		_coverImg->alphaRender(getMemDC(), _rcCover.left, _rcCover.top, 0, 0, _coverImg->getWidth(), _coverImg->getHeight(), alphaPoint);
	}
	else
	{
		_gaugeImg->render(getMemDC(), _rcGauge.left, _rcGauge.top, 0, 0, _width, _gaugeImg->getHeight());
		_coverImg->render(getMemDC(), _rcCover.left, _rcCover.top, 0, 0, _coverImg->getWidth(), _coverImg->getHeight());
	}
}

void progressBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * _maxWidth;
}
