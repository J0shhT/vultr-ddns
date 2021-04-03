cmake_minimum_required(VERSION 3.16.4)
project(vultrddns LANGUAGES CXX VERSION 0.0.0)

add_compile_definitions(_UNICODE UNICODE)

set(PROJECT_SOURCES "${PROJECT_NAME}_SOURCES")
set(PROJECT_HEADERS "${PROJECT_NAME}_HEADERS")

file(GLOB_RECURSE "${PROJECT_SOURCES}" ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE "${PROJECT_HEADERS}" ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_executable(${PROJECT_NAME} WIN32 "${${PROJECT_SOURCES}}")

target_include_directories(${PROJECT_NAME}
	PUBLIC
		"${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_precompile_headers(${PROJECT_NAME}
	PRIVATE
		<Common.h>
)