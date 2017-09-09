cmake_minimum_required(VERSION 3.6)
project(fii)

# This project uses C11 Standard
set( CMAKE_C_STANDARD 11 )

# Treat all warnings as intense errors.
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")

# Main executable has a single file
SET ( SRC_MAIN main.c )

# Setup main executable for this project
add_executable(fii ${SRC_MAIN})

include_directories(
  ${APP_ROOT}/src)

# Link Library support
target_link_libraries( fii factorii )

install(TARGETS fii
  RUNTIME DESTINATION bin)

