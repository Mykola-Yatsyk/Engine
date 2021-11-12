#ifndef ENGINE_H
#define ENGINE_H

#include "Window.h"

class Engine : private Window, private Render
{
protected:
	Engine();
	~Engine();

	void exit();

public:
	void createWindow(const char* title);
};

#endif