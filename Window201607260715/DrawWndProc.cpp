#include "DrawWndProc.h"

DrawWndProc::DrawWndProc(void)
{
}
DrawWndProc::~DrawWndProc(void)
{
}

LRESULT CALLBACK DrawWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
		case WM_PAINT:
		{
			HDC hdc;
			PAINTSTRUCT ps;

			hdc = BeginPaint(hWnd , &ps);

			SetBkColor(hdc , RGB(0xFF , 0 , 0));
			TextOut(hdc , 10 , 10 , _T("DrawWndProc::PartWndProc") , _tcslen( _T("DrawWndProc::PartWndProc")));

			SetBkMode(hdc , TRANSPARENT);
			TextOut(hdc , 10 , 30, _T("WM_PAINTで実装。GDIにて描画。TextOut関数。") , _tcslen( _T("WM_PAINTで実装。GDIにて描画。TextOut関数。")));

			EndPaint(hWnd , &ps);
			
			return 0;
		}
		default:
			break;
			//return (DefWindowProc(hWnd, uMsg, wParam, lParam));
	}
	return (0L);

}