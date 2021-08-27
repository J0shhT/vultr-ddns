cmake_minimum_required(VERSION 3.16.4)
project(vultrddns LANGUAGES CXX VERSION 0.0.0)

set(PROJECT_SOURCES "${PROJECT_NAME}_SOURCES")
set(PROJECT_HEADERS "${PROJECT_NAME}_HEADERS")

file(GLOB_RECURSE ${PROJECT_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
#file(GLOB_RECURSE ${PROJECT_HEADERS} ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

# nlohmann_json library dependency
add_subdirectory(nlohmann_json)

# httplib library dependecy
set(HTTPLIB_REQUIRE_OPENSSL ON)
set(OPENSSL_USE_STATIC_LIBS ON)
add_subdirectory(cpp-httplib)

# vultrddns executable
add_executable(${PROJECT_NAME})

# Preprocessor definitions
add_compile_definitions(_UNICODE UNICODE)

# Target source files
target_sources(${PROJECT_NAME}
	PRIVATE
		${${PROJECT_SOURCES}}
)

# Target include directories
target_include_directories(${PROJECT_NAME}
	PUBLIC
		"${CMAKE_CURRENT_SOURCE_DIR}/include"
		"$ENV{BOOST_INCLUDE_DIR}"
)

# Target pre-compiled header
target_precompile_headers(${PROJECT_NAME}
	PRIVATE
		<Common.hpp>
)

# Target library directories
target_link_directories(${PROJECT_NAME}
	PUBLIC
		"$ENV{BOOST_LIBRARIES}"
)

# Target libraries
target_link_libraries(${PROJECT_NAME}
	PRIVATE
		nlohmann_json::nlohmann_json
		httplib::httplib
)

# Post build command
# Copy files from "post" directory to built target directory
set(POST_BUILD_DIR "${PROJECT_SOURCE_DIR}/post")
file(GLOB_RECURSE POST_BUILD_FILES ${POST_BUILD_DIR}/*)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${POST_BUILD_FILES} $<TARGET_FILE_DIR:${PROJECT_NAME}>
    COMMENT "Executing post-build command"
)