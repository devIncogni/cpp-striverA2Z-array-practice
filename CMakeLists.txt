cmake_minimum_required(VERSION 3.10)
project(cppProjectTemplate)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_compile_options(-fdiagnostics-color=always -g)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

add_executable(main ${SOURCES})
