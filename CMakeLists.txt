cmake_minimum_required(VERSION 3.23)
project(StringClass)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(StringClass string.h string.cpp tests.cpp)
