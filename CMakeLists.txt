cmake_minimum_required (VERSION 3.24)
project (adventofcode2022)

set (CMAKE_CXX_STANDARD 23)

# Include cmake scripts
include(cmake/configurations.cmake)
include(cmake/warnings.cmake)
include(cmake/conan.cmake)


# Set up Conan dependencies
# To find packages:
#    - https://conan.io/center/
set(CONAN_EXTRA_REQUIRES "")
set(CONAN_EXTRA_OPTIONS "")
set(CONAN_EXTRA_REQUIRES ${CONAN_EXTRA_REQUIRES}
   gtest/1.12.1
   )
run_conan()

# Set output directory of all projects to be somewhere sensible
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RESOURCE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/res)

# Copy resources
file(GLOB RESOURCE_INPUT_FILES "./res/*")
file(COPY ${RESOURCE_INPUT_FILES} DESTINATION ${CMAKE_RESOURCE_OUTPUT_DIRECTORY})

# additional include directories
include_directories(3rdparty/mzlib/include)

add_executable (adventofcode2022 main.cpp)
