#include <vector>

#include "./disjointedSets.h"

DisjointedSets::DisjointedSets(std::vector<std::vector<int>> sets)
{
    for (auto set : sets)
    {
        for (auto value : set)
        {
            this->insertItem(set[0], value);
        }
    }
}

bool DisjointedSets::hasItem(int root, int value)
{
    try
    {
        int current = value;

        while (true) {
            auto parent = this->sets.at(current);

            if (current == parent && parent != root)
            {
                return false;
            }

            if (parent == root)
            {
                return true;
            }

            current = parent;
        }
    }
    catch (std::exception e)
    {
        return false;
    }

    return false;
}

void DisjointedSets::insertItem(int parent, int value)
{
    if (this->sets.find(value) != this->sets.end())
    {
        this->sets.erase(value);
    }

    this->sets.emplace(value, parent);
}

void DisjointedSets::removeItem(int value)
{
    this->sets.erase(value);
}

/**
 * Find set value belongs to
 * Throws: out_of_range exception if value is not in set
 **/
int DisjointedSets::findSet(int value)
{
    int current = value;

    while (true)
    {
        auto parent = this->sets.at(current);

        if (current == parent)
        {
            return current;
        }

        current = parent;
    }
}

bool DisjointedSets::isSameSet(int i, int j)
{
    try {
        int iSet = this->findSet(i);
        int jSet = this->findSet(j);

        return iSet == jSet;
    }
    catch (std::exception)
    {
        return false;
    }
}

void DisjointedSets::unionSet(int i, int j)
{
    int iSet = this->findSet(i);
    int jSet = this->findSet(j);

    this->insertItem(iSet, jSet);
}