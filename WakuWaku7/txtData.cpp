#include "stdafx.h"
#include "txtData.h"

txtData::txtData(){}
txtData::~txtData(){}

HRESULT txtData::init()
{
	return S_OK;
}

void txtData::release()
{

}

//Save

void txtData::txtSave(const wchar_t* saveFileName, vector<wstring> vStr)
{
	HANDLE file;

	wchar_t str[128];
	DWORD write;

	wcsncat_s(str, 128, vectorArrayCombine(vStr), 126);
	file = CreateFile(saveFileName, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, 128, &write, NULL);

	CloseHandle(file);
}


wchar_t* txtData::vectorArrayCombine(vector<wstring> vArray)
{
	wchar_t str[128];

	ZeroMemory(str, sizeof(str));

	for (int i = 0; i < vArray.size(); i++)
	{
		wcsncat_s(str, 128, vArray[i].c_str(), 126);
		if (i + 1 < vArray.size())	wcscat(str, L",");
	}

	return str;
}


//Load

vector<wstring> txtData::txtData::txtLoad(const wchar_t* loadFileName)
{
	HANDLE file;
	
	wchar_t str[128];
	DWORD read;

	file = CreateFile(loadFileName, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, 128, &read, NULL);

	CloseHandle(file);

	return wcharArraySeparation(str);
}

vector<wstring> txtData::wcharArraySeparation(wchar_t wcharArray[])
{
	vector<wstring> vArray;

	wchar_t* temp;
	wchar_t* separator = L",";
	wchar_t* token;

	token = wcstok_s(wcharArray, separator, &temp);
	vArray.push_back(token);

	while (NULL != (token = wcstok_s(NULL, separator, &temp)))
	{
		vArray.push_back(token);
	}

	return vArray;
}