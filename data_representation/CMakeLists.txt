cmake_minimum_required(VERSION 3.0.0)
project(data_structure VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)
find_package(Threads REQUIRED)
include(CTest)
enable_testing()

add_executable(list src/list.cpp)
target_link_libraries(list Threads::Threads)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
