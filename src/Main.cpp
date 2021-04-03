#include <VultrDDNS.hpp>

#include <fstream>
#include <cstdio>

using namespace VultrDDNS;

int main(int argc, wchar_t** argv)
{
	auto app = CreateApplication(DisplayMode::Console);

	httplib::Client http("http://api.ipify.org");
	auto res = http.Get("/").value();
	app->println("External IP: %s", res.body.c_str());

	std::ifstream configFile("config.json");
	if (configFile.good())
	{
		json config;
		configFile >> config;
		if (config.contains("domainName"))
		{
			std::string domainName = config.at("domainName");
			app->println("config.domainName = %s", domainName.c_str());
		}
	}
	else
	{
		app->println("Failed to open config.json");
	}
	configFile.close();

	printf("Press enter to exit...");
	getchar();
	return 0;
}

#ifdef PLATFORM_WINDOWS

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int cmdShow)
{
	int argc = 0;
	PWSTR* argv = CommandLineToArgvW(GetCommandLine(), &argc);
	return main(argc, argv);
}

#endif