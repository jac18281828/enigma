cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_VERBOSE_MAKEFILE on)
SET(CMAKE_CXX_FLAGS_RELEASE -O3)
add_compile_options(-std=c++0x)
project (enigma)
set(HEADER_FILES src/enigma3.h)
set(SRC src/enigma3.cc)

add_executable(enigma ${HEADER_FILES} ${SRC} src/main.cc)

enable_testing()

add_executable(maptest  ${HEADER_FILES} ${SRC} test/maptest.cc)

add_test(map maptest)

target_include_directories(maptest PRIVATE src)
