#pragma once

namespace VULTR_DDNS
{
	enum class DisplayMode
	{
		Background, Console
	};

	class Application
	{
	protected:
		Application(DisplayMode mode);
	public:
		virtual ~Application() = default;

	public:
		virtual void print(const char* fmt, ...) const;
		virtual void println(const char* fmt, ...) const;
		//virtual char* getLine(char* pBuffer, size_t szBuffer) const;

	protected:
		virtual void init(DisplayMode mode) = 0;
	
	protected:
		const DisplayMode m_DisplayMode;
	};

	extern std::shared_ptr<Application> CreateApplication(DisplayMode mode);
}