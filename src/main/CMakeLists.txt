cmake_minimum_required(VERSION 3.6)
project(${APP_EXE_NAME})

# This project uses C11 Standard
set( CMAKE_C_STANDARD 11 )

# Treat all warnings as intense errors.
if(UNIX)
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror -Wall -Wextra")
endif()

# Main executable has a single file
SET ( SRC_MAIN main.c )

if (WIN32)
    set(ICON ${APP_ROOT}/assets/fii.rc)
elseif (APPLE)
    set(ICON_ICNS ${APP_ROOT}/assets/fii.icns)
	set(ICON ${ICON_ICNS})
    set_source_files_properties(${ICON_ICNS} PROPERTIES
        MACOSX_PACKAGE_LOCATION "Resources")
endif()

# Setup main executable for this project
add_executable(${APP_EXE_NAME} WIN32 MACOSX_BUNDLE ${ICON} ${SRC_MAIN})

if (APPLE)
set_target_properties(${APP_EXE_NAME} PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Factorii")
set_target_properties(${APP_EXE_NAME} PROPERTIES
                        RESOURCE ${ICON_ICNS}
                        MACOSX_BUNDLE_SHORT_VERSION_STRING ${APP_VERSION_BUILD}
                        MACOSX_BUNDLE_LONG_VERSION_STRING ${APP_VERSION_FULL}
                        MACOSX_BUNDLE_ICON_FILE ${ICON_ICNS}
                        MACOSX_BUNDLE_INFO_PLIST "${APP_ROOT}/CMake/MacOSXBundleInfo.plist.in")
endif()

if (MSVC)
    # Tell MSVC to use main instead of WinMain for Windows subsystem executables
    set_target_properties(${APP_EXE_NAME} PROPERTIES
                          LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()

# Link Library support
target_link_libraries( ${APP_EXE_NAME}
  ${OPENGL_glu_LIBRARY}
  ${APP_LIB_NAME})

install(TARGETS ${APP_EXE_NAME}
  BUNDLE DESTINATION ${APP_ROOT}/build COMPONENT Runtime
  RUNTIME DESTINATION bin)

