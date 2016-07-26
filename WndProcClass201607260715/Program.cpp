#include <locale.h>
#include <windows.h>
#include <tchar.h>
#include <string>
using namespace std;

#include "Window.h"
#include "InitializeWndProc.h"
#include "KeyboardWndProc.h"
#include "DrawWndProc.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow)
{
	setlocale(LC_ALL, ".ACP");
	
	InitializeWndProc initializeWndProc;
	Window::partWndProcs.push_back(&initializeWndProc);

	KeyboardWndProc keyboardWndProc;
	Window::partWndProcs.push_back(&keyboardWndProc);

	DrawWndProc drawWndProc;
	Window::partWndProcs.push_back(&drawWndProc);

	Window::Create(hInstance);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}
