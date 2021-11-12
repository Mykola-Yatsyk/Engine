#include "Application.h"

int main(int argc, char* argv[])
{
	Log(LOG::MESSAGE).print("Start Application");

	Application app;
	app.createWindow("Application");

	return EXIT_SUCCESS;
}