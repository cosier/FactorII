cmake_minimum_required(VERSION 3.6)

set( APP_LIB_NAME factorii)
set( APP_EXE_NAME fii)
set( APP_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

project(${APP_LIB_NAME})

set (APP_VERSION_MAJOR 0)
set (APP_VERSION_MINOR 1)
set (APP_VERSION_PATCH 0)
set (APP_VERSION_BUILD $ENV{BUILD_REVISION})
set (APP_VERSION_DATE  $ENV{BUILD_TIMESTAMP})

if ("$ENV{BUILD_REVISION}" STREQUAL "")
  message (STATUS "BUILD_REVISION not specified in ENV")
  set(ENV{BUILD_REVISION} master)
endif()

if ("$ENV{BUILD_TIMESTAMP}" STREQUAL "")
  message (STATUS "BUILD_TIMESTAMP not specified in ENV")
  set(ENV{BUILD_TIMESTAMP} now)
endif()

# Add compile time definitions for debug optimizations
if ("$ENV{CMAKE_BUILD_TYPE}" STREQUAL "debug")
  add_definitions(-D_DEBUG_)
else()
  add_definitions(-D_DEBUG_)
endif()

# This project uses C11 Standard
set( CMAKE_C_STANDARD 11 )

# Treat all warnings as intense errors.
enable_testing ()

include_directories(
  "${APP_ROOT}/src"
  "${APP_ROOT}/vendor/nuklear"
  "${APP_ROOT}/vendor/ubelt/src"
  "${APP_ROOT}/vendor/glfw/include"
  "${APP_ROOT}/vendor/sqlite/include"
  "${APP_ROOT}/vendor/freetype2/include"
)

# Lots of tests :-)
add_subdirectory("tests")

# Main library support
add_subdirectory("src/${APP_LIB_NAME}")

# Our main executable sub project
add_subdirectory("src/main")

# UI and Rendering
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("vendor/glfw")
add_subdirectory("vendor/ubelt")
add_subdirectory("vendor/sqlite")

# Setup auto generation of version.h during build
configure_file (
  "${APP_ROOT}/src/${APP_LIB_NAME}/build.h.in"
  "${APP_ROOT}/src/${APP_LIB_NAME}/build.h"
)
