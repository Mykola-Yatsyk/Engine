#ifndef WINDOW_H
#define WINDOW_H

#include <Windows.h>

#include "Logger.h"

#pragma comment(lib, "opengl32.lib")

class Window
{
private:
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	friend static LRESULT CALLBACK WindowProcStatic(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:
	Window();
	~Window();

	void createWindow(const char* title);
};

#endif