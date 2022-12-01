set( target_name apack-cpp)

# I know. But it's appropriate for now.
file(GLOB_RECURSE src_cpp ./src/*.cpp)
file(GLOB_RECURSE src_h ./src/*.h)
file(GLOB_RECURSE inc_h ./apack-cpp/*.h)

add_library(${target_name} ${src_cpp} ${src_h} ${inc_h})
set_property(TARGET ${target_name} PROPERTY CXX_STANDARD 17)
target_link_libraries(${target_name} PUBLIC
  apack-c
)
target_include_directories(${target_name} PRIVATE
  src
)
target_include_directories(${target_name} PUBLIC
  include
)


# Install commands
install(
  FILES ${inc_h}
  DESTINATION apack-cpp COMPONENT Development
)
