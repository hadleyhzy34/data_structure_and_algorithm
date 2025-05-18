cmake_minimum_required(VERSION 3.10.0)
project(pq VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
find_package(Threads REQUIRED)
include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -ggdb")

# Set default build type to Debug if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

# Add executable target
add_executable(pq-customized src/pq_customized.cpp)
