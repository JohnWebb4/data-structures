#include <gtest/gtest.h>
#include <vector>

#include "./sorting/sorting.h"

TEST(SortingBubbleTest1, Test)
{
  std::vector<int> vector{2, 3, 4, 1};
  std::vector<int> sorted{1, 2, 3, 4};

  ASSERT_EQ(sorted, bubbleSort(vector));
}

TEST(SortingSelectionTest1, Test)
{
  std::vector<int> vector{2, 3, 4, 1};
  std::vector<int> sorted{1, 2, 3, 4};

  ASSERT_EQ(sorted, selectionSort(vector));
}

TEST(SortingInsertionTest1, Test)
{
  std::vector<int> vector{2, 3, 4, 1};
  std::vector<int> sorted{1, 2, 3, 4};

  ASSERT_EQ(sorted, insertionSort(vector));
}

TEST(SortingMergeTest1, Test)
{
  std::vector<int> vector{5, 6, 7, 8, 2, 3, 4, 1};
  std::vector<int> sorted{1, 2, 3, 4, 5, 6, 7, 8};

  ASSERT_EQ(sorted, mergeSort(vector, 0, vector.size() - 1));
}

TEST(SortingQuickTest1, Test)
{
  std::vector<int> vector{2, 3, 4, 1, 5, 8, 6, 7};
  std::vector<int> sorted{1, 2, 3, 4, 5, 6, 7, 8};

  ASSERT_EQ(sorted, quickSort(vector, 0, vector.size() - 1));
}