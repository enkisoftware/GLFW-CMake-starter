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

if( UNIX )
		SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )
endif()

if( APPLE )
		SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++" )
endif()

set( CMAKE-GLFW-STARTER-SRC
     main.cpp
     )
	 
add_executable( CMake-GLFW-starter ${CMAKE-GLFW-STARTER-SRC} )
target_link_libraries( CMake-GLFW-starter ${OPENGL_LIBRARIES} glfw ${GLFW_LIBRARIES} )