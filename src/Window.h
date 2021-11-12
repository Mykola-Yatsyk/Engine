#ifndef WINDOW_H
#define WINDOW_H

#include "Render.h"

class Window
{
private:
	Render* m_render;
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	friend static LRESULT CALLBACK WindowProcStatic(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

protected:
	Window(Render* render);
	virtual ~Window();

	void createWindow(const char* title);
};

#endif