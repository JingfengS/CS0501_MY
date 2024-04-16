//
// Created by Jingfeng Sun on 2024/4/16.
//
#include <iostream>
#include "ArraySet.h"
#include "gtest/gtest.h"

class SetTest : public ::testing::Test {
protected:
    ArraySet<int> set;
    void SetUp() override {
        for (int i = 0; i < 10; i++) {
            set.add(i);
        }
    }
};

TEST_F(SetTest, add) {
    set.add(10);
    EXPECT_EQ(set.size(), 11);
    set.add(10);
    EXPECT_EQ(set.size(), 11);
}

TEST_F(SetTest, remove) {
    set.remove(5);
    EXPECT_EQ(set.size(), 9);
    EXPECT_THROW({set.remove(5);}, std::runtime_error);
}

TEST_F(SetTest, contains) {
    EXPECT_TRUE(set.contains(5));
    EXPECT_FALSE(set.contains(10));
}

TEST_F(SetTest, size) {
    EXPECT_EQ(set.size(), 10);
    set.add(10);
    EXPECT_EQ(set.size(), 11);
    set.remove(5);
    EXPECT_EQ(set.size(), 10);
}

TEST_F(SetTest, isEmpty) {
    EXPECT_FALSE(set.isEmpty());
    set.clear();
    EXPECT_TRUE(set.isEmpty());
}

TEST_F(SetTest, clear) {
    set.clear();
    EXPECT_TRUE(set.isEmpty());
}

TEST_F(SetTest, printSet) {
    set.printSet();
}

TEST_F(SetTest, copyConstructor) {
    ArraySet<int> set2(set);
    EXPECT_EQ(set.size(), set2.size());
    for (int i = 0; i < 10; i++) {
        EXPECT_TRUE(set2.contains(i));
    }
}

TEST_F(SetTest, assignmentOperator) {
    ArraySet<int> set2;
    set2 = set;
    EXPECT_EQ(set.size(), set2.size());
    for (int i = 0; i < 10; i++) {
        EXPECT_TRUE(set2.contains(i));
    }
}

TEST_F(SetTest, iterator) {
    ArraySet<int>::Iterator it = set.begin();
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(*it, i);
        ++it;
    }

    int i = 0;
    for (auto j : set) {
        EXPECT_EQ(j, i);
        i++;
    }
}

TEST_F(SetTest, union) {
    ArraySet<int> set2;
    for (int i = 5; i < 15; i++) {
        set2.add(i);
    }
    ArraySet<int> set3 = set + set2;
    EXPECT_EQ(set3.size(), 15);
    for (int i = 0; i < 15; i++) {
        EXPECT_TRUE(set3.contains(i));
    }
    std::cout << "Union of set and set2: ";
    set3.printSet();
}

TEST_F(SetTest, intersection) {
    ArraySet<int> set2;
    for (int i = 5; i < 15; i++) {
        set2.add(i);
    }
    ArraySet<int> set3 = set * set2;
    EXPECT_EQ(set3.size(), 5);
    for (int i = 5; i < 10; i++) {
        EXPECT_TRUE(set3.contains(i));
    }
    std::cout << "Intersection of set and set2: ";
    set3.printSet();
}

TEST_F(SetTest, difference) {
    ArraySet<int> set2;
    for (int i = 5; i < 15; i++) {
        set2.add(i);
    }
    ArraySet<int> set3 = set - set2;
    EXPECT_EQ(set3.size(), 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_TRUE(set3.contains(i));
    }
    std::cout << "Difference of set and set2: ";
    set3.printSet();
}