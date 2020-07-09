project(linked_lists_tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(linked_list_tests linked_list_test.cpp)

target_link_libraries(linked_list_tests gtest gtest_main)
target_link_libraries(linked_list_tests linked_list_lib)