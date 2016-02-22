#-------------------------------------------------------------------------------------------
# CMake info
#-------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.5)
project(luatutorial)

#-------------------------------------------------------------------------------------------
# Source files
#-------------------------------------------------------------------------------------------
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/../shared/lua/src)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../shared/lua/src)

file(GLOB_RECURSE SRC_LUA
  "${LUA_SHARED_DIR}/*.C"
  "${LUA_SHARED_DIR}/*.h)")

list(REMOVE_ITEM SRC_LUA "${LUA_SHARED_DIR}/luac.c")

include_directories("${LUA_INCLUDE_DIR}")
add_executable(luashell ${SRC_LUA})
source_group("lua" FILES ${SRC_LUA})
