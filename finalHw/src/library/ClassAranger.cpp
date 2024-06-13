//
// Created by Jingfeng Sun on 2024/6/13.
//

#include "ClassAranger.h"

#include <utility>

void ClassAranger::addClass(int classId, const std::string& className) {
   classIdGraph.addVertex(classId);
   classId2className[classId] = className;
   className2classId[className] = classId;
}

void ClassAranger::addPrerequisite(int prerequisitedId, int classId) {
    classIdGraph.addEdge(prerequisitedId, classId);
}

std::string ClassAranger::getClassName(int classId) {
    if (classId2className.find(classId) == classId2className.end()) {
        throw std::runtime_error("No such class id!");
    }
    return classId2className[classId];
}

std::vector<std::string> ClassAranger::arrangeClasses() {
    topologicalOrder();
    for (const auto& classId : order) {
        result.push_back(classId2className[classId]);
    }
    return result;
}

std::vector<int> &ClassAranger::topologicalOrder() {
    std::unordered_map<int, int> Vertex2inDegree;
    std::deque<int> fringe;
    for (const auto& [key, value] : classId2className) {
        Vertex2inDegree[key] = 0;
    }
    for (const auto& [key, value] : classId2className) {
        for (const auto& neighbor : classIdGraph.neighbors(key)) {
            Vertex2inDegree[neighbor]++;
        }
    }
    for (const auto& [key, value] : Vertex2inDegree) {
        if (value == 0) {
            fringe.push_back(key);
        }
    }
    while (!fringe.empty()) {
        int v = fringe.front();
        fringe.pop_front();
        order.push_back(v);
        for (const auto& neighbor : classIdGraph.neighbors(v)) {
            Vertex2inDegree[neighbor]--;
            if (Vertex2inDegree[neighbor] == 0) {
                fringe.push_back(neighbor);
            }
        }
    }
    return order;
}

void ClassAranger::addPrerequisite(const std::string &className, const std::string &prerequisiteName) {
    addPrerequisite(className2classId[className], className2classId[prerequisiteName]);
}
