cmake_minimum_required(VERSION 3.10)
project(prog LANGUAGES CXX)

# Set C++ standard to match Makefile's -std=c++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Equivalent to Makefile's -Wall
add_compile_options(-Wall)


# Explicit source list matching Makefile's SRC
set(SOURCES
    main.cpp
    source/commands.cpp
    source/factory/circle.cpp
    source/factory/rectangle.cpp
    source/factory/triangle.cpp
    source/factory/polygon.cpp
    source/context.cpp
    source/vector.cpp
    source/menu.cpp
    source/shapes/circle.cpp
    source/shapes/rectangle.cpp
    source/shapes/shape.cpp
    source/shapes/triangle.cpp
    source/shapes/polygon.cpp
    source/exceptions.cpp
    source/printer/printer_perim.cpp
    source/printer/printer.cpp
)

# Create executable (matches Makefile's TARGET)
add_executable(prog.out ${SOURCES})

# Equivalent to Makefile's -Iinclude
target_include_directories(prog.out PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)