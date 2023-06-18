cmake_minimum_required(VERSION 3.22)

project(MATRIX CXX)


set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(googletest)

set(Headers
	matrix.h
)
set(Sources
	main.cpp
)
add_library(MATRIX STATIC ${Sources} ${Headers})

add_subdirectory(test)