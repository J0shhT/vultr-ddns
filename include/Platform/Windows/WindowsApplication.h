#pragma once

#ifdef PLATFORM_WINDOWS

#include <Core/Application.h>

namespace VULTR_DDNS
{
	class WindowsApplication : public Application
	{
	public:
		WindowsApplication();
		virtual ~WindowsApplication() = default;
	
	public:
		bool Initialize() override;
		void Shutdown() override;
	};
}

#endif