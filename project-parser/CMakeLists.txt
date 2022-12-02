set( target_name project-parser )

# I know. But it's appropriate to glob for now.
file(GLOB_RECURSE src_cpp ./src/*.c)
file(GLOB_RECURSE src_h ./src/*.h)
file(GLOB_RECURSE inc_h ./${target_name}/*.h ./${target_name}/*.hpp)

add_library(${target_name} ${src_cpp} ${src_h} ${inc_h})
set_target_properties(${target_name} PROPERTIES
  LINKER_LANGUAGE C
)
#set_property(TARGET ${target_name} PROPERTY CXX_STANDARD 17)
target_compile_definitions(${target_name} PRIVATE
  BUILDING_APPP
)
target_link_libraries(${target_name} PUBLIC
  toml
  yaml
)
target_include_directories(${target_name} PRIVATE
  src
)
target_include_directories(${target_name} PUBLIC
  .
)


# Install commands
install(
  FILES ${inc_h}
  DESTINATION ${target_name} COMPONENT Development
)
