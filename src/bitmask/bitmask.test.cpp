#include <gtest/gtest.h>

#include "./bitmask/bitmask.h"

TEST(BitmaskSetBit1, Test)
{
  ASSERT_EQ(3, setBit(2, 0));
}

TEST(BitmaskCheckBit1, Test)
{
  ASSERT_EQ(true, checkBit(3, 1));
}

TEST(BitmaskToggleBit1, Test)
{
  ASSERT_EQ(7, toggleBit(5, 1));
}

TEST(BitmaskToggleBit2, Test)
{
  ASSERT_EQ(5, toggleBit(7, 1));
}

TEST(BitmaskClearBit1, Test)
{
  ASSERT_EQ(8, clearBit(8, 1));
}

TEST(BitmaskClearBit2, Test)
{
  ASSERT_EQ(1, clearBit(3, 1));
}

TEST(BitmaskLeastSignificant1, Test)
{
  ASSERT_EQ(2, leastSignificantBit(2));
}

TEST(BitmaskLeastSignificant2, Test)
{
  ASSERT_EQ(1, leastSignificantBit(5));
}