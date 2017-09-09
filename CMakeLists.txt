cmake_minimum_required(VERSION 3.6)

set( APP_LIB_NAME $ENV{APP_LIB_NAME})
set( APP_EXE_NAME $ENV{APP_MAIN_EXE})
set( APP_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

project(${APP_LIB_NAME})

set (APP_VERSION_MAJOR 0)
set (APP_VERSION_MINOR 1)
set (APP_VERSION_PATCH 0)
set (APP_VERSION_BUILD $ENV{BUILD_REVISION})
set (APP_VERSION_DATE  $ENV{BUILD_TIMESTAMP})

if ("$ENV{BUILD_REVISION}" STREQUAL "")
  message (FATAL_ERROR "BUILD_REVISION not specified in ENV")
endif()

if ("$ENV{BUILD_TIMESTAMP}" STREQUAL "")
  message (FATAL_ERROR "BUILD_TIMESTAMP not specified in ENV")
endif()

# Add compile time definitions for debug optimizations
if ("$ENV{CMAKE_BUILD_TYPE}" STREQUAL "debug")
  add_definitions(-D_DEBUG_)
endif()


# This project uses C11 Standard
set( CMAKE_C_STANDARD 11 )

# Treat all warnings as intense errors.
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")
enable_testing ()

# Main library support
add_subdirectory("src/${APP_LIB_NAME}")

# Our main executable sub project
add_subdirectory("src/main")

# Lots of tests :-)
add_subdirectory("tests")

add_subdirectory("vendor/ubelt")

# Setup auto generation of version.h during build
configure_file (
  "${APP_ROOT}/src/version.h.in"
  "${APP_ROOT}/src/version.h"
)

include_directories(
  "${APP_ROOT}/src"
  "${APP_ROOT}/vendor/ubelt/src"
)
