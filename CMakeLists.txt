cmake_minimum_required(VERSION 3.10)
project(rtx)

include_directories(LinearAlg_libs)
add_executable(${PROJECT_NAME} main.cpp)

target_sources(${PROJECT_NAME} PRIVATE ${HEADERS})