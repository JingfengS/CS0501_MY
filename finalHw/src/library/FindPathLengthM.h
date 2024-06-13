//
// Created by Jingfeng Sun on 2024/6/13.
//

#ifndef GRAPH_FINDPATHLENGTHM_H
#define GRAPH_FINDPATHLENGTHM_H
#include "Graph.h"


/**
 * Find all the paths start from Node [start] of exact length M in Graph [graph]
 * Note that Because the edge of this graph has no weight, so you can assume that every edge has weight 1
 * if we are dealing with weighted graph, just set the dfs [m - 1] to [m - weight(e)] will be alright.
 */
class FindPathLengthM {
private:
    Graph graph;
    int start;
    int M;
    std::vector<std::vector<int>> paths;
    std::unordered_set<int> visited;
    void FindPathLengthMDFS(Graph& graph, int start, int M, std::vector<int> pathBuilder);
public:
    /**
     * Return all the paths start from Node [start] of exact length M in Graph [graph]
     */
    std::vector<std::vector<int>> findPaths(Graph & graph, int start, int M);
};


#endif //GRAPH_FINDPATHLENGTHM_H
