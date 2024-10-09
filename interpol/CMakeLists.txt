cmake_minimum_required(VERSION 3.25)

project(interpolation
	LANGUAGES CXX 
)

file(GLOB SOURCES CONFIGURE_DEPENDS 
	${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)
file(GLOB HEADERS CONFIGURE_DEPENDS 
	${CMAKE_CURRENT_LIST_DIR}/include/**.hpp
)

add_library(nm_interpol STATIC)
add_library(nm::interpol ALIAS nm_interpol)
target_sources(nm_interpol
	PUBLIC
		${SOURCES}
	PUBLIC FILE_SET nm_interpol_headers
		TYPE HEADERS 
			BASE_DIRS include/
			FILES ${HEADERS}
)

target_include_directories(nm_interpol 
	PUBLIC include
)

target_link_libraries(nm_interpol
	PUBLIC exprtk nm::lsys
)
