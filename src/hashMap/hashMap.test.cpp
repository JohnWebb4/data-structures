#include <gtest/gtest.h>

#include "./hashMap.h"

TEST(HashMapGet1, Test)
{
  HashMap hashMap(10);

  hashMap.set("1", 1);
  hashMap.set("Test", 2);

  ASSERT_EQ(-1, hashMap.get("0"));
  ASSERT_EQ(1, hashMap.get("1"));
  ASSERT_EQ(2, hashMap.get("Test"));
}