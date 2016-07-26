#include "KeyboardWndProc.h"

KeyboardWndProc::KeyboardWndProc(void)
{ 
}

KeyboardWndProc::~KeyboardWndProc(void)
{
}

LRESULT CALLBACK KeyboardWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
		case WM_KEYDOWN:
			MessageBox(hWnd, _T("KeyboardWndProc::PartWndProc"), _T("WM_KEYDOWN"), MB_OK);
			break;
		//case WM_DESTROY:
		//	PostQuitMessage(0);
		//	break;
		default:
			break;
			//return (DefWindowProc(hWnd, uMsg, wParam, lParam));
	}
	return (0L);
}
