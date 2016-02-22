#-------------------------------------------------------------------------------------------
# CMake info
#-------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.5)
project(luatutorial)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(LUA_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/shared/lua/src)
set(LUA_SHARED_DIR ${PROJECT_SOURCE_DIR}/shared/lua/src)

MESSAGE(STATUS "LUA_INCLUDE_DIR A: " ${LUA_INCLUDE_DIR})

#-------------------------------------------------------------------------------------------
# Libraries
#-------------------------------------------------------------------------------------------
add_subdirectory(tutorial)
add_subdirectory(luac)
add_subdirectory(luashell)

#-------------------------------------------------------------------------------------------
# Compiler Flags
#-------------------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 11)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

#-------------------------------------------------------------------------------------------
# Defines
#-------------------------------------------------------------------------------------------
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
