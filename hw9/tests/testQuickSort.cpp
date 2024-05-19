//
// Created by Jingfeng Sun on 2024/5/19.
//
#include <gtest/gtest.h>
#include <quicksort.h>
#include <vector>

TEST(quicksort, emptyVector) {
    std::vector<int> vec = {};
    quicksort(vec);
    EXPECT_EQ(vec, std::vector<int>{});
}

TEST(quicksort, oneElement) {
    std::vector<int> vec = {1};
    quicksort(vec);
    EXPECT_EQ(vec, std::vector<int>{1});
}

TEST(quicksort, multielement) {
    std::vector<int> vec = {9, 1, 8, 3, 4, 10, 6, 2, 5, 5, 5, 9, 9, 8};
    quicksort(vec);
    std::vector<int> sorted = {1, 2, 3, 4, 5, 5, 5, 6, 8, 8, 9, 9, 9, 10};
    EXPECT_EQ(vec, sorted);
}
