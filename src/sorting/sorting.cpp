#include "./sorting.h"

// Sort array using bubble sort
// Size Complexity: O(1)
// Time Complexity: O(n^2)
std::vector<int> bubbleSort(std::vector<int> vector) {
  const unsigned int size = vector.size();
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

// Sort array using selection sort
// Size Complexity: O(1)
// Time Complexity: O(n^2)
std::vector<int> selectionSort(std::vector<int> vector) {
  const unsigned int size = vector.size();
  int smallestIndex;

  for (unsigned int i = 0; i < size; i++) {
    smallestIndex = i;

    // Find smallest element
    for (unsigned int j = i; j < size; j++) {
      if (vector[j] < vector[smallestIndex]) {
        smallestIndex = j;
      }
    }

    // Swap with nth element
    int temp = vector[i];
    vector[i] = vector[smallestIndex];
    vector[smallestIndex] = temp;
  }

  return vector;
}

std::vector<int> insertionSort(std::vector<int> vector) {
  std::vector<int> sorted{vector[0]};

  for (unsigned int i = 1; i < vector.size(); i++) {
    for (unsigned int j = 0; j < sorted.size(); j++) {
      if (vector[i] < sorted[j]) {
        sorted.insert(sorted.begin() + j, vector[i]);
        break;
      } else if (j == sorted.size() - 1) {
        // If reached end array, insert at end
        sorted.push_back(vector[i]);
        break;
      }
    }
  }

  return sorted;
}