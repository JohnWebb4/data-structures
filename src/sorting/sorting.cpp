#include "./sorting.h"

// Sort the array using bubble sort
// Size Complexity: O(1)
// Time Complexity: O(n^2)
std::vector<int> bubbleSort(std::vector<int> vector) {
  unsigned int size = vector.size();
  bool hasSorted;

  while(hasSorted) {
    hasSorted = false;

    for (unsigned int i = 0; i < size; i++) {
      if (i + 1 < size) {
        if (vector[i] > vector[i + 1]) {

          int temp = vector[i];
          vector[i] = vector[i + 1];
          vector[i + 1] = temp;
          hasSorted = true;
        }
      }
    }
  }

  return vector;
}