//
// Created by Jingfeng Sun on 2024/5/19.
//
#include <gtest/gtest.h>
#include <CloseHashTable.h>

class CloseHashTableTest : public ::testing::Test {
protected:
    void SetUp() override {
        for (int i = 0; i < 60; i++) {
            table1.insert(i, i);
        }
        for (int i = 0; i < 60; i++) {
            table2.insert(i, i);
        }
    }
    closeHashTable<int, int> table1 = closeHashTable<int, int>(10, 10);
    closeHashTable<int, int> table2 = closeHashTable<int, int>(10, 10);
};

TEST_F(CloseHashTableTest, testEnlargeRehash) {
    EXPECT_EQ(table1.getSize(), 160);
    EXPECT_EQ(table2.getSize(), 160);
}

TEST_F(CloseHashTableTest, testShrinkRehash) {
    for (int i = 0; i < 10; i++) {
        table2.remove(i);
    }
    EXPECT_EQ(table2.getSize(), 160 * 0.9);
}
