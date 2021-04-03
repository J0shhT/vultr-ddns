#ifdef PLATFORM_WINDOWS

#include <Platform/Windows/WindowsApplication.h>

#include <iostream>

using namespace VULTR_DDNS;

WindowsApplication::WindowsApplication(DisplayMode mode)
	: Application(mode), m_IsInitialized(false)
{
	init(mode);
}

WindowsApplication::~WindowsApplication()
{
	if (m_DisplayMode == DisplayMode::Console && m_IsInitialized)
		FreeConsole();
}

void WindowsApplication::init(DisplayMode mode)
{
	switch (mode)
	{
		case DisplayMode::Console:
			initConsole();
			break;
		case DisplayMode::Background:
			break;
		default:
			assert(false);
			break;
	}
}

void WindowsApplication::initConsole()
{
	if (AllocConsole() == 0)
	{
		bool consoleAllocSuccess = FreeConsole() != 0 && AllocConsole() != 0;
		assert(consoleAllocSuccess);
	}
	
	FILE* pIoFile;
    freopen_s(&pIoFile, "CONOUT$", "w", stdout);
    freopen_s(&pIoFile, "CONOUT$", "w", stderr);
    freopen_s(&pIoFile, "CONIN$", "r", stdin);
	std::cout.clear();
    std::clog.clear();
    std::cerr.clear();
    std::cin.clear();

	m_IsInitialized = true;
}

std::shared_ptr<Application> VULTR_DDNS::CreateApplication(DisplayMode mode)
{
	return std::make_shared<WindowsApplication>(mode);
}

#endif