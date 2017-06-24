#pragma once
#include "gameNode.h"

class progressBar : public gameNode
{
private:
	RECT _rcGauge, _rcCover;
	POINT _gaugePos, _coverPos;
	float _width, _maxWidth;
	unsigned short _alpha;

	image* _gaugeImg;
	image* _coverImg;

public:
	HRESULT init(
		int gaugeX, int gaugeY, int gaugeWidth, int gaugeHeight,
		int coverX, int coverY, int coverWidth, int coverHeight,
		const wchar_t* gaugeFile, const wchar_t* coverFile,
		bool alpha, bool trans);

	void release();
	void update();
	void render(bool alpha, unsigned short alphaPoint);

	void setGauge(float currentGauge, float maxGauge);

	inline void setGaugeX(int x) { _gaugePos.x = x; }
	inline void setGaugeY(int y) { _gaugePos.y = y; }

	inline void setCoverX(int x) { _coverPos.x = x; }
	inline void setCoverY(int y) { _coverPos.y = y; }

	progressBar();
	~progressBar();
};

