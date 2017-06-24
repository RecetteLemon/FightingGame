// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"


#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>
#include <iostream>


// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <tchar.h>



// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

#define _USE_MATH_DEFINES
#include <math.h>

#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "imageManager.h"
#include "timeManager.h"
#include "effectManager.h"
#include "soundManager.h"
#include "sceneManager.h"
#include "utils.h"
#include "txtData.h"

using namespace std;
using namespace OMEGA_UTIL;


//==================================
// ## 2017.04.05 ## �����ι� ##
//==================================

#define WINNAME (LPTSTR)(TEXT("WakuWaku7"))
#define WINSTARTX 50			//������ â �������� X��ǥ
#define WINSTARTY 50			//������ â �������� Y��ǥ
#define WINSIZEX  800			//������ â ����ũ��
#define WINSIZEY  600			//������ â ����ũ��
#define WINSTYLE WS_CAPTION | WS_SYSMENU

//�����Լ� ������
#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define EFFECTMANAGER effectManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define TXTDATA txtData::getSingleton()


//==================================
// ## 2017.04.05 ## ��ũ�� �Լ� ##
//==================================

#define SAFE_DELETE(p)	{if(p) {delete(p); (p) = NULL;}}
#define SAFE_RELEASE(p) {if(p) {(p)->release(); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p) {delete[] (p); (p) = NULL;}}

//==================================
// ## 2017.04.10 ## ���� ���� ##
//==================================

extern HWND _hWnd;
extern HINSTANCE _hInstance;
extern POINT _ptMouse;

//===============================================�޸� ���� üũ============================

#ifndef _MEMORYLEAK_H_
#define _MEMORYLEAK_H_

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
static class MemoryMng
{
public:
	MemoryMng()
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		//_CrtSetBreakAlloc(60861);
	}
	~MemoryMng()
	{
		_ASSERTE(_CrtCheckMemory());
	}


} MemoryLeak;
#endif      // _DEBUG
#endif      // _MEMORYLEAK_H_


//======================================================================================


// template safe delete 
template <typename T>
inline extern void safeDelete(T* &p)
{
	if (p == NULL) return;

	delete p;
	p = static_cast<T*>(NULL);
}

template <typename T>
inline extern void safeDeleteArray(T* &p)
{
	if (p == NULL) return;

	delete[] p;
	p = static_cast<T*>(NULL);
}

