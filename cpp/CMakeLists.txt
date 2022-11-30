set( target_name driver_cpp)


# I know. But it's appropriate for now.
file(GLOB_RECURSE src_cpp ./*.cpp)
file(GLOB_RECURSE src_h ./*.h)

add_executable(${target_name} ${src_cpp} ${src_h})
set_property(TARGET ${target_name} PROPERTY CXX_STANDARD 17)
target_link_libraries(${target_name}
  AntelopeCommon
)
