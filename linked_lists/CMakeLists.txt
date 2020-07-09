cmake_minimum_required(VERSION 3.5)
project(linked_lists_proj)

add_definitions(-std=c++11)
add_definitions(-Werror)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(SOURCE_FILES main.cpp)
add_executable(linked_lists_run ${SOURCE_FILES})

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(linked_lists_run linked_list_lib)