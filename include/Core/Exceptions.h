#pragma once

namespace VULTR_DDNS
{
	class initialization_error : public std::runtime_error
	{
	public:
		initialization_error(const char* const err)
			: std::runtime_error(err)
		{
		}
	};
}