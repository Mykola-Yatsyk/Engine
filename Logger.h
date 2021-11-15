#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdarg.h>

#define Log(TYPE) Logger::getLog(__FILE__, __LINE__, __FUNCTION__, __FUNCSIG__, TYPE)

enum class LOG { CLASS, WM, MESSAGE, ERRORS };

class Logger
{
private:
	Logger();
	Logger(const Logger& log) = delete;
	Logger& operator=(Logger& log) = delete;

public:
	static Logger& getLog(const char* file, const long line, const char* function, const char* signature, const LOG type);
	void print(const char* message, ...);

	~Logger();
};

#endif