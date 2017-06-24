#include "stdafx.h"
#include "gameNode.h"

gameNode::gameNode(){}
gameNode::~gameNode(){}

HRESULT gameNode::init(void)
{
	_hdc = GetDC(_hWnd);
	_managerInit = false;

	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if (_managerInit)
	{
		TIMEMANAGER->init();
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		EFFECTMANAGER->init();
		SOUNDMANAGER->init();
		SCENEMANAGER->init();
		TXTDATA->init();
	}

	return S_OK;
}

void gameNode::release(void)
{
	if (_managerInit)
	{
		
		IMAGEMANAGER->deleteImage(L"backBuffer");
		SCENEMANAGER->release();

		SOUNDMANAGER->release();
		EFFECTMANAGER->release();
		TIMEMANAGER->release();
		
		TXTDATA->releaseSingleton();
		SOUNDMANAGER->releaseSingleton();
		EFFECTMANAGER->releaseSingleton();
		IMAGEMANAGER->releaseSingleton();
		KEYMANAGER->releaseSingleton();	
		TIMEMANAGER->releaseSingleton();
		SCENEMANAGER->releaseSingleton();

	}

	ReleaseDC(_hWnd, _hdc);
}

void gameNode::update(void)
{
	SOUNDMANAGER->update();
}

void gameNode::render(void)
{

}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (iMessage)
	{
		case WM_MOUSEMOVE:
		{
			_ptMouse.x = static_cast<float>LOWORD(lParam);
			_ptMouse.y = static_cast<float>HIWORD(lParam);
		}
		break;

		case WM_KEYDOWN:
		{
			switch (wParam)
			{
				case VK_ESCAPE:
				{
					PostMessage(hWnd, WM_DESTROY, 0, 0);
				}
				break;

				case VK_F10:
				{
					this->init();
				}
			}
		}
		break;

		case WM_DESTROY:
		{
			PostQuitMessage(0);
		}
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}