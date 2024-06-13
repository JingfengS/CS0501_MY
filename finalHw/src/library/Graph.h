//
// Created by Jingfeng Sun on 2024/6/13.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include <unordered_map>
#include <unordered_set>
#include <exception>


/**
 * This is my representation of graph
 * which uses adjacent list representation.
 */
class Graph {
private:
    std::unordered_map<int, std::unordered_set<int>> graph;
public:
    /**
     * Add vertex v to the graph
     */
    void addVertex(int v);

    /**
     * Add edge from v pointing to w to the graph
     */
    void addEdge(int v, int w);

    /**
     * Return all the nodes Vertex v is pointing
     */
    std::unordered_set<int>& neighbors(int v);

    Graph();

    int size() const;
};


#endif //GRAPH_GRAPH_H
