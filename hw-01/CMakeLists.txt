cmake_minimum_required(VERSION 3.10)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.1.${PATCH_VERSION})
project(helloworld VERSION ${PROJECT_VERSION})

configure_file(version.h.in version.h)
add_library(helloworld lib.cpp)
add_executable(helloworld_cli helloworld.cpp)

target_include_directories(
  helloworld
  PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(helloworld_cli PRIVATE
    helloworld
)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)
include(CPack)
