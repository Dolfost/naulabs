cmake_minimum_required(VERSION 3.25)

project(run
	LANGUAGES CXX 
)

add_library(nm_run STATIC)
target_sources(nm_run
	PUBLIC
		run.cpp
	PUBLIC FILE_SET nm_interpol_headers
		TYPE HEADERS 
			BASE_DIRS include/
			FILES include/run.hpp
)

target_include_directories(nm_run
	PUBLIC include
)
