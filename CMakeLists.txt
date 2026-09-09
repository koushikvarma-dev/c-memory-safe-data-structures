cmake_minimum_required(VERSION 3.16)
project(c_memory_safe_data_structures C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(data_structures src/data_structures.c)
target_include_directories(data_structures PUBLIC include)
target_compile_options(data_structures PRIVATE -Wall -Wextra -Wpedantic)

add_executable(test_data_structures tests/test_data_structures.c)
target_link_libraries(test_data_structures PRIVATE data_structures)

enable_testing()
add_test(NAME data_structures_tests COMMAND test_data_structures)
