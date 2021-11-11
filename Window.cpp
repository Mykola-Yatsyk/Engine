#include "Window.h"

LRESULT CALLBACK Window::WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(EXIT_SUCCESS);
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

Window::Window()
{
}

void Window::createWindow(const char* title)
{
	WNDCLASS wnd;
	wnd.style = CS_OWNDC;
	wnd.lpfnWndProc = &Window::WindowProc;
	wnd.cbClsExtra = NULL;
	wnd.cbWndExtra = NULL;
	wnd.hInstance = GetModuleHandle(NULL);
	wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	wnd.hbrBackground = HBRUSH(GetStockObject(BLACK_BRUSH));
	wnd.lpszMenuName = NULL;
	wnd.lpszClassName = title;
	RegisterClass(&wnd);

	HWND hWnd = CreateWindowEx(WS_EX_APPWINDOW, title, title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, GetModuleHandle(NULL), NULL);

	PIXELFORMATDESCRIPTOR pfd;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;

	HDC hDC = GetDC(hWnd);
	SetPixelFormat(hDC, ChoosePixelFormat(hDC, &pfd), &pfd);

	HGLRC hGLRC = wglCreateContext(hDC);
	wglMakeCurrent(hDC, hGLRC);

	ShowWindow(hWnd, SW_SHOWDEFAULT);

	MSG msg;

	bool run = true;
	while (run)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) run = false;
			else DispatchMessage(&msg);
		}
		else SwapBuffers(hDC);
	}

	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hGLRC);
	ReleaseDC(hWnd, hDC);
}

Window::~Window()
{
}