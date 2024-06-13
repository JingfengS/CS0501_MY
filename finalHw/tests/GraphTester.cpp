//
// Created by Jingfeng Sun on 2024/6/13.
//
#include "gtest/gtest.h"
#include <Graph.h>

class GraphTester : public ::testing::Test {
protected:
    Graph g;

    void SetUp() override {
        g.addVertex(0);
        g.addVertex(1);
        g.addVertex(2);
        g.addVertex(3);
        g.addVertex(4);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 4);
        g.addEdge(1, 3);
    };
};

TEST_F(GraphTester, addVertex) {
    ASSERT_THROW(g.addVertex(1), std::runtime_error);
    ASSERT_NO_THROW(g.addVertex(5));
}

TEST_F(GraphTester, addEdge) {
    ASSERT_THROW(g.addEdge(1, 5), std::runtime_error);
    ASSERT_NO_THROW(g.addEdge(1, 2));
}

TEST_F(GraphTester, testGraph) {
    ASSERT_EQ(g.neighbors(0).size(), 2);
    ASSERT_EQ(g.neighbors(1).size(), 2);
    ASSERT_EQ(g.neighbors(2).size(), 0);
    ASSERT_EQ(g.neighbors(3).size(), 0);
    ASSERT_EQ(g.neighbors(4).size(), 0);
}
