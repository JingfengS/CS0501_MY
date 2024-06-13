//
// Created by Jingfeng Sun on 2024/6/13.
//

#include "Graph.h"

void Graph::addVertex(int v) {
    if (graph.find(v) != graph.end()) {
        throw std::runtime_error("Vertex already in graph!");
    }
    graph.insert(std::make_pair(v, std::unordered_set<int>()));
}

void Graph::addEdge(int v, int w) {
    if (graph.find(v) == graph.end() || graph.find(w) == graph.end()) {
        throw std::runtime_error("No such vertex v or w!");
    }
    graph[v].insert(w);
}

std::unordered_set<int> &Graph::neighbors(int v) {
    if (graph.find(v) == graph.end()) {
        throw std::runtime_error("No such vertex v or w!");
    }
    return graph[v];
}

int Graph::size() const {
    return graph.size();
}

Graph::Graph() = default;
