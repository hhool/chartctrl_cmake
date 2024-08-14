# ********************************************************************
# CMakeLists for anxi
# file: CMakeLists.txt
# author: hhool
# date: 2024-07-16
# ********************************************************************

cmake_minimum_required(VERSION 3.0)

project(chartctrl LANGUAGES CXX)

# set output directory
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif()

# set build tpye
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# set product name
set(PRODUCT_NAME chartctrl CACHE STRING "chartctrl")
set(PRODUCT_VERSION 3.0.2 CACHE STRING "chartctrl version")

# options
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(USE_UNICODE "Use unicode" ON)
option(CHARTCTRL_BUILD_EXAMPLES "Build chartctrl examples" ON)
option(CHARTCTRL_BUILD_DOC "Build chartctrl Doc" OFF)
option(CHARTCTRL_BUILD_TEST "Build chartctrl Test" ON)
option(CHARTCTRL_BUILD_UNITTEST "Build chartctrl Unittest" ON)

# only build library if add chartctrl as subdirectory
if(NOT CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    set(CHARTCTRL_BUILD_EXAMPLES OFF)
    set(CHARTCTRL_BUILD_DOC OFF)
    set(CHARTCTRL_BUILD_TEST OFF)
    set(CHARTCTRL_BUILD_UNITTEST OFF)
endif()

# chartctrl UNICODE define for windows platform
# with MFC support for windows platform
if(WIN32)
    add_definitions(-D_AFXDLL)

    # 1: use MFC as a static library
    # 2: use MFC as a shared DLL
    set(CMAKE_MFC_FLAG 1)

    # for windows xp and later
    # Windows Server 2003 with SP1, Windows XP with SP2
    add_definitions(-D_WIN32_WINNT=0x0502)
endif()

# chartctrl UNICODE define for windows platform
if(WIN32)
    if(USE_UNICODE)
        add_definitions(-DUNICODE -D_UNICODE)
    endif()

    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

if(NOT CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    message(STATUS "chartctrl CMake Info")
    message(STATUS "=======================================================")
    message(STATUS "    Operation System :  ${CMAKE_SYSTEM}")
    message(STATUS "    CPU Architecture : ${CMAKE_SYSTEM_PROCESSOR}")
    message(STATUS "    Build Type : ${CMAKE_BUILD_TYPE}")
    message(STATUS "    Shared Library  : ${BUILD_SHARED_LIBS}")
    message(STATUS "    Build Examples  : ${CHARTCTRL_BUILD_EXAMPLES}")
    message(STATUS "    Build Doc  : ${CHARTCTRL_BUILD_DOC}")
    message(STATUS "    Build Test  : ${CHARTCTRL_BUILD_TEST}")
    message(STATUS "    Build Unittest  : ${CHARTCTRL_BUILD_UNITTEST}")
    message(STATUS "=======================================================")
endif()

FILE(GLOB_RECURSE chartctrl_src CONFIGURE_DEPENDS chartctrl_source/*.h chartctrl_source/*.cpp chartctrl_source/*.inl)
FILE(GLOB_RECURSE chartctrl_wapper_src CONFIGURE_DEPENDS ./*.h ./*.cpp ./*.cc)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/chartctrl_source)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
add_library(chartctrl STATIC ${chartctrl_src} ${chartctrl_wapper_src})

add_definitions(-DCHARTCTRL_EXPORTS)
target_link_libraries(chartctrl comctl32)
set_target_properties(chartctrl PROPERTIES OUTPUT_NAME "chartctrl")

if(CHARTCTRL_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
