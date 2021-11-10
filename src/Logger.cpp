#include "Logger.h"

Logger::Logger()
{
	printf("Compilation date [%s %s]\n", __DATE__, __TIME__);
}

Logger::~Logger()
{
}

Logger& Logger::getLog(const char* file, const long line, const char* function, const char* signature, LOG type)
{
	// -------------------------------------
	// | Text color     | Background color |
	// -------------------------------------
	// | 30 -> Black    | 40 -> Black      |
	// | 31 -> Red      | 41 -> Red        |
	// | 32 -> Green    | 42 -> Green      |
	// | 33 -> Yellow   | 43 -> Yellow     |
	// | 34 -> DarkBlue | 44 -> DarkBlue   |
	// | 35 -> Purple   | 45 -> Purple     |
	// | 36 -> Blue     | 46 -> Blue       |
	// | 37 -> White    | 47 -> White      |
	// -------------------------------------

	static Logger log;

	switch (type)
	{
	case LOG::CLASS: printf("\033[36m%s\n\033[0m", function); break;
	case LOG::WM: printf("\033[33m"); break;
	case LOG::MESSAGE: printf("\033[37m"); break;
	case LOG::ERRORS: printf("\033[31m[%s:%i] %s -> ", file, line, signature); break;
	}

	return log;
}

void Logger::print(const char* message, ...)
{
	va_list list;
	va_start(list, message);

	while (*message != '\0')
	{
		if (*message == '%')
		{
			switch (*++message)
			{
			case 'i': printf("%i", va_arg(list, int)); break;
			case 'f': printf("%f", va_arg(list, double)); break;
			case 's': printf("%s", va_arg(list, char*)); break;
			default: printf("%c", *message); break;
			}
			message++;
		}
		else printf("%c", *message++);
	}
	printf("\n\033[0m");

	va_end(message);
}