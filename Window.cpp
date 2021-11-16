#include "Window.h"

LRESULT CALLBACK Window::WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		Log(LOG::WM).print("WM_CREATE");
		break;

	case WM_SIZE:
		GetRender.setViewPort(LOWORD(lParam), HIWORD(lParam));
		break;

	case WM_CLOSE:
		Log(LOG::WM).print("WM_CLOSE");
		DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		Log(LOG::WM).print("WM_DESTROY");
		PostQuitMessage(EXIT_SUCCESS);
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

Window::Window(Engine* engine)
{
	Log(LOG::CLASS);
	GetRender.setEngine(engine);
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

	GetRender.init();

	ShowWindow(hWnd, SW_SHOWDEFAULT);

	MSG msg;

	GetRender.run();
	while (GetRender.isRun())
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) GetRender.exit();
			else DispatchMessage(&msg);
		}
		else
		{
			GetRender.draw();
			SwapBuffers(hDC);
		}
	}

	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hGLRC);
	ReleaseDC(hWnd, hDC);
}

Window::~Window()
{
	Log(LOG::CLASS);
}