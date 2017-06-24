#include "stdafx.h"
#include "utils.h"

namespace OMEGA_UTIL
{
	//�Ÿ�
	float getDistance(float startX, float startY, float endX, float endY)
	{
		float x = endX - startX;
		float y = endY - startY;

		return sqrtf(x * x + y * y);
	}

	//����
	float getAngle(float x1, float y1, float x2, float y2)
	{
		float x = x2 - x1;		//x�� ����
		float y = y2 - y1;		//y�� ����

								//�Ÿ��� �˾Ҵ�
		float distance = sqrtf((x * x) + (y * y));

		//cos�� ��ġ�� -> acosf
		float angle = acosf(x / distance);

		if (y2 > y1)
		{
			angle = PI * 2 - angle;
			if (angle >= PI * 2) angle -= PI * 2;
		}

		return angle;
	}

	float ptpDistance(float x, float y, float a, float b)
	{
		float dx = a - x;
		float dy = b - y;

		return (dx * dx + dy * dy);
	}

	float deductionRadian(float x, float y, float a, float b)
	{

		float dx = a - x;
		float dy = b - y;

		return atan2f(-dy, dx);
	}
}

