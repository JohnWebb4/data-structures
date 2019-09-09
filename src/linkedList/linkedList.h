#ifndef LINKEDLIST_H
#define LINKEDLIST_H 1

class LinkedList
{
public:
  int value;
  LinkedList *next;

  LinkedList(int value, LinkedList *next);
  int search(int value);
  void insert(int value, unsigned int index);
};

bool operator==(LinkedList list1, LinkedList list2);

#endif