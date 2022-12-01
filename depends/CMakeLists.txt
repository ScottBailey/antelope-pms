
include(FetchContent)
include(ExternalProject)

# Set timestamp policy to EXTRACTION time instead of archive time.
cmake_policy(SET CMP0135 NEW)

include(./yaml.cmake REQUIRED)
include(./toml-fc.cmake REQUIRED)
