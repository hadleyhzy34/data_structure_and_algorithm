cmake_minimum_required(VERSION 3.10)
project(expression_add_operators)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(expression_add_operators 
    src/282-expression-add-operators.cpp
)

# Add include directories if needed
target_include_directories(expression_add_operators
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Set compiler flags
if(MSVC)
    target_compile_options(expression_add_operators PRIVATE /W4)
else()
    target_compile_options(expression_add_operators PRIVATE -Wall -Wextra)
endif()