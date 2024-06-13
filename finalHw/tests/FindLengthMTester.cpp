//
// Created by Jingfeng Sun on 2024/6/13.
//
#include "gtest/gtest.h"
#include "FindPathLengthM.h"

TEST(FindPathLengthMTester, Test1) {
    Graph graph;
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    FindPathLengthM findPathLengthM;
    std::vector<std::vector<int>> paths = findPathLengthM.findPaths(graph, 0, 2);
    std::vector<std::vector<int>> expectedPaths = {{0, 2, 5}, {0, 1, 4}};
    ASSERT_EQ(paths, expectedPaths);
}
