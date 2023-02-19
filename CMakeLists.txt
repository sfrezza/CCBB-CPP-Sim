cmake_minimum_required(VERSION 3.16)
project(ccbb)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
