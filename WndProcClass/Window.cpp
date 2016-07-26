#include "Window.h"

vector<IPartWndProc*> Window::partWndProcs;

Window::Window(void) {}
Window::~Window(void) {}
void Window::Create(HINSTANCE hInstance)
{
	basic_string<TCHAR> className = Window::GetUuid();

	WNDCLASSEX wc;
	wc.cbSize			= sizeof(WNDCLASSEX); 
	wc.style			= CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc		= Window::WndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hInstance		= hInstance;
	wc.hIcon			= NULL;
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= className.c_str();
	wc.hIconSm			= LoadIcon(NULL, IDI_APPLICATION);
	if (!RegisterClassEx(&wc)) { throw "RegisterClassEx�֐������s�����B"; }

	HWND hWnd = CreateWindowEx(
		0,							// �g���E�B���h�E�X�^�C��
		className.c_str(),			// class��
		_T("Window::Create�Ő�������Window�ł��B"),		// �^�C�g��
		WS_OVERLAPPEDWINDOW,		// Style
		CW_USEDEFAULT,				// X
		CW_USEDEFAULT,				// Y
		CW_USEDEFAULT,				// Width
		CW_USEDEFAULT,				// Height
		NULL,						// �e�E�B���h�E�܂��̓I�[�i�[�E�B���h�E�̃n���h��
		NULL,						// ���j���[�n���h���܂��͎q�E�B���h�E ID
		hInstance,					// �A�v���P�[�V�����C���X�^���X�̃n���h��
		NULL						// �E�B���h�E�쐬�f�[�^
	);
	if (NULL == hWnd) { throw "CreateWindow�֐������s�����B"; }

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
}

LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	BOOL isReturn = false;
	for (unsigned int i = 0; i < Window::partWndProcs.size(); i++) {
		LRESULT res = Window::partWndProcs[i]->PartWndProc(hWnd, uMsg, wParam, lParam, &isReturn);
		if (isReturn) { return res; }
	}
	if (uMsg == WM_NCDESTROY) { PostQuitMessage(0); }
	return (DefWindowProc(hWnd, uMsg, wParam, lParam));
}

basic_string<TCHAR> Window::GetUuid()
{
	RPC_WSTR p;
	UUID uuid;

	::UuidCreate(&uuid);                  // UUID����
	::UuidToString(&uuid, &p);            // UUID�𕶎���ɂ���

	basic_string<TCHAR> str = (WCHAR*)p;
	::RpcStringFree(&p);

	return str;
}
