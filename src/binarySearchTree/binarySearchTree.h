#include <vector>

class BinarySearchTree
{
public:
  int value;
  BinarySearchTree *left;
  BinarySearchTree *right;
  BinarySearchTree *parent;
  BinarySearchTree(int value, BinarySearchTree *parent = 0);
  BinarySearchTree(std::vector<int> values);
  ~BinarySearchTree();
  BinarySearchTree *getPredecessor(int value);
  BinarySearchTree *getSuccessor(int value);
  void insert(int value);
  void remove(int value);
  BinarySearchTree *search(int value);
};
