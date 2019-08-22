cmake_minimum_required(VERSION 3.10)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE 
  ./src/tests.cpp
  ./src/sorting/sorting.cpp
)

# Link tests
add_executable(runTests ${SOURCE})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

target_include_directories(runTests PUBLIC src/)