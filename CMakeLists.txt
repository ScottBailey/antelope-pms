cmake_minimum_required(VERSION 3.11)

project("Antelope Project Management System")

# Add some common stuff.
include( ./common.cmake REQUIRED )

# Add dependent libraries.
add_subdirectory( depends )


add_subdirectory( common )
add_subdirectory( c )
add_subdirectory( cpp )
