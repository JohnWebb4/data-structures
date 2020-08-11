#include <vector>
#include <unordered_map>

#ifndef DISJOINTEDSETS_H
#define DISJOINTEDSETS_H

class DisjointedSets
{
public:
    std::unordered_map<int, int> sets;
    std::unordered_map<int, int> ranks;

    DisjointedSets(std::vector<std::vector<int>> sets);

    bool hasItem(int root, int value);
    void insertItem(int parent, int value);
    void removeItem(int value);

    int findSet(int value);
    bool isSameSet(int i, int j);
    void unionSet(int i, int j);
};

#endif