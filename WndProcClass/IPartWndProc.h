#pragma once
#include <windows.h>
#include <tchar.h>
#include <string>

class IPartWndProc
{
public:
	virtual LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn) = 0;
};

