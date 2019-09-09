#include "./linkedList.h"

LinkedList::LinkedList(int value, LinkedList *next)
{
  this->value = value;
  this->next = next;
}

int LinkedList::search(int value)
{
  LinkedList *current = this;

  for (int i = 0; current != nullptr; i++)
  {
    if (current->value == value)
    {
      return i;
    }

    current = current->next;
  }

  return -1;
}

void LinkedList::insert(int value, unsigned int index)
{
  if (index == 0)
  {
    int tempValue = this->value;
    this->value = value;
    LinkedList *list = new LinkedList(tempValue, this->next);
    this->next = list;

    return;
  }

  LinkedList *current = this;

  for (int i = 0; i < index - 1; i++)
  {
    if (current != nullptr)
    {
      current = current->next;
    }
    else
    {
      throw "Cannot insert at index";
    }
  }

  LinkedList *next = current->next;
  LinkedList *newNode = new LinkedList(value, next);
  current->next = newNode;
}

bool operator==(LinkedList list1, LinkedList list2)
{
  bool isEqual = list1.value == list2.value;

  if (isEqual)
  {
    isEqual = list1.next == list2.next;
  }

  return isEqual;
}