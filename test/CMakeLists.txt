include(CTest)

# I know. But it's appropriate for now.
file(GLOB_RECURSE src_cpp ./*.c ./*.cpp)

foreach(file_name IN ITEMS ${src_cpp})
  cmake_path(GET file_name FILENAME temp1)
  string(REPLACE ".c" "" temp2 ${temp1})
  string(REPLACE ".cpp" "" name ${temp2})
  set(name "test-${name}")

  add_executable(${name} ${file_name})
  target_link_libraries(${name} project-parser)
  add_test(NAME ${name} COMMAND ${name})
endforeach()
