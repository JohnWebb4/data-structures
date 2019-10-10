#include <gtest/gtest.h>

#include "./binarySearchTree.h"

TEST(BinarySearchTreeTest, Create)
{
  BinarySearchTree binarySearchtree(0);

  ASSERT_EQ(binarySearchtree.value, 0);
  ASSERT_EQ((bool)binarySearchtree.left, false);
  ASSERT_EQ((bool)binarySearchtree.right, false);
  ASSERT_EQ((bool)binarySearchtree.parent, false);
}

TEST(BinarySearchTreeTest, CreateVector)
{
  BinarySearchTree binarySearchTree({3, 2, 1, 4, 6, 5});

  ASSERT_EQ(binarySearchTree.value, 3);
  ASSERT_EQ(binarySearchTree.left->value, 2);
  ASSERT_EQ(binarySearchTree.left->parent, &binarySearchTree);
  ASSERT_EQ(binarySearchTree.left->left->value, 1);
  ASSERT_EQ(binarySearchTree.right->value, 4);
  ASSERT_EQ(binarySearchTree.right->right->value, 6);
  ASSERT_EQ(binarySearchTree.right->right->left->value, 5);
}

TEST(BinarySearchTreeTest, getPredecessor)
{
  BinarySearchTree binarySearchTree({3, 2, 1, 4, 6, 5});

  ASSERT_EQ(binarySearchTree.getPredecessor(3)->value, 2);
  ASSERT_EQ(binarySearchTree.getPredecessor(4)->value, 3);
  ASSERT_EQ(binarySearchTree.getPredecessor(5)->value, 4);
  ASSERT_THROW(binarySearchTree.getPredecessor(1), std::range_error);
  ASSERT_THROW(binarySearchTree.getPredecessor(10), std::invalid_argument);
}

TEST(BinarySearchTreeTest, getSuccessor)
{
  BinarySearchTree binarySearchTree({3, 1, 2, 4, 6, 5, 7});

  ASSERT_EQ(binarySearchTree.getSuccessor(3)->value, 4);
  ASSERT_EQ(binarySearchTree.getSuccessor(2)->value, 3);
  ASSERT_EQ(binarySearchTree.getSuccessor(6)->value, 7);
  ASSERT_THROW((void)binarySearchTree.getSuccessor(7), std::range_error);
  ASSERT_THROW(binarySearchTree.getSuccessor(10), std::invalid_argument);
}

TEST(BinarySearchTreeTest, Insert)
{
  BinarySearchTree binarySearchTree(3);

  binarySearchTree.insert(2);
  binarySearchTree.insert(1);
  binarySearchTree.insert(4);
  binarySearchTree.insert(6);
  binarySearchTree.insert(5);

  // Root
  ASSERT_EQ(binarySearchTree.value, 3);
  ASSERT_EQ((bool)binarySearchTree.left, true);
  ASSERT_EQ((bool)binarySearchTree.right, true);

  // Left
  ASSERT_EQ(binarySearchTree.left->value, 2);
  ASSERT_EQ((bool)binarySearchTree.left->left, true);
  ASSERT_EQ((bool)binarySearchTree.left->right, false);

  // Left left
  ASSERT_EQ(binarySearchTree.left->left->value, 1);
  ASSERT_EQ((bool)binarySearchTree.left->left->left, false);
  ASSERT_EQ((bool)binarySearchTree.left->left->right, false);

  // Right
  ASSERT_EQ(binarySearchTree.right->value, 4);
  ASSERT_EQ((bool)binarySearchTree.right->right, true);
  ASSERT_EQ((bool)binarySearchTree.right->left, false);

  // Right right
  ASSERT_EQ(binarySearchTree.right->right->value, 6);
  ASSERT_EQ((bool)binarySearchTree.right->right->right, false);
  ASSERT_EQ((bool)binarySearchTree.right->right->left, true);

  // Right right left
  ASSERT_EQ(binarySearchTree.right->right->left->value, 5);
  ASSERT_EQ((bool)binarySearchTree.right->right->left->right, false);
  ASSERT_EQ((bool)binarySearchTree.right->right->left->left, false);
}

TEST(BinarySearchTreeTest, Remove)
{
  BinarySearchTree binarySearchTree({3, 2, 1, 4, 6, 5, 7});

  // Remove leaf
  binarySearchTree.remove(5);

  ASSERT_EQ(binarySearchTree.value, 3);
  ASSERT_EQ(binarySearchTree.left->value, 2);
  ASSERT_EQ(binarySearchTree.left->left->value, 1);
  ASSERT_EQ(binarySearchTree.right->value, 4);
  ASSERT_EQ(binarySearchTree.right->right->value, 6);
  ASSERT_EQ(binarySearchTree.right->right->right->value, 7);
  ASSERT_EQ((bool)binarySearchTree.right->right->left, false);

  // Bypass node
  binarySearchTree.remove(2);

  ASSERT_EQ(binarySearchTree.value, 3);
  ASSERT_EQ(binarySearchTree.left->value, 1);
  ASSERT_EQ(binarySearchTree.right->value, 4);
  ASSERT_EQ(binarySearchTree.right->right->value, 6);
  ASSERT_EQ(binarySearchTree.right->right->right->value, 7);

  binarySearchTree.insert(5);
  binarySearchTree.remove(6);

  ASSERT_EQ(binarySearchTree.value, 3);
  ASSERT_EQ(binarySearchTree.left->value, 1);
  ASSERT_EQ(binarySearchTree.right->value, 4);
  ASSERT_EQ(binarySearchTree.right->right->value, 7);
  ASSERT_EQ(binarySearchTree.right->right->left->value, 5);
}

TEST(BinarySearchTreeTest, Search)
{
  BinarySearchTree binarySearchTree({3, 2, 1, 4, 6, 5, 7});

  ASSERT_EQ(binarySearchTree.search(3), &binarySearchTree);
  ASSERT_EQ(binarySearchTree.search(2), binarySearchTree.left);
  ASSERT_EQ(binarySearchTree.search(7), binarySearchTree.right->right->right);
}
