cmake_minimum_required(VERSION 3.0.0)
project(data_structure VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)
find_package(Threads REQUIRED)
include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -ggdb")

add_library(palindrome src/131-palindrome-partitioning.cpp)
add_library(boundaryCheck src/576-out-of-boundary-paths.cpp)

add_executable(main main.cpp)
target_link_libraries(main palindrome boundaryCheck)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
