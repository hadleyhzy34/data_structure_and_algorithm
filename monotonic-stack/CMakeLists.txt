cmake_minimum_required(VERSION 3.10.0)
project(monotonic-stack VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)
find_package(Threads REQUIRED)
include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -ggdb")

# Set default build type to Debug if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

# add_executable(csn src/315-count-smaller-numbers.cpp)
# add_executable(reverse-pairs src/493-reverse-pairs.cpp)
add_executable(trap-in-waters src/42-trapping-rain-water.cpp)
add_executable(pattern-132 src/456-132-pattern.cpp)
add_executable(remove-k-digits src/402-remove-k-digits.cpp)
add_executable(remove-duplicate-letter src/316-remove-duplicate-letters.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
