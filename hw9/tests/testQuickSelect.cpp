//
// Created by Jingfeng Sun on 2024/5/19.
//
#include <gtest/gtest.h>
#include <quickselect.h>

TEST(quickSelect, emptyVector) {
    std::vector<int> vec = {};
    EXPECT_THROW(quickSelect(vec, 0), std::invalid_argument);
}

TEST(quickSelect, invalidK) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    EXPECT_THROW(quickSelect(vec, -1), std::invalid_argument);
    EXPECT_THROW(quickSelect(vec, 6), std::invalid_argument);
}

TEST(quickSelect, oneElement) {
    std::vector<int> vec = {1};
    EXPECT_EQ(quickSelect(vec, 1), 1);
}

TEST(quickSelect, multielement) {
    std::vector<int> vec = {9, 1, 8, 3, 4, 10, 6, 2, 5, 5, 5, 9, 9, 8};
    EXPECT_EQ(quickSelect(vec, 1), 1);
    EXPECT_EQ(quickSelect(vec, 2), 2);
    EXPECT_EQ(quickSelect(vec, 3), 3);
    EXPECT_EQ(quickSelect(vec, 4), 4);
    EXPECT_EQ(quickSelect(vec, 5), 5);
    EXPECT_EQ(quickSelect(vec, 6), 5);
    EXPECT_EQ(quickSelect(vec, 7), 5);
    EXPECT_EQ(quickSelect(vec, 8), 6);
    EXPECT_EQ(quickSelect(vec, 9), 8);
    EXPECT_EQ(quickSelect(vec, 10), 8);
    EXPECT_EQ(quickSelect(vec, 11), 9);
    EXPECT_EQ(quickSelect(vec, 12), 9);
    EXPECT_EQ(quickSelect(vec, 13), 9);
    EXPECT_EQ(quickSelect(vec, 14), 10);
}
