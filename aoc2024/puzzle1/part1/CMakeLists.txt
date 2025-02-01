cmake_minimum_required(VERSION 3.30.3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(SOURCES main.cpp)

project(test)

add_executable(${PROJECT_NAME} ${SOURCES})
