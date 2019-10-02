#include <vector>

#ifndef BINARYHEAP_H
#define BINARYHEAP_H 1

class BinaryHeap
{
public:
  BinaryHeap();
  BinaryHeap(std::vector<int> values);

  std::vector<int> elements;

  int extractMax();
  std::vector<int> *heapSort();
  void insert(int value);
};

#endif