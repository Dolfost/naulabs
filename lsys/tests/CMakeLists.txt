enable_testing()

file(GLOB TESTS CONFIGURE_DEPENDS
	*.cpp 
)

foreach(T ${TESTS})
	cmake_path(GET T STEM TNAME)
	add_executable(${TNAME} 
		${T}
	)
	target_compile_definitions(${TNAME} 
		PRIVATE TESTPATH="${CMAKE_CURRENT_LIST_DIR}"
	)
	target_link_libraries(${TNAME} nm::lsys)
	add_test(NAME ${TNAME}
		COMMAND ${TNAME}
	)
endforeach()
