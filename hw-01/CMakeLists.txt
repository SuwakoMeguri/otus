cmake_minimum_required(VERSION 3.10)
project(helloworld_cli)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.1.${PATCH_VERSION})
configure_file(src/version.h.in src/version.h)

add_library(lib.h)
add_executable(helloworld_cli src/helloworld.cpp)
install(TARGETS helloworld_cli RUNTIME DESTINATION bin)
include(CPack)
