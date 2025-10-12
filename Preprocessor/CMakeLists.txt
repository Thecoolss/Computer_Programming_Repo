cmake_minimum_required(VERSION 3.10)
project(WelcomeProject C)

# Create welcome library with language definition
add_library(welcome src/welcome.c)
target_include_directories(welcome PUBLIC include)


# Create main executable
add_executable(main src/main.c)
target_link_libraries(main welcome)


enable_testing()

# Add tests
add_executable(test_welcome tests/welcome_tests.c)
target_link_libraries(test_welcome welcome)
add_test(NAME welcome_test COMMAND test_welcome)