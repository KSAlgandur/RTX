cmake_minimum_required(VERSION 3.10)
project(rtx)

#include_directories(LinearAlg_libs)

add_executable(${PROJECT_NAME} main.cpp )

add_subdirectory(LinearAlg_libs)

target_link_libraries(${PROJECT_NAME} LinearAlg_libs)
#target_sources(${PROJECT_NAME} PRIVATE ${SOURCES} ${HEADERS})