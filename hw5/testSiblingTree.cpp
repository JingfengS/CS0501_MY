//
// Created by Jingfeng Sun on 2024/4/7.
//
#include <iostream>
#include "gtest/gtest.h"
#include "siblingTree.h"

TEST(SiblingChildTree, constructor) {
    SiblingTree<int> bt2;
    bt2.root = new SiblingTree<int>::Node(0);
    bt2.root->child = new SiblingTree<int>::Node(1);
    bt2.root->sibling = new SiblingTree<int>::Node(2);
    bt2.preOrder();

    SiblingTree<int> bt1(bt2);
    std::cout << "This is bt1: ";
    bt1.preOrder();
    std::cout << "Copy constructor OK\n";
    std::cout << std::endl;

    SiblingTree<int> bt3 = bt1;
    std::cout << "This is bt3: ";
    bt3.preOrder();
    std::cout << "operator= OK\n";

}

class SiblingTreeTest : public testing::Test {
protected:
    // Creating a simple child-sibling tree:
    //       1
    //      /
    //     2 - 3 - 4
    //    /       /
    //   5 - 6   7 - 8
    void SetUp() override {
        st.root->child = new SiblingTree<int>::Node(2);
        st.root->child->sibling = new SiblingTree<int>::Node(3);
        st.root->child->sibling->sibling = new SiblingTree<int>::Node(4);
        st.root->child->child = new SiblingTree<int>::Node(5);
        st.root->child->child->sibling = new SiblingTree<int>::Node(6);
        st.root->child->sibling->sibling->child = new SiblingTree<int>::Node(7);
        st.root->child->sibling->sibling->child->sibling = new SiblingTree<int>::Node(8);
    }
    SiblingTree<int> st = SiblingTree<int>(1);
};

TEST_F(SiblingTreeTest, preOrder) {
    std::cout << "PreOrder: ";
    st.preOrder();
}

TEST_F(SiblingTreeTest, postOrder) {
    std::cout << "PostOrder: ";
    st.postOrder();
}

TEST_F(SiblingTreeTest, levelOrder) {
    std::cout << "LeverOrder: ";
    st.levelOrder();
}