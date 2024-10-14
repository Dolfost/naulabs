cmake_minimum_required(VERSION 3.25)

project(lsys
	LANGUAGES CXX 
)

file(GLOB SOURCES CONFIGURE_DEPENDS
	src/*.cpp 
)
file(GLOB HEADERS CONFIGURE_DEPENDS 
	include/calgo/lsys/*.hpp
)

add_library(ca_lsys STATIC)
add_library(ca::lsys ALIAS ca_lsys)
target_sources(ca_lsys
	PUBLIC
		${SOURCES}
	PUBLIC FILE_SET ca_lsys_headers
		TYPE HEADERS 
			BASE_DIRS include/
			FILES ${HEADERS}
)

target_include_directories(ca_lsys
	PUBLIC include/
)

target_link_libraries(ca_lsys
	PUBLIC ca::calgo
)

add_subdirectory(tests)
