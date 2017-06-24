#pragma once
#include "player.h"

class may : public player
{
public:

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	//===========================================================커맨드 관리 함수
	
	//===========================================================

	may();
	~may();
};

