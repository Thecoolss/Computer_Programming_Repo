add_library(rectangle rectangle.c)
add_executable(main main.c)
target_link_libraries(main PRIVATE rectangle)
include_directories(${PROJECT_SOURCE_DIR}/include)
