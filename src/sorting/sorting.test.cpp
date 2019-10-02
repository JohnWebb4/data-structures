#include <gtest/gtest.h>
#include <vector>

#include "./sorting/sorting.h"

TEST(SortingTest, BubbleSort)
{
  std::vector<int> vector{2, 3, 4, 1};
  std::vector<int> sorted{1, 2, 3, 4};

  ASSERT_EQ(sorted, bubbleSort(vector));
}

TEST(SortingTest, SelectionSort)
{
  std::vector<int> vector{2, 3, 4, 1};
  std::vector<int> sorted{1, 2, 3, 4};

  ASSERT_EQ(sorted, selectionSort(vector));
}

TEST(SortingTest, InsertionSort)
{
  std::vector<int> vector{2, 3, 4, 1};
  std::vector<int> sorted{1, 2, 3, 4};

  ASSERT_EQ(sorted, insertionSort(vector));
}

TEST(SortingTest, MergeSort)
{
  std::vector<int> vector{5, 6, 7, 8, 2, 3, 4, 1};
  std::vector<int> sorted{1, 2, 3, 4, 5, 6, 7, 8};

  ASSERT_EQ(sorted, mergeSort(vector, 0, vector.size() - 1));
}

TEST(SortingTest, QuickSort)
{
  std::vector<int> vector{2, 3, 4, 1, 5, 8, 6, 7};
  std::vector<int> sorted{1, 2, 3, 4, 5, 6, 7, 8};

  ASSERT_EQ(sorted, quickSort(vector, 0, vector.size() - 1));
}