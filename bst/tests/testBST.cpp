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
    BSTNon<int, char> bst = BSTNon<int, char>();
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

TEST_F(TestBST, min) {
    EXPECT_EQ(bst.min(), 'e');
}

TEST_F(TestBST, max) {
    EXPECT_EQ(bst.max(), 'g');
}

TEST_F(TestBST, delMin) {
    EXPECT_EQ(bst.delMin(), 'e');
    EXPECT_EQ(bst.size(), 9);
    EXPECT_EQ(bst.delMin(), 'c');
    EXPECT_EQ(bst.size(), 8);
    bst.printLevelOrder();
    BSTNon<int, char>bst2;
    bst2.insert(1, 'a');
    EXPECT_EQ(bst2.delMin(), 'a');
    EXPECT_EQ(bst2.size(), 0);
}

TEST_F(TestBST, delMax) {
    EXPECT_EQ(bst.delMax(), 'g');
    EXPECT_EQ(bst.size(), 9);
    EXPECT_EQ(bst.delMax(), 'i');
    EXPECT_EQ(bst.size(), 8);
    bst.printLevelOrder();
}

TEST_F(TestBST, remove) {
    EXPECT_FALSE(bst.empty());
    EXPECT_EQ(bst.remove(5), 'a');
    EXPECT_EQ(bst.size(), 9);
    bst.printLevelOrder();
    EXPECT_EQ(bst.remove(4), 'b');
    EXPECT_EQ(bst.remove(10), 'g');
    EXPECT_EQ(bst.size(), 7);
    bst.printLevelOrder();
    EXPECT_EQ(bst.remove(2), 'c');
    EXPECT_EQ(bst.remove(3), 'd');
    EXPECT_EQ(bst.remove(1), 'e');
    EXPECT_EQ(bst.remove(6), 'f');
    EXPECT_EQ(bst.remove(8), 'h');
    EXPECT_EQ(bst.remove(9), 'i');
    EXPECT_EQ(bst.remove(7), 'j');
    EXPECT_TRUE(bst.empty());
}

TEST_F(TestBST, deleteLessThan) {
    bst.deleteLessThan(5);
    EXPECT_EQ(bst.size(), 6);
    bst.printLevelOrder();
    bst.deleteLessThan(6);
    EXPECT_EQ(bst.size(), 5);
    bst.printLevelOrder();
    bst.deleteLessThan(10);
    EXPECT_EQ(bst.size(), 1);
    bst.printLevelOrder();
}

TEST_F(TestBST, deleteGreaterThan) {
    bst.deleteGreaterThan(5);
    EXPECT_EQ(bst.size(), 5);
    bst.printLevelOrder();
    bst.deleteGreaterThan(4);
    EXPECT_EQ(bst.size(), 4);
    bst.printLevelOrder();
    bst.deleteGreaterThan(2);
    EXPECT_EQ(bst.size(), 2);
    bst.printLevelOrder();
}

TEST_F(TestBST, deleteRange) {
    bst.deleteRange(2, 8);
    EXPECT_EQ(bst.size(), 3);
    bst.printLevelOrder();
}

TEST_F(TestBST, findIthLargest) {
    EXPECT_EQ(bst.findIthLargest(1), 'g');
    EXPECT_EQ(bst.findIthLargest(2), 'i');
    EXPECT_EQ(bst.findIthLargest(3), 'h');
    EXPECT_EQ(bst.findIthLargest(4), 'j');
    EXPECT_EQ(bst.findIthLargest(5), 'f');
    EXPECT_EQ(bst.findIthLargest(6), 'a');
    EXPECT_EQ(bst.findIthLargest(7), 'b');
}
