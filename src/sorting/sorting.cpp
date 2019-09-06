#include <cmath>
#include "./sorting.h"

// Sort array using bubble sort
// Size Complexity: O(1)
// Time Complexity: O(n^2)
std::vector<int> bubbleSort(std::vector<int> vector)
{
  const unsigned int size = vector.size();
  bool hasSorted = true;

  while (hasSorted)
  {
    hasSorted = false;

    for (unsigned int i = 0; i < size - 1; i++)
    {
        if (vector.at(i) > vector.at(i + 1))
        {
          int temp = vector.at(i);
          vector[i] = vector.at(i + 1);
          vector[i + 1] = temp;
          hasSorted = true;
        }
    }
  }

  return vector;
}

// Sort array using selection sort
// Size Complexity: O(1)
// Time Complexity: O(n^2)
std::vector<int> selectionSort(std::vector<int> vector)
{
  const unsigned int size = vector.size();
  int smallestIndex;

  for (unsigned int i = 0; i < size; i++)
  {
    smallestIndex = i;

    // Find smallest element
    for (unsigned int j = i; j < size; j++)
    {
      if (vector.at(j) < vector.at(smallestIndex))
      {
        smallestIndex = j;
      }
    }

    // Swap with nth element
    int temp = vector.at(i);
    vector[i] = vector.at(smallestIndex);
    vector[smallestIndex] = temp;
  }

  return vector;
}

// Sort array using insertion sort
// Size Complexity: O(1)
// Time Complexity: O(N^2)
std::vector<int> insertionSort(std::vector<int> vector)
{
  for (unsigned int i = 1; i < vector.size(); i++)
  {
    int element = vector.at(i);
    int j = i - 1;

    for (; j >= 0 && vector.at(j) > element; j--)
    {
      vector[j + 1] = vector.at(j);
    }

    vector[j + 1] = element;
  }

  return vector;
}

std::vector<int> merge(std::vector<int> &vector, int low, int middle, int high)
{
  std::vector<int> temp;
  int left = low;
  int right = middle + 1;

  while (left <= middle && right <= high)
  {
    if (vector.at(left) > vector.at(right))
    {
      temp.push_back(vector.at(right++));
    }
    else
    {
      temp.push_back(vector.at(left++));
    }
  }

  while (left <= middle)
  {
    temp.push_back(vector.at(left++));
  }

  while (right <= high)
  {
    temp.push_back(vector.at(right++));
  }

  // copy back
  for (unsigned int i = 0; i < temp.size(); i++)
  {
    vector[i + low] = temp.at(i);
  }

  return vector;
}

// Sort array using merge sort
// Size Complexity: O(N)
// Time Complexity: O(N log (N))
std::vector<int> mergeSort(std::vector<int> &vector, int low, int high)
{
  if (low < high)
  {
    int middle = (low + high) / 2;

    mergeSort(vector, low, middle);
    mergeSort(vector, middle + 1, high);
    merge(vector, low, middle, high);
  }

  return vector;
}
