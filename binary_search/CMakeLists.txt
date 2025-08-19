cmake_minimum_required(VERSION 3.10.0)
project(data_structure VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)
find_package(Threads REQUIRED)
include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -ggdb")

# Set default build type to Debug if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

add_executable(find-kth-smallest-pair src/719-find-kth-smallest-pair-distance.cpp)
add_executable(find-minimum src/154-find-minimum-in-rotated-sorted-array.cpp)
add_executable(median-sorted src/4-median-of-two-sorted-array.cpp)
add_executable(max-sum src/363-max-sum-rectangle-no-larger-than-k.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
