cmake_minimum_required(VERSION 3.5)
project(single-responsibility-principle)

set(CMAKE_CXX_STANDARD 14)

add_executable(srp main.cpp journal.cpp persistor.cpp persistor.h)