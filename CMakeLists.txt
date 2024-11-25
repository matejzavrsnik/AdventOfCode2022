cmake_minimum_required (VERSION 3.24)
set(CMAKE_VERBOSE_MAKEFILE ON)
project (recreational)
set (CMAKE_CXX_STANDARD 23)

# Set output directory of all projects to be somewhere sensible
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RESOURCE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/res)


# Copy resources
file(GLOB RESOURCE_INPUT_FILES "adventofcode2022/input/*")
file(COPY ${RESOURCE_INPUT_FILES} DESTINATION ${CMAKE_RESOURCE_OUTPUT_DIRECTORY}/adventofcode2022 )
file(GLOB RESOURCE_INPUT_FILES "adventofcode2021/input/*")
file(COPY ${RESOURCE_INPUT_FILES} DESTINATION ${CMAKE_RESOURCE_OUTPUT_DIRECTORY}/adventofcode2021 )
file(GLOB RESOURCE_INPUT_FILES "aoc23/*.txt")
file(COPY ${RESOURCE_INPUT_FILES} DESTINATION ${CMAKE_RESOURCE_OUTPUT_DIRECTORY}/aoc23 )
file(GLOB RESOURCE_INPUT_FILES "aoc24/*.txt")
file(COPY ${RESOURCE_INPUT_FILES} DESTINATION ${CMAKE_RESOURCE_OUTPUT_DIRECTORY}/aoc24 )

# additional include directories
include_directories(
   3rdparty/mzlib/include
   )

file(GLOB TEST_FILES
   reusables/*
   adventofcode2021/tests/*
   adventofcode2022/tests/*
   aoc23/*.cpp
   aoc24/*.cpp
   )

add_executable (recreational
   main.cpp
   ${TEST_FILES}
   )

# First, tell CMake to find the package.
# Conan will install the packages so that CMake can find it:
find_package(GTest)
find_package(range-v3)
find_package(absl)

# Link with libraries
target_link_libraries(recreational
   gtest::gtest
   range-v3::range-v3
   abseil::abseil
)
