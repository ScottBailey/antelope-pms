
set(TOML_LIB_GIT_HASH 894902820a3ea2f1ec470cd7fe338bde54045cf5)

ExternalProject_Add(toml_lib

  DOWNLOAD_NAME tomlc99-${TOML_LIB_GIT_HASH}.tar.gz
  URL      https://github.com/cktan/tomlc99/archive/${TOML_LIB_GIT_HASH}.tar.gz
  URL_HASH SHA256=3ae1970c4f2d03ac16f8616963dfa6d1fac38883408f76fefbecfc1d8f61e570

  #DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}
  UPDATE_COMMAND ""
  SOURCE_DIR ${toml_lib_SOURCE_DIR}
  BUILD_IN_SOURCE 1
  CONFIGURE_COMMAND ""
  BUILD_COMMAND "make -j4"
#  INSTALL_COMMAND "${make_lib_install_commands}"
)

#add_library(toml_lib_libA STATIC IMPORTED GLOBAL)
#set_property(TARGET toml_lib_libA
#    PROPERTY IMPORTED_LOCATION
#    ${toml_lib_SOURCE_DIR}/path/to/make_lib_libA.a
#)

#add_dependencies(myOtherLib make_lib)
