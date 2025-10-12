find_package(PLplot REQUIRED)

add_executable(fial fial.c plot.c)
target_include_directories(fial PRIVATE ${PLPLOT_INCLUDE_DIRS})
target_link_libraries(fial PRIVATE ${PLPLOT_LIBRARIES})
