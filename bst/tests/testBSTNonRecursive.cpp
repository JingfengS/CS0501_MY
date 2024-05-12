//
// Created by Jingfeng Sun on 2024/5/12.
//
#include <iostream>
#include <gtest/gtest.h>
#include <BSTNonRecursive.h>

class TestBSTNonRecursive : public testing::Test {
protected:
    /**
     * the bst will look like this:
     *         5
     *        /\
     *       4 6
     *      /   \
     *     2    10
     *    / \   /
     *   1  3  8
     *        /\
     *       7 9
     */
    void SetUp() override {
        bst.insert(5);
        bst.insert(4);
        bst.insert(2);
        bst.insert(3);
        bst.insert(1);
        bst.insert(6);
        bst.insert(10);
        bst.insert(8);
        bst.insert(9);
        bst.insert(7);
    }
    BSTNonRecursive bst = BSTNonRecursive();
};

TEST_F(TestBSTNonRecursive, insert) {
    EXPECT_EQ(bst.search(5), true);
    EXPECT_EQ(bst.search(4), true);
    EXPECT_EQ(bst.search(2), true);
    EXPECT_EQ(bst.search(3), true);
    EXPECT_EQ(bst.search(1), true);
    EXPECT_EQ(bst.search(6), true);
    EXPECT_EQ(bst.search(10), true);
    EXPECT_EQ(bst.search(8), true);
    EXPECT_EQ(bst.search(9), true);
    EXPECT_EQ(bst.search(7), true);
    EXPECT_EQ(bst.search(11), false);
    bst.insert(11);
    EXPECT_EQ(bst.search(11), true);
}

TEST_F(TestBSTNonRecursive, search) {
    EXPECT_EQ(bst.search(5), true);
    EXPECT_EQ(bst.search(4), true);
    EXPECT_EQ(bst.search(2), true);
    EXPECT_EQ(bst.search(3), true);
    EXPECT_EQ(bst.search(1), true);
    EXPECT_EQ(bst.search(6), true);
    EXPECT_EQ(bst.search(10), true);
    EXPECT_EQ(bst.search(8), true);
    EXPECT_EQ(bst.search(9), true);
    EXPECT_EQ(bst.search(7), true);
    EXPECT_EQ(bst.search(11), false);
}

TEST_F(TestBSTNonRecursive, remove) {
    EXPECT_EQ(bst.search(5), true);
    EXPECT_EQ(bst.search(4), true);
    EXPECT_EQ(bst.search(2), true);
    EXPECT_EQ(bst.search(3), true);
    EXPECT_EQ(bst.search(1), true);
    EXPECT_EQ(bst.search(6), true);
    EXPECT_EQ(bst.search(10), true);
    EXPECT_EQ(bst.search(8), true);
    EXPECT_EQ(bst.search(9), true);
    EXPECT_EQ(bst.search(7), true);
    EXPECT_EQ(bst.search(11), false);
    bst.remove(5);
    EXPECT_EQ(bst.search(5), false);
    bst.remove(4);
    EXPECT_EQ(bst.search(4), false);
    bst.remove(2);
    EXPECT_EQ(bst.search(2), false);
    bst.remove(3);
    EXPECT_EQ(bst.search(3), false);
    bst.remove(1);
    EXPECT_EQ(bst.search(1), false);
    bst.remove(6);
    EXPECT_EQ(bst.search(6), false);
    bst.remove(10);
    EXPECT_EQ(bst.search(10), false);
    bst.remove(8);
    EXPECT_EQ(bst.search(8), false);
    bst.remove(9);
    EXPECT_EQ(bst.search(9), false);
    bst.remove(7);
    EXPECT_EQ(bst.search(7), false);
    bst.remove(11);
    EXPECT_EQ(bst.search(11), false);
}
