add_executable(test_length test_length.c)
target_link_libraries(test_length name_length)
# Make sure the test can find the headers
target_include_directories(test_length PRIVATE ${PROJECT_SOURCE_DIR}/third_party)
add_test(NAME test_length COMMAND test_length)
