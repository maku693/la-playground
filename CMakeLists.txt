cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project("linmath")
enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED)
set(CMAKE_CXX_EXTENSIONS OFF)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}
  )

file(GLOB_RECURSE TEST_SOURCE_FILES "tests/*.cpp")
add_executable("tests" ${TEST_SOURCE_FILES})
