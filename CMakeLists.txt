cmake_minimum_required(VERSION 3.11)

project("Antelope Project Management System")

# Add some common stuff.
include( ./common.cmake REQUIRED )

# Add dependent libraries.
add_subdirectory( depends )


add_subdirectory( apack-c )
add_subdirectory( apack-cpp )
add_subdirectory( project-parser )


option(BUILD_TESTS "Build and run the tests." On)
if(BUILD_TESTS)
  enable_testing()
  add_subdirectory( test )
endif()
