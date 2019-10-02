#include <gtest/gtest.h>

#include "./linkedList/linkedList.h"

TEST(LinkedListTest, Create)
{
  LinkedList list(1, nullptr);

  ASSERT_EQ(1, list.value);
  ASSERT_EQ(nullptr, list.next);
}

TEST(LinkedListTest, Search)
{
  LinkedList node1(4, nullptr);
  LinkedList node2(3, &node1);
  LinkedList node3(2, &node2);
  LinkedList list(1, &node3);

  ASSERT_EQ(2, list.search(3));
}

TEST(LinkedListTest, Insert)
{
  LinkedList node1(4, nullptr);
  LinkedList node2(3, &node1);
  LinkedList list(1, &node2);

  list.insert(2, 1);

  ASSERT_EQ(2, list.next->value);

  delete list.next;
}

TEST(LinkedListTest, Insert1)
{
  LinkedList list(1, nullptr);

  list.insert(2, 0);

  ASSERT_EQ(2, list.value);
  ASSERT_EQ(1, list.next->value);

  delete list.next;
}

TEST(LinkedListTest, Remove)
{
  LinkedList node1(1, nullptr);
  LinkedList node2(2, &node1);
  LinkedList list(3, &node2);

  list.remove(&node1);

  ASSERT_EQ(nullptr, list.next->next);
}
