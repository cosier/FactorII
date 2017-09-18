cmake_minimum_required(VERSION 3.6)
project(${APP_LIB_NAME})

# This project uses C11 Standard
set( CMAKE_C_STANDARD 11 )

# Treat all warnings as intense errors.
if(MSVC)
  set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /WX")
else(CMAKE_COMPILER_IS_GNUCXX)
  set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter -Wno-unused-but-set-variable")
endif()

# Glob'n all C source + headers under src/
#
# Below we iterate and remove any tmp files that
# Would otherwise break the Make build system.
file(GLOB_RECURSE SRC_LIB *.c *.h)

# Remove tmp files from source tree
foreach ( PATH ${SRC_LIB} )
  string (FIND ${PATH} "#" FOUND)
  if (NOT ${FOUND} EQUAL -1)
    list ( REMOVE_ITEM SRC_LIB ${PATH} )
  endif()
endforeach( PATH )

# Build project core as a library
add_library(${APP_LIB_NAME} STATIC ${SRC_LIB})

# Use Utility Belt in Shared library mode

# add_library(freetype2 STATIC IMPORTED)
# set_property(TARGET freetype2  PROPERTY LOCATION
  # ${APP_ROOT}/vendor/build/libfreetype.a)

# Everybody needs curses
find_library( ncurses_lib ncurses )

find_package(OpenGL REQUIRED)

if (APPLE)
endif()

if(UNIX)
set(math_lib "m")
endif()

# Link Library support: lib${APP_LIB_NAME}
target_link_libraries( ${APP_LIB_NAME}
  # C Math Lib
  ${math_lib}

  # Cross platform c utility belt
  ubeltx

  # Data persistence
  sqlite3
  # freetype

  # OpenGL toolkit
  ${OPENGL_gl_LIBRARY}
  ${OPENGL_glu_LIBRARY}
  glfw)



