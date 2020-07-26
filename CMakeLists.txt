cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 11)
project("data_structures")

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE 
  ./src/binaryHeap/binaryHeap.cpp
  ./src/binarySearchTree/binarySearchTree.cpp
  ./src/bitmask/bitmask.cpp
  ./src/graph/graph.cpp
  ./src/graph/graphEdge.cpp
  ./src/graph/graphNode.cpp
  ./src/hashMap/hashMap.cpp
  ./src/linkedList/linkedList.cpp
  ./src/sorting/sorting.cpp
  ./src/tests.cpp
)

# Link tests
add_executable(runTests ${SOURCE})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

target_include_directories(runTests PUBLIC src/)
