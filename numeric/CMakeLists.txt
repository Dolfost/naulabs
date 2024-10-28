cmake_minimum_required(VERSION 3.25)

project(numeric
	LANGUAGES CXX 
)

file(GLOB SOURCES CONFIGURE_DEPENDS
	src/*.cpp 
)
file(GLOB HEADERS CONFIGURE_DEPENDS 
	include/calgo/lsys/*.hpp
)

add_library(ca_numeric STATIC)
add_library(ca::numeric ALIAS ca_numeric)
target_sources(ca_numeric
	PUBLIC
		${SOURCES}
	PUBLIC FILE_SET ca_numeric_headers
		TYPE HEADERS 
			BASE_DIRS include/
			FILES ${HEADERS}
)

target_include_directories(ca_numeric
	PUBLIC include/
)

target_link_libraries(ca_numeric
	PUBLIC ca::calgo
)

add_subdirectory(tests)
