#include <gtest/gtest.h>

#include "./linkedList/linkedList.h"

TEST(LinkedListCreate1, Test)
{
  LinkedList list(1, nullptr);

  ASSERT_EQ(1, list.value);
  ASSERT_EQ(nullptr, list.next);
}

TEST(LinkedListSearch1, Test)
{
  LinkedList node1(4, nullptr);
  LinkedList node2(3, &node1);
  LinkedList node3(2, &node2);
  LinkedList list(1, &node3);

  ASSERT_EQ(2, list.search(3));
}

TEST(LinkedListInsert1, Test)
{
  LinkedList node1(4, nullptr);
  LinkedList node2(3, &node1);
  LinkedList list(1, &node2);

  list.insert(2, 1);

  ASSERT_EQ(2, list.next->value);

  delete list.next;
}

TEST(LinkedListInsert2, Test)
{
  LinkedList list(1, nullptr);

  list.insert(2, 0);

  ASSERT_EQ(2, list.value);
  ASSERT_EQ(1, list.next->value);

  delete list.next;
}