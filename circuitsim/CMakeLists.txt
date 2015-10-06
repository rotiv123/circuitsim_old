cmake_minimum_required(VERSION 3.0)
project(circuitsim)

set(circuitsim_MAJOR_VERSION 1)
set(circuitsim_MINOR_VERSION 0)
set(circuitsim_PATCH_VERSION 0)
set(circuitsim_VERSION ${circuitsim_MAJOR_VERSION}.${circuitsim_MINOR_VERSION}.${circuitsim_PATCH_VERSION})

configure_file("config.h.in" "${PROJECT_BINARY_DIR}/config.h")
include_directories("${PROJECT_BINARY_DIR}")

add_library(circuitsim SHARED
        src/circuitsim.cpp
        src/simulation.cpp
        src/simulation.h
        include/circuitsim.h
        include/circuitsim++.h
        src/parser.cpp
        src/parser.h
        src/token.h
        src/token.cpp
        src/resistor.cpp
        src/resistor.h
        include/circuitsim/simulation.h
        include/circuitsim/utils.h
        src/component.h
        src/component.cpp
        src/voltage_source.cpp
        src/voltage_source.h
        src/current_source.cpp
        src/current_source.h
        src/utils.h
        src/matrix.h
        src/matrix.cpp)

set_target_properties(circuitsim PROPERTIES VERSION ${circuitsim_VERSION} SOVERSION ${circuitsim_MAJOR_VERSION})

install(TARGETS circuitsim DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
