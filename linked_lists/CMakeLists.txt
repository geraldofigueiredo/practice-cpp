cmake_minimum_required(VERSION 3.5)
project(linked_lists_proj)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_definitions(-Werror)

set(SOURCE_FILES main.cpp)
add_executable(linked_lists_run ${SOURCE_FILES})

include_directories(src)

add_subdirectory(src)
# add_subdirectory(tests)

target_link_libraries(linked_lists_run linked_list_lib)