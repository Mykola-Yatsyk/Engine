#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.h"

class Application : public Engine, public Window
{
public:
	Application();
	~Application();
};

#endif