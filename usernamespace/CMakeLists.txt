cmake_minimum_required(VERSION 3.0.0)
project(usernamespace VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(usernamespace main.c)

SET(GCC_COVERAGE_LINK_FLAGS    "-lcap")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--no-as-needed ${GCC_COVERAGE_LINK_FLAGS}")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
