#pragma once
#include "player.h"

class may : public player
{
public:

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	//===========================================================Ŀ�ǵ� ���� �Լ�
	
	//===========================================================

	may();
	~may();
};

