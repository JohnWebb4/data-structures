#include <gtest/gtest.h>

#include "./bitmask/bitmask.h"

TEST(BitmaskTest, SetBit)
{
  ASSERT_EQ(3, setBit(2, 0));
}

TEST(BitmaskTest, CheckBit)
{
  ASSERT_EQ(true, checkBit(3, 1));
}

TEST(BitmaskTest, ToggleBit)
{
  ASSERT_EQ(7, toggleBit(5, 1));
  ASSERT_EQ(5, toggleBit(7, 1));
}

TEST(BitmaskTest, ClearBit)
{
  ASSERT_EQ(8, clearBit(8, 1));
  ASSERT_EQ(1, clearBit(3, 1));
}

TEST(BitmaskTest, LeastSignificant)
{
  ASSERT_EQ(2, leastSignificantBit(2));
  ASSERT_EQ(1, leastSignificantBit(5));
}