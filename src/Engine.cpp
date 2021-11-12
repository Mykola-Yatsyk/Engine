#include "Engine.h"

Engine::Engine() : Window(this)
{
	Log(LOG::CLASS);
}

Engine::~Engine()
{
	Log(LOG::CLASS);
}

void Engine::exit()
{
	Log(LOG::CLASS);

	run = false;
}

void Engine::createWindow(const char* title)
{
	Log(LOG::CLASS);

	Window::createWindow(title);
}