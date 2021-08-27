#include <VultrDDNS.hpp>

#include <fstream>
#include <cstdio>

using namespace VultrDDNS;

#ifdef PLATFORM_WINDOWS

int main(int argc, char** argv)
{
	WindowsApplication app;
	if (!app.ParseArguments(argc, argv))
	{
		//app.WaitForUser();
		return 0;
	}

	if (!app.Initialize())
	{
		app.WaitForUser();
		return 1;
	}

	httplib::Client http("https://api.ipify.org");
	http.set_ca_cert_path(app.GetAbsolutePath("/cacert.pem").c_str());
	http.enable_server_certificate_verification(true);
	auto res = http.Get("/");
	if (res.error() == httplib::Error::Success)
	{
		app.println("Public IP address: %s", res.value().body.c_str());
	}
	else
	{
		app.println("Failed to fetch public IP address with error code: %d", res.error());
	}

	app.WaitForUser();
	app.Shutdown();
	return 0;
}

#endif