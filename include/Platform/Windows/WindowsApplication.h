#pragma once

#ifdef PLATFORM_WINDOWS

#include <Core/Application.h>

namespace VULTR_DDNS
{
	class WindowsApplication : public Application
	{
	public:
		WindowsApplication(DisplayMode mode);
		virtual ~WindowsApplication();

	protected:
		virtual void init(DisplayMode mode) override;
		virtual void initConsole();
	
	protected:
		bool m_IsInitialized;
	};
}

#endif