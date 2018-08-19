cmake_minimum_required(VERSION 3.5)
project(builder-pattern)

set(CMAKE_CXX_STANDARD 14)

add_executable(builder-pattern HtmlElement.cpp HtmlBuilder.cpp main.cpp)