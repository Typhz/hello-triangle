cmake_minimum_required(VERSION 3.26)
project(HelloTriangle)

add_executable(HelloTriangle main.cpp "Vectors.cpp")

target_include_directories(
	HelloTriangle PRIVATE deps/glm deps/stb deps/glfw/include deps/glew/include
)

target_link_directories(HelloTriangle PRIVATE deps/glfw/lib-vc2019 deps/glew/lib/Release/x64)

target_link_libraries(HelloTriangle PRIVATE glfw3.lib glew32.lib opengl32.lib)

add_custom_command(TARGET HelloTriangle POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/deps/glew/bin/Release/x64/glew32.dll" "${CMAKE_BINARY_DIR}/glew32.dll")

add_executable(Vectors "Vectors.cpp")
target_include_directories(Vectors PRIVATE deps/glm)