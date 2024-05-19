//
// Created by Jingfeng Sun on 2024/5/19.
//
#include <gtest/gtest.h>
#include <RemoveDuplicates.h>

TEST(RemoveDuplicates, NoDuplicates) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    removeDuplicates(vec);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(vec, expected);
}

TEST(RemoveDuplicates, AllDuplicates) {
    std::vector<int> vec = {1, 1, 1, 1, 1};
    removeDuplicates(vec);
    std::vector<int> expected = {1};
    EXPECT_EQ(vec, expected);
}

TEST(RemoveDuplicates, SomeDuplicates) {
    std::vector<int> vec = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    removeDuplicates(vec);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(vec, expected);
}
