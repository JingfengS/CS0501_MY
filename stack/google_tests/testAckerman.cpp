//
// Created by Jingfeng Sun on 2024/3/23.
//
#include "gtest/gtest.h"
#include "acker.h"

TEST(ackerman, recursive) {
   EXPECT_EQ(ackerman_recursive(0, 0), 1);
   EXPECT_EQ(ackerman_recursive(1, 0), 2);
   EXPECT_EQ(ackerman_recursive(2, 0), 3);
   EXPECT_EQ(ackerman_recursive(2, 1), 5);
   EXPECT_EQ(ackerman_recursive(2, 2), 7);
}

TEST(ackerman, nonrecursive) {
    EXPECT_EQ(ackerman_nonrecursive(0, 0), 1);
    EXPECT_EQ(ackerman_nonrecursive(1, 0), 2);
    EXPECT_EQ(ackerman_nonrecursive(2, 0), 3);
    EXPECT_EQ(ackerman_nonrecursive(2, 1), 5);
    EXPECT_EQ(ackerman_nonrecursive(2, 2), 7);
}