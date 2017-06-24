#pragma once
#include "singletonBase.h"
#include <vector>
#include <string>

class txtData : public singletonBase<txtData>
{
public:
	HRESULT init();
	void release();

	//Save
	void txtSave(const wchar_t* saveFileName, vector<wstring> vStr);
	wchar_t* vectorArrayCombine(vector<wstring> vArray);

	//Load
	vector<wstring> txtLoad(const wchar_t* loadFileName);
	vector<wstring> wcharArraySeparation(wchar_t wcharArray[]);

	txtData();
	~txtData();
};

