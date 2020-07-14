cmake_minimum_required(VERSION 3.5)
project(linked_list_lib)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(
    HEADER_FILES
    list_element.h
    linked_list.h
)

set(
    SOURCE_FILES
    linked_list.cc
)

add_library(linked_list_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})