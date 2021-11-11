#include "Window.h"

int main(int argc, char* argv[])
{
	Log(LOG::MESSAGE).print("Run Application");

	Window window;
	window.createWindow("Application");

	return EXIT_SUCCESS;
}