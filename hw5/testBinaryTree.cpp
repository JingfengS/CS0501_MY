//
// Created by Jingfeng Sun on 2024/4/7.
//
#include <iostream>
#include "gtest/gtest.h"
#include "BTree.h"

TEST(BTree, constructor) {
    BTree<int> bt2;
    bt2.root = new BTree<int>::Node(0);
    bt2.root->right = new BTree<int>::Node(1);
    bt2.root->left = new BTree<int>::Node(2);
    bt2.printTree();

    BTree<int> bt1(bt2);
    std::cout << "This is bt1: ";
    bt1.printTree();
    std::cout << "Copy constructor OK\n";
    std::cout << std::endl;

    BTree<int> bt3 = bt1;
    std::cout << "This is bt3: ";
    bt3.printTree();
    std::cout << "operator= OK\n";

    bt3.deleteNode(bt3.root);
    std::cout << "This is bt3 after deletion: ";
    bt3.printTree();
}

class BTreeTest : public testing::Test {
protected:
    /**
     *   bt1: 0  bt2: 0  bt3:  0      bt4:  0      bt5:  0     bt6:  0        bt7:  0       bt8:  0
     *               /       /   \        /   \        /   \       /   \          /   \         /   \
     *              1       1     2      1     2      1     2     1     2        1     2       1     2
     *                                 /  \  /  \   /  \  /     /     /  \        \  /  \    /     /  \
     *                                3   4 5   6  3   4 5     3     5   6        4 5   6   3     5   6
     *                                                                                    /  \
     *                                                                                   7    8
     */
    void SetUp() override {
        bt1.root = new BTree<int>::Node(0);

        bt2.root = new BTree<int>::Node(0);
        bt2.root->left = new BTree<int>::Node(1);

        bt3.root = new BTree<int>::Node(0);
        bt3.root->left = new BTree<int>::Node(1);
        bt3.root->right = new BTree<int>::Node(2);

        bt4 = bt3;
        bt4.root->left->left = new BTree<int>::Node(3);
        bt6 = bt4;
        bt4.root->left->right = new BTree<int>::Node(4);
        bt5 = bt4;
        bt5.root->right->left = new BTree<int>::Node(5);
        bt4.root->right->left = new BTree<int>::Node(5);
        bt4.root->right->right = new BTree<int>::Node(6);

        bt6.root->right->left = new BTree<int>::Node(5);
        bt6.root->right->right = new BTree<int>::Node(6);

        bt7 = bt3;
        bt7.root->left->right = new BTree<int>::Node(3);
        bt7.root->right->left = new BTree<int>::Node(5);
        bt7.root->right->right = new BTree<int>::Node(6);

        bt8 = bt6;
        bt8.root->left->left->left = new BTree<int>::Node(8);
        bt8.root->left->left->right = new BTree<int>::Node(9);
    }
    BTree<int> bt1, bt2, bt3, bt4, bt5, bt6, bt7, bt8;
};

TEST_F(BTreeTest, twoNodes) {
    EXPECT_EQ(bt1.numOf2ChildsParents(), 0);
    EXPECT_EQ(bt2.numOf2ChildsParents(), 0);
    EXPECT_EQ(bt3.numOf2ChildsParents(), 1);
    EXPECT_EQ(bt4.numOf2ChildsParents(), 3);
    EXPECT_EQ(bt5.numOf2ChildsParents(), 2);
    EXPECT_EQ(bt6.numOf2ChildsParents(), 2);
    EXPECT_EQ(bt7.numOf2ChildsParents(), 2);
    EXPECT_EQ(bt8.numOf2ChildsParents(), 3);
}

TEST_F(BTreeTest, isComplete) {
    EXPECT_TRUE(bt1.isComplete());
    EXPECT_TRUE(bt2.isComplete());
    EXPECT_TRUE(bt3.isComplete());
    EXPECT_TRUE(bt4.isComplete());
    EXPECT_TRUE(bt5.isComplete());
    EXPECT_FALSE(bt6.isComplete());
    EXPECT_FALSE(bt7.isComplete());
    EXPECT_FALSE(bt8.isComplete());
}

using std::cout;
using std::endl;
TEST(Steering_angle, compute) {
    bool turn_right = true;
    bool turn_left = false;
    float desired_line_slope = -1.6;
    const int len_ahead = 50;
    float desired_line_intercept = 20;
    int wheelbase = 25;
    float degrees;
    float delta = (1 + desired_line_slope * desired_line_slope) * len_ahead * len_ahead - desired_line_intercept * desired_line_intercept;
    if (delta >= 0) {
        float aim_point_x = - (desired_line_slope * desired_line_intercept + sqrt(delta))
                            / (1 + desired_line_slope * desired_line_slope);
        float aim_point_y = desired_line_slope * aim_point_x + desired_line_intercept;

        // 计算转向角
        cout << "DEBUG: degrees = " << atan(2 * wheelbase * aim_point_y / (len_ahead * len_ahead)) / 3.14159 * 180 << endl;
    }
    else {
        if(turn_right) cout << 40;
        if(turn_left) cout << -40;
        cout << 0;
    }
}
