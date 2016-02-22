#-------------------------------------------------------------------------------------------
# CMake info
#-------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.5)
project(luac)

file(GLOB_RECURSE SRC_LUA
  "${LUA_SHARED_DIR}/*.C"
  "${LUA_SHARED_DIR}/*.h)")

list(REMOVE_ITEM SRC_LUA "${LUA_SHARED_DIR}/lua.c")

include_directories("${LUA_SHARED_DIR}")
add_executable(luac ${SRC_LUA})
source_group("lua" FILES ${SRC_LUA})
