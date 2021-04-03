#pragma once

#define VULTR_DDNS VultrDDNS

/**
 * C Standard Library
 */
#include <cassert>

/**
 * C++ Standard Template Library
 */
#include <memory>

/**
 * Dependency Libraries
 */
#include <httplib.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

/**
 * Build types
 */
#if defined(_DEBUG) || !defined(NDEBUG)
	#define BUILD_DEBUG
#else
	#define BUILD_RELEASE
#endif

/**
 * Platform types
 */
#if defined(_WIN32)
	#define PLATFORM_WINDOWS
#endif

/**
 * Architecture types
 */
#if defined(_WIN64)
	#define ARCHITECTURE_x64
#else
	#define ARCHITECTURE_x86
#endif

/**
 * Platform-specific includes
 */
#ifdef PLATFORM_WINDOWS
	#define WIN32_LEAN_AND_MEAN
	#include "Platform/WindowsPlatform.h"
#else
	#error Unsupported platform
#endif