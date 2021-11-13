#ifndef WINDOW_H
#define WINDOW_H

#include "Render.h"

class Window
{
private:
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:
	Window();
	void createWindow(const char* title);
	virtual ~Window();
};

#endif