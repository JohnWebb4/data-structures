#include <stdexcept>
#include <vector>

#include "./binaryHeap.h"

BinaryHeap::BinaryHeap() : elements()
{
}

BinaryHeap::BinaryHeap(std::vector<int> values) : elements()
{
  for (int value : values)
  {
    this->insert(value);
  }
}

void BinaryHeap::insert(int value)
{
  this->elements.push_back(value);

  for (int index = this->elements.size(); index > 1; index = index >> 1)
  {
    int parentIndex = index >> 1;

    if (value > this->elements[parentIndex - 1])
    {
      std::swap(this->elements[index - 1], this->elements[parentIndex - 1]);
    }
  }
}

int BinaryHeap::extractMax()
{
  int size = this->elements.size();

  if (size <= 0)
  {
    throw std::out_of_range("There are no elements in the heap");
  }

  for (int index = 1; index < size;)
  {
    int leftIndex = index << 1;
    int rightIndex = (index << 1) + 1;

    if (leftIndex <= size && rightIndex <= size)
    {
      if (this->elements.at(leftIndex - 1) > this->elements.at(rightIndex - 1))
      {
        // Swap left
        std::swap(this->elements[index - 1], this->elements[leftIndex - 1]);
        index = leftIndex;
      }
      else if (rightIndex <= size)
      {
        // Swap right
        std::swap(this->elements[index - 1], this->elements[rightIndex - 1]);
        index = rightIndex;
      }
    }
    else if (leftIndex <= size)
    {
      // Swap left
      std::swap(this->elements[index - 1], this->elements[leftIndex - 1]);
      index = leftIndex;
    }
    else if (rightIndex <= size)
    {
      // Swap right
      std::swap(this->elements[index - 1], this->elements[rightIndex - 1]);
      index = rightIndex;
    }
    else
    {
      break;
    }
  }

  int max = this->elements.at(size - 1);
  this->elements.pop_back();
  return max;
}

std::vector<int> *BinaryHeap::heapSort()
{
  std::vector<int> *sorted = new std::vector<int>();

  while (this->elements.size() > 0)
  {
    sorted->push_back(this->extractMax());
  }

  return sorted;
}
