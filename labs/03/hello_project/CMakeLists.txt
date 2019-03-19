CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
# project name
project(hello_world)
# executabe produced for the project - note that the binary will be called
# hello and it will be the result of compiling hello.cpp and main.cpp
add_executable(hello hello.cpp main.cpp)
