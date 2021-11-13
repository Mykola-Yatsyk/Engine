#ifndef RENDER_H
#define RENDER_H

#include <windows.h>
#include <gl/GL.h>

#pragma comment(lib, "opengl32.lib")

#define GetRender Render::getRender()

class Render
{
private:
	bool m_run;

	Render();
	Render(const Render& render) = delete;
	Render& operator=(Render& render) = delete;

public:
	static Render& getRender();

	void init();
	void draw();

	~Render();

	void run() { m_run = true; }
	void exit() { m_run = false; }
	bool isRun() const { return m_run; }
};

#endif