#include "./hashMap.h"

int hash(std::string key, int size)
{
  return key[0] % size;
}

HashValue::HashValue(std::string key, int value) : key(key), value(value)
{
}

HashMap::HashMap(int size) : hashSections(size)
{
}

HashMap::~HashMap()
{
  for (auto hashSection : this->hashSections)
  {
    for (auto hashValue : hashSection)
    {
      delete hashValue;
    }
  }
}

void HashMap::set(std::string key, int value)
{
  int index = hash(key, this->hashSections.size());

  // Check has value
  for (HashValue *hashValue : this->hashSections[index])
  {
    if (hashValue->key == key)
    {
      hashValue->value = value;
      return;
    }
  }

  this->hashSections[index].push_back(new HashValue(key, value));
}

int HashMap::get(std::string key)
{
  int index = hash(key, this->hashSections.size());

  for (HashValue *hashValue : this->hashSections.at(index))
  {
    if (hashValue->key == key)
    {
      return hashValue->value;
    }
  }

  return -1;
}
