#pragma once

namespace VULTR_DDNS
{
	struct Configuration
	{
		std::string apiKey;
		std::string domainName;
		std::string recordType;
		std::string recordName;
		unsigned int recordTTL;
	};

	class Application
	{
	protected:
		Application() = default;
	public:
		virtual ~Application() = default;

	public:
		virtual bool Initialize();
		virtual void Shutdown() = 0;
		virtual bool ParseArguments(int argc, char** argv);
		virtual void LoadConfiguration();

		virtual void WaitForUser() const;
		std::string GetAbsolutePath(const std::string& path) const;

		virtual void print(const char* fmt, ...) const;
		virtual void println(const char* fmt, ...) const;

	protected:
		std::string m_AppDir;
		boost::program_options::variables_map m_Args;
		Configuration m_Config;
	};

	NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Configuration, apiKey, domainName, recordType, recordName, recordTTL)
}