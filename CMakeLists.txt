cmake_minimum_required( VERSION 2.8 )

project( CMake-GLFW-starter )

find_package( OpenGL REQUIRED )

include_directories( "glfw/include" )
include_directories( ${OPENGL_INCLUDE_DIRS} )

set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_BUILD_TESTS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_BUILD_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_subdirectory( glfw )

if( WIN32 )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup" )
endif()

set( CMAKE-GLFW-STARTER-SRC
     main.cpp
     )
     
add_executable( CMake-GLFW-starter ${CMAKE-GLFW-STARTER-SRC} )
target_link_libraries( CMake-GLFW-starter ${OPENGL_LIBRARIES} glfw ${GLFW_LIBRARIES} )
if( MSVC )
    if(${CMAKE_VERSION} VERSION_LESS "3.6.0") 
        message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'CMake-GLFW-starter' as StartUp Project in Visual Studio.\n" )
    else()
        set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT CMake-GLFW-starter )
    endif()
endif()
