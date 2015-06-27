cmake_minimum_required(VERSION 3.2)
project(circuitsim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

#include_directories("${PROJECT_INCLUDE_DIR}")

add_library(${PROJECT_NAME} SHARED src/circuitsim.cpp)