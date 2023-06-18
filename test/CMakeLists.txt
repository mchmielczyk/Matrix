cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 14)

set(Sources
	matrixtest.cpp
)

add_executable(matrixtest ${Sources})

target_link_libraries(matrixtest PUBLIC
	gtest_main
	MATRIX
)

add_test(
	NAME matrixtest
	COMMAND matrixtest
)
