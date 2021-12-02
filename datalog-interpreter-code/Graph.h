#ifndef PROJECT_1_GRAPH_H
#define PROJECT_1_GRAPH_H

#include "Rules.h"
#include <map>
#include <set>
#include <algorithm>

class Graph
{
private:
    std::vector<Rules*> rules;
    std::map<int, std::set<int>> adjacencyList;
    std::map<int, std::set<int>> reverseAdjacencyList;
    std::vector<bool> visited;
    std::vector<std::vector<int>> forest;
    std::vector<int> postorder;

public:
    Graph(std::vector<Rules*> rules);
    Graph(std::map<int, std::set<int>> reverseAdjacencyList);
    ~Graph();
    std::map<int, std::set<int>> getReverseAdjacencyList();
    void createDependencyGraph();
    void createReverseGraph();
    std::string graphToString();
    std::string reverseGraphToString();
    void DFSForest();
    void DFS(int v, std::vector<int> &tree);
    std::vector<int> getReversePostorder();
    void DFSForestPostorder(std::vector<int> postorder);
    std::vector<std::vector<int>> getForest();
};

#endif //PROJECT_1_GRAPH_H
