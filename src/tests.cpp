#include "./bitmask/bitmask.test.cpp"
#include "./linkedList/linkedList.test.cpp"
#include "./sorting/sorting.test.cpp"

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
