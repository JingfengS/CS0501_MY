//
// Created by Jingfeng Sun on 2024/5/12.
//
#include <iostream>
#include <gtest/gtest.h>
#include <BST.h>

class TestBST : public testing::Test {
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
        bst.insert(5, 'a');
        bst.insert(4, 'b');
        bst.insert(2, 'c');
        bst.insert(3, 'd');
        bst.insert(1, 'e');
        bst.insert(6, 'f');
        bst.insert(10, 'g');
        bst.insert(8, 'h');
        bst.insert(9, 'i');
        bst.insert(7, 'j');
    }
    BST<int, char> bst = BST<int, char>();
};

TEST_F(TestBST, insert) {
    bst.printLevelOrder();
    EXPECT_EQ(bst.size(), 10);
    bst.insert(10, 'z');
    EXPECT_EQ(bst.size(), 10);
    bst.insert(11, 'z');
    EXPECT_EQ(bst.size(), 11);
    EXPECT_EQ(bst.search(10), 'z');
    bst.printLevelOrder();
}

TEST_F(TestBST, search) {
    EXPECT_EQ(bst.search(5), 'a');
    EXPECT_EQ(bst.search(4), 'b');
    EXPECT_EQ(bst.search(2), 'c');
    EXPECT_EQ(bst.search(3), 'd');
    EXPECT_EQ(bst.search(1), 'e');
    EXPECT_EQ(bst.search(6), 'f');
    EXPECT_EQ(bst.search(10), 'g');
    EXPECT_EQ(bst.search(8), 'h');
    EXPECT_EQ(bst.search(9), 'i');
    EXPECT_EQ(bst.search(7), 'j');
}

