#include <cmath>

#include "./bitmask.h"

int setBit(int number, unsigned int index)
{
  return number | (int)std::pow(2, index);
}

bool checkBit(int number, unsigned int index)
{
  return number & (int)std::pow(2, index);
}

int toggleBit(int number, unsigned int index)
{
  return number ^ (int)std::pow(2, index);
}

int clearBit(int number, unsigned int index)
{
  return number & ~(int)(std::pow(2, index));
}

int leastSignificantBit(int number)
{
  return number & (~number + 1);
}