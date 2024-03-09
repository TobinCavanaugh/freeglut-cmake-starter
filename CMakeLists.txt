cmake_minimum_required(VERSION 3.25.1)

project(freeglut-project-starter VERSION 1.0)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(${LIB_DIR})
add_subdirectory(${SRC_DIR})
