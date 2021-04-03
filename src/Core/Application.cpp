#include <Core/Application.h>

#include <cstdio>
#include <cstdarg>
#include <cstring>

using namespace VULTR_DDNS;

Application::Application(DisplayMode mode)
	: m_DisplayMode(mode)
{
}

void Application::print(const char* fmt, ...) const
{
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);
}

void Application::println(const char* fmt, ...) const
{
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	putc('\n', stdout);
	va_end(args);
}

/*
char* Application::getLine(char* pBuffer, size_t szBuffer) const
{
	size_t fmtSize = 2u + 10u + 1u;
	char* fmt = new char[fmtSize];
	if (snprintf(fmt, fmtSize, "%%%zds", szBuffer) < 0)
	{
		delete[] fmt;
		return nullptr;
	}
	if (fscanf(stdin, fmt, pBuffer) == 1)
	{
		return pBuffer;
	}
	return nullptr;
}
*/