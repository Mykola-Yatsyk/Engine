#include <stdlib.h>

#include "Logger.h"

int main(int argc, char* argv[])
{
	Log(LOG::MESSAGE).print("Run Application");

	return EXIT_SUCCESS;
}