cmake_minimum_required(VERSION 3.10)
project(merge_sort LANGUAGES CXX)

find_package(Catch2 REQUIRED)
enable_testing()

add_library(mergesort mergesort.cc)

add_executable(main_test catch_main.cc)


target_link_libraries(main_test PRIVATE Catch2::Catch2 mergesort)


add_test(main_test main_test)
include(Catch)
catch_discover_tests(main_test)
