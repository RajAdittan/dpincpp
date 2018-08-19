cmake_minimum_required(VERSION 3.5)
project(abstractfactory-pattern)

set(CMAKE_CXX_STANDARD 14)

add_executable(abstractfactory-pattern factory.cpp vehicle.cpp main.cpp)