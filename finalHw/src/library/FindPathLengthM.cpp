//
// Created by Jingfeng Sun on 2024/6/13.
//

#include "FindPathLengthM.h"

void FindPathLengthM::FindPathLengthMDFS(Graph& graph, int start, int M, std::vector<int> pathBuilder) {
    visited.insert(start);
    pathBuilder.push_back(start);
    if (M == 0) {
        paths.push_back(pathBuilder);
        return;
    }
    for (int neighbor : graph.neighbors(start)) {
        if (visited.find(neighbor) == visited.end()) {
            FindPathLengthMDFS(graph, neighbor, M - 1, pathBuilder);
        }
    }
}

std::vector<std::vector<int>> FindPathLengthM::findPaths(Graph& graph, int start, int M) {
    FindPathLengthMDFS(graph, start, M, {});
    return paths;
}
