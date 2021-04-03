#include <VultrDDNS.h>

#include <cstdio>

using namespace VultrDDNS;

int main(int argc, wchar_t** argv)
{
	auto app = CreateApplication(DisplayMode::Console);
	app->println("Hello World!");

	printf("Press enter to exit...");
	getchar();
	return 0;
}

#ifdef PLATFORM_WINDOWS

BOOL WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int cmdShow)
{
	int argc = 0;
	PWSTR* argv = CommandLineToArgvW(GetCommandLine(), &argc);
	return main(argc, argv) == 0 ? TRUE : FALSE;
}

#endif