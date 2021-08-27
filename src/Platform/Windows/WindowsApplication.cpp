#ifdef PLATFORM_WINDOWS

#include <Platform/Windows/WindowsApplication.h>
#include <Core/Exceptions.h>

using namespace VULTR_DDNS;

WindowsApplication::WindowsApplication()
{
}

bool WindowsApplication::Initialize()
{
	try
	{
		return Application::Initialize();
	}
	catch (const initialization_error& e)
	{
		const char* const message = e.what();
		println("ERROR: %s", message);
		return false;
	}
}

void WindowsApplication::Shutdown()
{
}

#endif