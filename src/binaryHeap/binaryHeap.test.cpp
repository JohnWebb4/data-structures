#include <gtest/gtest.h>

#include "./binaryHeap.h"

TEST(BinaryHeapTest, Create)
{
  BinaryHeap binaryHeap({1, 2, 3});

  ASSERT_EQ(3, binaryHeap.elements.at(0));
  ASSERT_EQ(1, binaryHeap.elements.at(1));
  ASSERT_EQ(2, binaryHeap.elements.at(2));
}

TEST(BinaryHeapTest, Insert)
{
  BinaryHeap binaryHeap;

  binaryHeap.insert(1);
  binaryHeap.insert(2);
  binaryHeap.insert(3);
  binaryHeap.insert(4);
  binaryHeap.insert(5);
  binaryHeap.insert(6);
  binaryHeap.insert(7);
  binaryHeap.insert(8);

  ASSERT_EQ(8, binaryHeap.elements.at(0));
  ASSERT_EQ(7, binaryHeap.elements.at(1));
  ASSERT_EQ(6, binaryHeap.elements.at(2));
  ASSERT_EQ(4, binaryHeap.elements.at(3));
  ASSERT_EQ(3, binaryHeap.elements.at(4));
  ASSERT_EQ(2, binaryHeap.elements.at(5));
  ASSERT_EQ(5, binaryHeap.elements.at(6));
  ASSERT_EQ(1, binaryHeap.elements.at(7));
}

TEST(BinaryHeapTest, ExtractMax)
{
  BinaryHeap binaryHeap({1, 2, 3, 4, 5});

  ASSERT_EQ(5, binaryHeap.extractMax());
  ASSERT_EQ(4, binaryHeap.extractMax());
  ASSERT_EQ(3, binaryHeap.extractMax());
  ASSERT_EQ(2, binaryHeap.extractMax());
  ASSERT_EQ(1, binaryHeap.extractMax());
  ASSERT_THROW((void)binaryHeap.extractMax(), std::out_of_range);
}

TEST(BinaryHeapTest, HeapSort)
{
  BinaryHeap binaryHeap({1, 2, 3, 4, 5});
  std::vector<int> expected = {5, 4, 3, 2, 1};
  std::vector<int> *result = binaryHeap.heapSort();

  ASSERT_EQ(expected, *result);
  delete result;
}