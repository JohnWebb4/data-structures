#include <gtest/gtest.h>

#include "./sorting/sorting.h"

TEST(SortingBubbleTest1, Test)
{
  int arr[] = { 2, 3, 4, 1};
  std::vector<int> vector(arr, arr + sizeof(arr) / sizeof(arr[0]));

  int sortedArr[] = { 1, 2, 3, 4};
  std::vector<int> sorted(sortedArr, sortedArr + sizeof(sortedArr) / sizeof(sortedArr[0]));

  ASSERT_EQ(sorted, bubble(vector));
}
