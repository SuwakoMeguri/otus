cmake_minimum_required(VERSION 3.29)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 1.1.${PATCH_VERSION})
project(ip-filter VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT hisoutensoku@suwako.ryukyu)

include_directories(src)

add_library(idk src/ip_filter.cpp)

add_executable(ip-filter src/main.cpp)

target_link_libraries(ip-filter idk)

include(CPack)

#### TESTS ##########################################
enable_testing()

add_executable(ip_filter_test test/ip_filter_test.cpp)
target_link_libraries(ip_filter_test PRIVATE gtest)
target_link_libraries(ip_filter_test PRIVATE idk)

include(GoogleTest)
gtest_discover_tests(ip_filter_test)
