//
// Created by Jingfeng Sun on 2024/3/29.
//
#include "gtest/gtest.h"
#include "deque.h"

TEST(deque, contructor) {
    deque<int> dq;
}

TEST(deque, addLast) {
    deque<int> dq;
    dq.addLast(1);
    dq.printList();
    dq.addLast(2);
    dq.printList();
    dq.addLast(3);
    dq.printList();
    dq.addLast(4);
    dq.printList();
    EXPECT_EQ(dq.getSize(), 4);
}

TEST(deque, addFirst) {
    deque<int> dq;
    for (int i = 0; i < 5; i++) {
        dq.addLast(i);
    }
    std::cout << "This is the deque before addFirst: \n";
    dq.printList();
    dq.addFirst(-1);
    std::cout << "This is the deque after addFirst: \n";
    dq.printList();
    EXPECT_EQ(dq.getSize(), 6);
}

TEST(deque, getFirst) {
    deque<int> dq;
    EXPECT_THROW({dq.getFirst();}, std::runtime_error);
    dq.addLast(1);
    dq.addFirst(0);
    dq.addLast(2);
    EXPECT_EQ(dq.getFirst(), 0);
}

TEST(deque, getLast) {
    deque<int> dq;
    EXPECT_THROW({dq.getLast();}, std::runtime_error);
    dq.addLast(1);
    dq.addFirst(0);
    dq.addLast(2);
    EXPECT_EQ(dq.getLast(), 2);
}

TEST(deque, get) {
    deque<int> dq;
    EXPECT_THROW({dq.get(0);}, std::runtime_error);
    for (int i = 0; i < 10; i++) {
        dq.addLast(i);
    }
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(dq.get(i), i);
    }
    EXPECT_THROW({dq.get(10);}, std::runtime_error);
}

TEST(deque, removeLast) {
    deque<int> dq;
    EXPECT_THROW({dq.removeLast();}, std::runtime_error);
    dq.addLast(1);
    dq.addLast(2);
    dq.addLast(3);
    EXPECT_EQ(dq.removeLast(), 3);
    EXPECT_EQ(dq.getSize(), 2);
    EXPECT_EQ(dq.getLast(), 2);
}

TEST(deque, removeFirst) {
    deque<int> dq;
    EXPECT_THROW({dq.removeFirst();}, std::runtime_error);
    dq.addLast(1);
    dq.addLast(2);
    dq.addLast(3);
    EXPECT_EQ(dq.removeFirst(),1);
    EXPECT_EQ(dq.getSize(), 2);
    EXPECT_EQ(dq.getFirst(), 2);
}

TEST(deque, copyConstructor) {
    deque<int> dq1;
    deque<int> dq2(dq1);
    EXPECT_TRUE(dq2.isEmpty());
    dq2.addLast(1);
    dq2.addLast(2);
    EXPECT_TRUE(dq1.isEmpty());
    deque<int> dq3(dq2);
    EXPECT_EQ(dq3.getSize(), 2);
    EXPECT_EQ(dq3.getFirst(), 1);
    EXPECT_EQ(dq3.getLast(), 2);
}

TEST(deque, assign) {
    deque<int> dq1;
    deque<int> dq2;
    dq2.addLast(1);
    dq2 = dq1;
    EXPECT_TRUE(dq2.isEmpty());
    dq2.addLast(1);
    dq2.addLast(2);
    EXPECT_TRUE(dq1.isEmpty());
    deque<int> dq3;
    dq3 = dq2;
    EXPECT_EQ(dq3.getSize(), 2);
    EXPECT_EQ(dq3.getFirst(), 1);
    EXPECT_EQ(dq3.getLast(), 2);
}

TEST(deque, remove) {
    deque<int> dq1;
    deque<int> dq2;
    deque<int> dq3;

    EXPECT_THROW({dq1.remove(0);}, std::runtime_error);

    dq2.addLast(0);
    EXPECT_EQ(dq2.remove(0), 0);
    dq2.printList();
    EXPECT_EQ(dq2.getSize(), 0);

    dq3.addLast(1);
    dq3.addLast(0);
    dq3.addLast(2);

    dq3.remove(0);
    EXPECT_EQ(dq3.getSize(), 2);
    dq3.printList();
    dq3.remove(1);
    dq3.printList();
    dq3.remove(2);
    dq3.printList();
}