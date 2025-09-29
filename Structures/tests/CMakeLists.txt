add_executable(test_struct struct_test.c)
target_link_libraries(test_struct PRIVATE rectangle)
target_include_directories(test_struct PRIVATE ${PROJECT_SOURCE_DIR}/third_party)
add_test(NAME test_struct COMMAND test_struct)
