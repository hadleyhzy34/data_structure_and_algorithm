cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SortArrayTest)

# Add the executable
add_executable(SortArrayTest src/912-merge-sort.cpp)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)