//
// Created by Jingfeng Sun on 2024/3/21.
//
#include <string>
#include "gtest/gtest.h"
#include "stack.h"

TEST(stackConstructor, createAStack) {
    Stack<int> st;
    Stack<std::string> st2(8);
    ASSERT_EQ(st.getSize(), 0);
    ASSERT_EQ(st.getCapicity(), 16);
    EXPECT_EQ(st2.getSize(), 0);
    ASSERT_EQ(st2.getCapicity(), 8);
}

TEST(stackPeak, normalFunction) {
    Stack<int> st;
    EXPECT_EQ(st.peak(), nullptr);
    st.push(1);
    EXPECT_EQ(*st.peak(), 1);
}

TEST(stackPush, resize) {
    Stack<int> st;
    for (int i = 0; i < 16; i++) {
        st.push(i);
        EXPECT_EQ(st.getSize(), i+1);
    }
    EXPECT_EQ(st.getCapicity(), 32);
}

TEST(stackPop, normalPop) {
    Stack<int> st;
    EXPECT_EQ(st.pop(), nullptr);
    EXPECT_EQ(st.getSize(), 0);
    st.push(1);
    EXPECT_EQ(*st.pop(), 1);
    EXPECT_EQ(st.getSize(), 0);
}

TEST(stackpop, resize) {
    Stack<int> st;
    for (int i = 0; i < 32; i++) {
        st.push(i);
    }
    EXPECT_EQ(st.getSize(), 32);
    Stack<int> other;
    other = st;
    EXPECT_EQ(other.getSize(), 32);
    for (int i = 0; i < 30; i++) {
        st.pop();
    }
    EXPECT_EQ(st.getCapicity(), 16);
}