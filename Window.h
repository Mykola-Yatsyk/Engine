#ifndef WINDOW_H
#define WINDOW_H

#include <Windows.h>
#include <gl/GL.h>

#pragma comment(lib, "opengl32.lib")

class Window
{
private:
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:
	Window();
	void createWindow(const char* title);
	~Window();
};

#endif