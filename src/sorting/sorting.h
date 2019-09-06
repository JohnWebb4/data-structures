#include <stdio.h>
#include <vector>

#ifndef SORTING_H

#define SORTING_H 1

std::vector<int> bubbleSort(std::vector<int> vector);

std::vector<int> selectionSort(std::vector<int> vector);

std::vector<int> insertionSort(std::vector<int> vector);

std::vector<int> mergeSort(std::vector<int> &vector, int low, int high);

#endif
