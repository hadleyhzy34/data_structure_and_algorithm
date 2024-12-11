cmake_minimum_required(VERSION 3.10.0)
project(data_structure VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)
find_package(Threads REQUIRED)
include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -ggdb")

# add_library(palindrome src/131-palindrome-partitioning.cpp)
# add_library(boundaryCheck src/576-out-of-boundary-paths.cpp)

# add_executable(main main.cpp)
# target_link_libraries(main palindrome boundaryCheck)

# add_executable(expression src/10-regular-expression-matching.cpp)
# add_executable(wildcard_matching src/44-wildcard-matching.cpp)
# add_executable(divisible_subset src/368-largest-divisible-subset.cpp)
# add_executable(burst_balloon src/312-burst-balloons-II.cpp)
add_executable(count_unique_digits src/357-count-numbers-with-unique-digits.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
