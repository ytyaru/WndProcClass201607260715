#include "InitializeWndProc.h"

InitializeWndProc::InitializeWndProc(void)
{
}

InitializeWndProc::~InitializeWndProc(void)
{
}

LRESULT CALLBACK InitializeWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
		case WM_CREATE:
			TCHAR szTitle[1024];
			memset(szTitle, '\0', 1024);
			GetWindowText(hWnd, szTitle, 1024);
			_tcscat_s(szTitle, 1024, _T("InitializeWndProc::PartWndProc�ɂĂ��̕������ǉ����܂����B�����L�[���������Ă݂ĉ������B"));
			SetWindowText(hWnd, szTitle);
			break;
		default:
			break;
			//return (DefWindowProc(hWnd, uMsg, wParam, lParam));
	}
	return (0L);
}