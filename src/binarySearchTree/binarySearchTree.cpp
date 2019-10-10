#include <stdexcept>
#include <vector>

#include "./binarySearchTree.h"

BinarySearchTree::BinarySearchTree(int value, BinarySearchTree *parent) : value(value), left(0), parent(parent), right(0)
{
}

BinarySearchTree::BinarySearchTree(std::vector<int> values) : BinarySearchTree(0)
{
  std::vector<int> newVector(values.begin(), values.end());
  if (newVector.size() > 0)
  {
    this->value = values.at(0);
    newVector.erase(newVector.begin());
  }

  for (int value : newVector)
  {
    this->insert(value);
  }
}

BinarySearchTree::~BinarySearchTree()
{
  if (this->left)
  {
    delete this->left;
  }

  if (this->right)
  {
    delete this->right;
  }
}

void BinarySearchTree::insert(int value)
{
  if (value == this->value)
  {
    throw std::invalid_argument("Cannot insert into binary search tree");
  }
  else if (value < this->value)
  {
    if (this->left)
    {
      this->left->insert(value);
      return;
    }

    this->left = new BinarySearchTree(value, this);
  }
  else
  {
    if (this->right)
    {
      this->right->insert(value);
      return;
    }

    this->right = new BinarySearchTree(value, this);
  }
}

void BinarySearchTree::remove(int value)
{
  BinarySearchTree *node = this->search(value);

  if (node)
  {
    BinarySearchTree *parent = node->parent;

    if (parent)
    {
      if (node->left && node->right)
      {
        // Replace successor
        BinarySearchTree *successor = node->getSuccessor(node->value);
        BinarySearchTree *successorParent = successor->parent;

        // Remove successor node from tree
        if (successorParent)
        {
          if(successorParent->left == successor)
          {
            successorParent->left = 0;
          } else {
            successorParent->right = 0;
          }
        }

        // Add to parent
        if (parent->left == node)
        {
          parent->left = successor;
          successor->parent = parent;
          successor->left = node->left;
        }
        else
        {
          parent->right = successor;
          successor->parent = parent;
          successor->left = node->left;
        }
      }
      else if (node->left || node->right)
      {
        BinarySearchTree *newNode;
        if (node->left)
        {
          newNode = node->left;
        }
        else
        {
          newNode = node->right;
        }

        // Bypass
        if (parent->left == node)
        {
          parent->left = newNode;
          newNode->parent = parent;
        }
        else
        {
          parent->right = newNode;
          newNode->parent = parent;
        }
      }
      else
      {
        // Delete leaf
        if (parent->left == node)
        {
          parent->left = 0;
        }
        else
        {
          parent->right = 0;
        }

      }
    }

    // Clear node
    node->left = 0;
    node->right = 0;

    delete node;
  }
  else
  {
    throw std::invalid_argument("Does not exist");
  }
}

BinarySearchTree *BinarySearchTree::getPredecessor(int value)
{
  BinarySearchTree *node = this->search(value);

  if (!node)
  {
    throw std::invalid_argument("Value does not exist");
  }

  if (node->left)
  {
    node = node->left;
    while (node->right)
    {
      node = node->right;
    }

    return node;
  }
  else
  {
    while (node->parent)
    {
      if (node->parent->value < node->value)
      {
        return node->parent;
      }

      node = node->parent;
    }
  }

  throw std::range_error("No successor for value");
}

BinarySearchTree *BinarySearchTree::getSuccessor(int value)
{
  BinarySearchTree *node = this->search(value);

  if (!node)
  {
    throw std::invalid_argument("Value does not exist");
  }

  if (node->right)
  {
    node = node->right;

    while (node->left)
    {
      node = node->left;
    }

    return node;
  }
  else
  {
    while (node->parent)
    {
      if (node->parent->value > node->value)
      {
        return node->parent;
      }

      node = node->parent;
    }

    throw std::range_error("No successor for value");
  }
}

BinarySearchTree *BinarySearchTree::search(int value)
{
  if (this->value == value)
  {
    return this;
  }
  else
  {
    if (this->left)
    {
      BinarySearchTree *leftResult = this->left->search(value);
      if (leftResult)
      {
        return leftResult;
      }
    }

    if (this->right)
    {
      BinarySearchTree *rightResult = this->right->search(value);
      if (rightResult)
      {
        return rightResult;
      }
    }
  }

  return 0;
}
