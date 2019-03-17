cmake_minimum_required(VERSION 3.10)
project(merge_sort LANGUAGES CXX)
enable_testing()

add_library(mergesort INTERFACE)
target_include_directories(mergesort
  INTERFACE
    .
)
target_compile_features(mergesort
  INTERFACE
    cxx_std_14
)

find_package(Catch2 REQUIRED)
add_executable(main_test
  catch_main.cc
)
target_link_libraries(main_test
  PRIVATE
    Catch2::Catch2
    mergesort
)
add_test(main_test main_test)