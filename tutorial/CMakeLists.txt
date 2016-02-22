#-------------------------------------------------------------------------------------------
# CMake info
#-------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.5)
project(tutorial)

#-------------------------------------------------------------------------------------------
# Source files
#-------------------------------------------------------------------------------------------
set (TUTORIAL_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE SRC_LUA
  "${LUA_SHARED_DIR}/*.C"
  "${LUA_SHARED_DIR}/*.h)")

list(REMOVE_ITEM SRC_LUA "${LUA_SHARED_DIR}/lua.c")
list(REMOVE_ITEM SRC_LUA "${LUA_SHARED_DIR}/luac.c")

file(GLOB_RECURSE SRC_TUTORIAL
  "${TUTORIAL_SOURCE_DIR}/*.cpp"
  "${TUTORIAL_SOURCE_DIR}/*.h"
  )

set(PROJECT_LUASHELL_SRCS
${TUTORIAL_SOURCE_DIR}/config.cpp
${TUTORIAL_SOURCE_DIR}/tutorial.cpp
)

include_directories("${LUA_INCLUDE_DIR}")
add_executable(tutorial ${SRC_LUA} ${SRC_TUTORIAL})
source_group("lua" FILES ${SRC_LUA})
source_group("src" FILES ${SRC_TUTORIAL})
include_directories("${TUTORIAL_SOURCE_DIR}")

if (APPLE)
target_link_libraries(tutorial ncurses)
endif()
