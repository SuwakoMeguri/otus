cmake_minimum_required(VERSION 3.29)

project(ip_filter)

add_executable(IPFilter ip_filter.cpp)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_CONTACT hisoutensoku@suwako.ryukyu)

include(CPack)

