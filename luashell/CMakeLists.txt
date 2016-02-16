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
 
set(PROJECT_LUASHELL_SRCS 
${PROJECT_SOURCE_DIR}/lapi.c
${PROJECT_SOURCE_DIR}/lauxlib.c
${PROJECT_SOURCE_DIR}/lbaselib.c
${PROJECT_SOURCE_DIR}/lbitlib.c
${PROJECT_SOURCE_DIR}/lcode.c
${PROJECT_SOURCE_DIR}/lcorolib.c
${PROJECT_SOURCE_DIR}/lctype.c
${PROJECT_SOURCE_DIR}/ldblib.c
${PROJECT_SOURCE_DIR}/ldebug.c
${PROJECT_SOURCE_DIR}/ldo.c
${PROJECT_SOURCE_DIR}/ldump.c
${PROJECT_SOURCE_DIR}/lfunc.c
${PROJECT_SOURCE_DIR}/lgc.c
${PROJECT_SOURCE_DIR}/linit.c
${PROJECT_SOURCE_DIR}/liolib.c
${PROJECT_SOURCE_DIR}/llex.c
${PROJECT_SOURCE_DIR}/lmathlib.c
${PROJECT_SOURCE_DIR}/lmem.c
${PROJECT_SOURCE_DIR}/loadlib.c
${PROJECT_SOURCE_DIR}/lobject.c
${PROJECT_SOURCE_DIR}/lopcodes.c
${PROJECT_SOURCE_DIR}/loslib.c
${PROJECT_SOURCE_DIR}/lparser.c
${PROJECT_SOURCE_DIR}/lstate.c
${PROJECT_SOURCE_DIR}/lstring.c
${PROJECT_SOURCE_DIR}/lstrlib.c
${PROJECT_SOURCE_DIR}/ltable.c
${PROJECT_SOURCE_DIR}/ltablib.c
${PROJECT_SOURCE_DIR}/ltm.c
${PROJECT_SOURCE_DIR}/lundump.c
${PROJECT_SOURCE_DIR}/lutf8lib.c
${PROJECT_SOURCE_DIR}/lvm.c
${PROJECT_SOURCE_DIR}/lzio.c
${PROJECT_SOURCE_DIR}/lua.c
)
 
include_directories("${PROJECT_BINARY_DIR}")
add_executable(luashell ${PROJECT_LUASHELL_SRCS})
include_directories("${PROJECT_INCLUDE_DIR}")
