cmake_minimum_required(VERSION 3.25)

project(calgo
	LANGUAGES CXX 
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(calgo)
add_subdirectory(lsys)
add_subdirectory(interpol)
add_subdirectory(numeric)
