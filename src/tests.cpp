#include "./binaryHeap/binaryHeap.test.cpp"
#include "./binarySearchTree/binarySearchTree.test.cpp"
#include "./bitmask/bitmask.test.cpp"
#include "./disjointedSets/disjointedSets.test.cpp"
#include "./graph/graph.test.cpp"
#include "./hashMap/hashMap.test.cpp"
#include "./linkedList/linkedList.test.cpp"
#include "./sorting/sorting.test.cpp"

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
