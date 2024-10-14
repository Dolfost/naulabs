cmake_minimum_required(VERSION 3.25)

project(interpolation
	LANGUAGES CXX 
)

file(GLOB SOURCES CONFIGURE_DEPENDS 
	${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)
file(GLOB HEADERS CONFIGURE_DEPENDS 
	${CMAKE_CURRENT_LIST_DIR}/include/calgo/**.hpp
)

add_library(ca_interpol STATIC)
add_library(ca::interpol ALIAS ca_interpol)
target_sources(ca_interpol
	PUBLIC
		${SOURCES}
	PUBLIC FILE_SET ca_interpol_headers
		TYPE HEADERS 
			BASE_DIRS include/
			FILES ${HEADERS}
)

target_include_directories(ca_interpol 
	PUBLIC include
)

target_link_libraries(ca_interpol
	PUBLIC ca::lsys
)

target_link_libraries(ca_lsys
	PUBLIC ca::calgo
)

add_subdirectory(tests)
