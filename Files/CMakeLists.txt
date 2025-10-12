#THE FILES CONTAIN ATTEMPTS AT INCORPORATING PLPLOT, BUT FOR SOME REASON IT DOESN'T WORK.


cmake_minimum_required(VERSION 3.21)
project(Files_Homework C)
# Point CMake at the active Conda environment automatically, if any.
if(DEFINED ENV{CONDA_PREFIX})
  list(APPEND CMAKE_PREFIX_PATH "$ENV{CONDA_PREFIX}")
  if(NOT PLplot_DIR AND EXISTS "$ENV{CONDA_PREFIX}/lib/cmake/plplot")
    set(PLplot_DIR "$ENV{CONDA_PREFIX}/lib/cmake/plplot" CACHE PATH "Path to Conda PLplot configuration")
  endif()
endif()

find_package(PLplot REQUIRED)
#include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(src)
include_directories(${PROJECT_SOURCE_DIR}/third_party)
#enable_testing()
#add_subdirectory(tests)
