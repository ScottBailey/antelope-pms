
set(TOML_LIB_GIT_HASH 894902820a3ea2f1ec470cd7fe338bde54045cf5)

ExternalProject_Add(toml_lib_ep

  DOWNLOAD_NAME tomlc99-${TOML_LIB_GIT_HASH}.tar.gz
  URL      https://github.com/cktan/tomlc99/archive/${TOML_LIB_GIT_HASH}.tar.gz
  URL_HASH SHA256=3ae1970c4f2d03ac16f8616963dfa6d1fac38883408f76fefbecfc1d8f61e570

  #DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}
  UPDATE_COMMAND ""
  SOURCE_DIR ${toml_lib_ep_SOURCE_DIR}
  BUILD_IN_SOURCE 1
  CONFIGURE_COMMAND ""
  BUILD_COMMAND "make"
  INSTALL_COMMAND ""
  #INSTALL_COMMAND "${toml_lib_install_commands}"
  #INSTALL_COMMAND "${toml_lib_ep_install_commands}"
)

message( "=> ${toml_lib_ep_SOURCE_DIR}")

#add_library(toml_lib STATIC IMPORTED GLOBAL)
#set_property(TARGET toml_lib
#    PROPERTY IMPORTED_LOCATION
#    ${toml_lib_ep_SOURCE_DIR}/libtoml.a
#)

#add_dependencies(myOtherLib make_lib)
