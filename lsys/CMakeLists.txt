cmake_minimum_required(VERSION 3.25)

project(lsys
	LANGUAGES CXX 
)

file(GLOB SOURCES CONFIGURE_DEPENDS
	src/*.cpp 
)
file(GLOB HEADERS CONFIGURE_DEPENDS 
	include/lsys/*.hpp
)

add_library(nm_lsys STATIC)
add_library(nm::lsys ALIAS nm_lsys)
target_sources(nm_lsys
	PUBLIC
		${SOURCES}
	PUBLIC FILE_SET nm_lsys_headers
		TYPE HEADERS 
			BASE_DIRS include/
			FILES ${HEADERS}
)

target_include_directories(nm_lsys
	PUBLIC include/lsys
)

add_subdirectory(tests)
