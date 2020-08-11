#include <gtest/gtest.h>

#include "./disjointedSets.h"

TEST(DisjointedSetsTest, HasItem)
{
    DisjointedSets sets({ { 1, 2, 3 }, { 7, 8, 9 } });

    sets.insertItem(3, 4);
    sets.insertItem(4, 6);

    ASSERT_TRUE(sets.hasItem(1, 1));
    ASSERT_TRUE(sets.hasItem(1, 2));

    // Handle nested
    ASSERT_TRUE(sets.hasItem(3, 4));
    ASSERT_TRUE(sets.hasItem(1, 4));

    // Handle missing
    ASSERT_FALSE(sets.hasItem(1, 5));

    // Handle deeply nested
    ASSERT_TRUE(sets.hasItem(4, 6));
    ASSERT_TRUE(sets.hasItem(3, 6));
    ASSERT_TRUE(sets.hasItem(1, 6));

    // Handle other sets
    ASSERT_TRUE(sets.hasItem(7, 8));
    ASSERT_FALSE(sets.hasItem(3, 8));

    // Handle removing from sets
    sets.removeItem(2);
    ASSERT_FALSE(sets.hasItem(1, 2));
}

TEST(DisjointedSetsTest, FindSet)
{
    DisjointedSets sets({ { 1, 2, 3 } });

    sets.insertItem(3, 4);

    ASSERT_EQ(sets.findSet(3), 1);
    ASSERT_EQ(sets.findSet(4), 1);
    ASSERT_THROW(sets.findSet(5), std::out_of_range);
}

TEST(DisjointedSetsTest, IsSameSet)
{
    DisjointedSets sets({ { 1, 2, 3 }, { 4, 5, 6 } });

    sets.insertItem(3, 7);
    sets.insertItem(6, 8);

    ASSERT_FALSE(sets.isSameSet(7, 8));
    ASSERT_TRUE(sets.isSameSet(7, 7));
    ASSERT_TRUE(sets.isSameSet(4, 8));
    ASSERT_FALSE(sets.isSameSet(7, 9));
}

TEST(DisjointedSetsTest, UnionSet)
{
    DisjointedSets sets({ { 1, 2, 3 }, { 4, 5, 6 } });

    ASSERT_FALSE(sets.isSameSet(3, 6));
    sets.unionSet(1, 4);
    ASSERT_TRUE(sets.isSameSet(3, 6));

}