#include <Core/Application.h>
#include <Core/Exceptions.h>

using namespace VULTR_DDNS;

bool Application::Initialize()
{
	LoadConfiguration();
	return true;
}

bool Application::ParseArguments(int argc, char** argv)
{
	namespace po = boost::program_options;
	namespace fs = boost::filesystem;
	if (argc < 1)
		return false;

	const char* exePathString = argv[0];
	fs::path exePath(exePathString);
	if (!fs::exists(exePath))
		return false;
	m_AppDir = exePath.parent_path().generic_string();

	po::options_description options("Supported options");
	options.add_options()
		("help", "produces this help message")
	;
	
	po::store(po::parse_command_line(argc, argv, options), m_Args);
	po::notify(m_Args);

	if (m_Args.count("help"))
	{
		std::basic_stringstream<char> optionsStream;
		options.print(optionsStream);
		const char* message = optionsStream.str().c_str();
		print("%s", message);
		return false;
	}

	return true;
}

void Application::LoadConfiguration()
{
	std::string configFilePath = GetAbsolutePath("/config.json");
	std::ifstream configFile(configFilePath);
	if (configFile.good())
	{
		json config;
		configFile >> config;
		m_Config = config.get<Configuration>();

		json output = m_Config;
		println("Loaded configuration file: %s", configFilePath.c_str());
	}
	else
	{
		throw initialization_error("Failed to open config.json");
	}
}

void Application::WaitForUser() const
{
	print("Press enter to continue...");
	std::getchar();
}

std::string Application::GetAbsolutePath(const std::string& path) const
{
	namespace fs = boost::filesystem;
	fs::path appPath(m_AppDir);
	fs::path newPath = appPath.append(path);
	return newPath.generic_string();
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
	vfprintf_s(stdout, fmt, args);
	va_end(args);
	std::cout << std::endl;
}