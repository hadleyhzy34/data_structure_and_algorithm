cmake_minimum_required(VERSION 3.0.0)
project(data_structure VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)
find_package(Threads REQUIRED)
include(CTest)
enable_testing()

add_executable(kmp src/kmp.cpp)
target_link_libraries(kmp Threads::Threads)

add_library(is_subsequence src/392-is_subsequence.cpp)

add_executable(main main.cpp)
target_link_libraries(main is_subsequence)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
