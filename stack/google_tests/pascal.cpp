//
// Created by Jingfeng Sun on 2024/3/22.
//
#include <string>
#include <iostream>
#include "gtest/gtest.h"
#include "stringStack.h"
#include "pascalChecker.h"

TEST(stringStack, splitSentence) {
    std::cout << "This checks if the stack can get the right pascal commands\n";
    stringStack s("Today is a nice day");
    s.display();
    EXPECT_EQ(s.getSize(), 5);
    EXPECT_EQ(s.getCapicity(), 16);
}

TEST(checkPascal, basicCase) {
    EXPECT_TRUE(check(""));
    EXPECT_TRUE(check("hello"));
    EXPECT_FALSE(check("begin"));
    EXPECT_FALSE(check("end"));
    EXPECT_FALSE(check("if"));
    EXPECT_FALSE(check("then"));
    EXPECT_FALSE(check("else"));
}

TEST(checkPascal, pairCheck) {
    EXPECT_TRUE(check("begin end"));
    EXPECT_TRUE(check("if then"));
    EXPECT_TRUE(check("if then else"));
    EXPECT_FALSE(check("begin else end"));
    EXPECT_FALSE(check("begin end else"));
    EXPECT_FALSE(check("begin if"));
    EXPECT_FALSE(check("begin then"));
}

TEST(checkPascal, nestedCheck) {
    EXPECT_TRUE(check("begin begin end end"));
    EXPECT_TRUE(check("begin if then end"));
    EXPECT_TRUE(check("begin if then else end begin end"));
    EXPECT_TRUE(check("begin a b c end d e if a then d else e"));
    EXPECT_FALSE(check("begin if then else"));
    EXPECT_FALSE(check("if begin then end"));
    EXPECT_TRUE(check("if begin end then"));
}



