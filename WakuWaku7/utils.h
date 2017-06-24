#pragma once
//���� ���� ������� ���� cMath
//#include <cmath>

#define DEG_TO_RAD 0.017453f //1���� ���� ���� ��
#define PI 3.141592654f
#define PI2 PI * 2
#define FLAOT_EPSILON 0.001f //�Ǽ��� ���� ���� ����

namespace OMEGA_UTIL
{
	//�Ÿ�
	float getDistance(float startX, float startY, float endX, float endY);

	//����
	float getAngle(float x1, float y1, float x2, float y2);

	float ptpDistance(float x, float y, float a, float b);
	float deductionRadian(float x, float y, float a, float b);
}


