#pragma once
#include "gameNode.h"

class selectScene : public gameNode
{
private:

	enum ELAPSED_TIME
	{
		START_SELECT, VIB, ELAPSED_TIME_END
	};

	image* _selectBackground;
	image* _selectChara;
	image* _vs;

	float	_elapsedTime[ELAPSED_TIME_END];
	int		_loopTime;
	int		_vibCount;

	bool	_startSelect;
	bool	_vib;

public:

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void imageVib();

	selectScene();
	~selectScene();
};

