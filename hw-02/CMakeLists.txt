cmake_minimum_required(VERSION 3.29)

project(ip-filter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

add_library(idk src/ip_filter.cpp)

add_executable(ip-filter src/main.cpp)

target_link_libraries(ip-filter idk)

include(CPack)

## Google tests stuff
enable_testing()

#### TESTS ##########################################
add_executable(ip_filter_test test/ip_filter_test.cpp)
target_link_libraries(ip_filter_test PRIVATE gtest)
target_link_libraries(ip_filter_test PRIVATE idk)

include(GoogleTest)
gtest_discover_tests(ip_filter_test)
