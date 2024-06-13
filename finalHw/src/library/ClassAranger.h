//
// Created by Jingfeng Sun on 2024/6/13.
//

#ifndef GRAPH_CLASSARANGER_H
#define GRAPH_CLASSARANGER_H
#include "Graph.h"
#include <string>
#include <vector>
#include <deque>


class ClassAranger {
private:
    Graph classIdGraph;
    std::unordered_map<int, std::string> classId2className;
    std::unordered_map<std::string, int> className2classId;
    std::vector<int>& topologicalOrder();
    std::vector<int> order;
    std::vector<std::string> result;
public:
    /**
     * Add a class to the class aranger
     */
    void addClass(int classId, const std::string& className);

    /**
     * Add a prerequisite to the class aranger
     */
    void addPrerequisite(int classId, int prerequisiteId);
    void addPrerequisite(const std::string& className, const std::string& prerequisiteName);

    /**
     * Return the class name of the class id
     */
    std::string getClassName(int classId);

    /**
     * Arrange a plan for students to finish their classes as fast as possible
     * Note that this method will use topological sort to arrange the classes
     */
    std::vector<std::string> arrangeClasses();

};


#endif //GRAPH_CLASSARANGER_H
