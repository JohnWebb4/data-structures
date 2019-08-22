#include <gtest/gtest.h>
#include <vector>

#include "./sorting/sorting.h"

TEST(SortingBubbleTest1, Test)
{
  std::vector<int> vector{2, 3, 4, 1};

  std::vector<int> sortedVector{ 1, 2, 3, 4};

  ASSERT_EQ(sortedVector, bubbleSort(vector));
}
