cmake_minimum_required(VERSION 3.5)
project(prototype-pattern)

set(CMAKE_CXX_STANDARD 14)

add_executable(prototype-pattern IpAddress.cpp Location.cpp Domain.cpp Host.cpp main.cpp HostFactory.cpp)