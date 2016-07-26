#pragma once
#include "IPartWndProc.h"

class DrawWndProc : public IPartWndProc
{
public:
	DrawWndProc(void);
	~DrawWndProc(void);
	LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn);
};

