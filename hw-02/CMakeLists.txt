cmake_minimum_required(VERSION 3.29)

project(ip_filter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ip_filter ip_filter.cpp)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_CONTACT hisoutensoku@suwako.ryukyu)

include(CPack)


## Google tests stuff
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(ip_filter_test ip_filter_test.cpp)
target_link_libraries(ip_filter_test GTest::gtest_main ip_filter)

include(GoogleTest)
gtest_discover_tests(ip_filter_test)
