cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ll_e01)

file(GLOB ${PROJECT_NAME}_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sources/*)

add_executable(ll_e01 ${${PROJECT_NAME}_SOURCES})
