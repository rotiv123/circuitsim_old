cmake_minimum_required(VERSION 3.0)
project(testeapp)

add_executable(testeapp src/main.cpp)
target_link_libraries(testeapp circuitsim)
