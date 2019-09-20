#include <string>
#include <vector>

#ifndef HASHMAP_H
#define HASHMAP_H 1

class HashValue
{
public:
  int value;
  std::string key;
  HashValue(std::string key, int value);
};

class HashMap
{
public:
  std::vector<std::vector<HashValue *>> hashSections;

  HashMap(int size);
  ~HashMap();
  int get(std::string key);
  void set(std::string key, int value);
};

#endif