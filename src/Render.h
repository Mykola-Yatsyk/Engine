#ifndef RENDER_H
#define RENDER_H

#include <Windows.h>

#include "Logger.h"

#pragma comment(lib, "opengl32.lib")

class Render
{
protected:
	bool run;

	Render();
	virtual ~Render();

public:

	void init();
	void draw();
	
	void exit() { run = false; }
	bool isRun() const { return run; }
};

#endif