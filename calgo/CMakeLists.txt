cmake_minimum_required(VERSION 3.25)

add_library(ca_calgo INTERFACE)
add_library(ca::calgo ALIAS ca_calgo)

target_sources(ca_calgo
	INTERFACE
		include/calgo/calgo.hpp
	PUBLIC FILE_SET ca_calgo_headers
		TYPE HEADERS 
			BASE_DIRS include/
			FILES include/calgo/calgo.hpp
)

target_include_directories(ca_calgo 
	INTERFACE include
)
