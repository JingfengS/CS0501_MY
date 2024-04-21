//
// Created by Jingfeng Sun on 2024/4/7.
//
#include <iostream>
#include <string>
#include "Heap.h"
#include "gtest/gtest.h"

using std::string;
class HeapTest : public testing::Test {
protected:
    void SetUp() override {
        pq.insert("c", 3);
        pq.insert("i", 9);
        pq.insert("g", 7);
        pq.insert("d", 4);
        pq.insert("a", 1);
        pq.insert("h", 8);
        pq.insert("e", 5);
        pq.insert("b", 2);
        pq.insert("c", 3);
        pq.insert("d", 4);
    }
    Heap<string> pq = Heap<string>();
};

TEST_F(HeapTest, insertAndRemoveAndPeek) {
    pq.printContent();
    int i = 0;
    string expected[] = {"a", "b", "c", "c", "d", "d", "e", "g", "h", "i", "g"};
    while (pq.getSize() >= 1) {
        EXPECT_EQ(expected[i], pq.removeMin());
        i += 1;
    }
}

TEST_F(HeapTest, findMin) {
    pq.printContent();
    EXPECT_EQ("a", pq.getValue(pq.findMin(1)));
    EXPECT_EQ("e", pq.getValue(pq.findMin(5)));
    EXPECT_EQ("c", pq.getValue(pq.findMin(3)));
    EXPECT_EQ(-1, pq.findMin(10));
}

TEST_F(HeapTest, decreaseKey) {
    std::cout << "Before decrease: ";
    pq.printContent();
    pq.decreaseKey(8, 9);
    std::cout << "After decrease: ";
    pq.printContent();
    EXPECT_EQ("i", pq.removeMin());
}

