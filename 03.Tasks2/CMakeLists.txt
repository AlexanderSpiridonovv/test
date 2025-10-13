cmake_minimum_required(VERSION 3.16)
project(Demo)

# file(GLOB_RECURSE SOURCES "*.cpp")

# add_executable (task ${SOURCES})

add_executable(task
    main.cpp
    Animal.cpp
    Leopard.cpp
    Turtle.cpp
)