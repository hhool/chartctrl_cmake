# ********************************************************************
# CMakeLists for anxi
# file: CMakeLists.txt
# author: hhool
# date: 2024-08-14
# ********************************************************************

cmake_minimum_required(VERSION 3.0)

project(console LANGUAGES CXX)

# MFC is required
find_package(MFC)

if(NOT MFC_FOUND)
    MESSAGE(FATAL_ERROR "MFC not found")
endif()

add_definitions(-D_AFXDLL)

# 1 the static MFC library 2 shared MFC library
set(CMAKE_MFC_FLAG 1)

set(sources
)

add_executable(console ${sources} main.cc)

target_link_libraries(console PRIVATE chartctrl)
