#pragma once
#pragma comment(lib, "Rpcrt4.lib")
#include <windows.h>
#include <tchar.h>
#include <string>
#include <vector>
#include "IPartWndProc.h"
using namespace std;

class Window
{
public:
	~Window(void);
	static void Create(HINSTANCE hInstance);
	static vector<IPartWndProc*> partWndProcs;
protected:
private:
	Window(void);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static basic_string<TCHAR> GetUuid();

	//WNDCLASSEX m_wndClassEx;
	//HWND m_hWnd;
};

