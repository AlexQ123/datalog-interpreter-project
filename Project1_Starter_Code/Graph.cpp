#include "Graph.h"

Graph::Graph(std::vector<Rules *> rules) {
    this->rules = rules;
    for (size_t i = 0; i < rules.size(); i++) {
        visited.push_back(false);
    }
}

Graph::Graph(std::map<int, std::set<int>> reverseAdjacencyList) {
    adjacencyList = reverseAdjacencyList;
    for (size_t i = 0; i < adjacencyList.size(); i++) {
        visited.push_back(false);
    }
}

Graph::~Graph() {

}

std::map<int, std::set<int>> Graph::getReverseAdjacencyList() {
    return reverseAdjacencyList;
}

void Graph::createDependencyGraph() {
    for (size_t i = 0; i < rules.size(); i++) {
        std::vector<Predicate*> predicates = rules.at(i)->getPredicates();
        for (size_t j = 0; j < predicates.size(); j++) {
            for (size_t k = 0; k < rules.size(); k++) {
                Predicate* headPredicate = rules.at(k)->getHeadPredicate();
                if (headPredicate->getName() == predicates.at(j)->getName()) {
                    std::map<int, std::set<int>>::iterator it = adjacencyList.find(i);
                    if (it == adjacencyList.end()) {
                        std::set<int> setToInsert = {static_cast<int>(k)};
                        adjacencyList.insert({i, setToInsert});
                    }
                    else {
                        it->second.insert(k);
                    }
                }
            }
        }
    }
    for (size_t i = 0; i < rules.size(); i++) {
        if (adjacencyList.find(i) == adjacencyList.end()) {
            adjacencyList[i];
        }
    }
}

void Graph::createReverseGraph() {
    std::map<int, std::set<int>>::iterator it;
    for (it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        int currentRule = it->first;
        std::map<int, std::set<int>>::iterator it2;
        for (it2 = adjacencyList.begin(); it2 != adjacencyList.end(); it2++) {
            std::set<int> verticesToCompare = it2->second;
            std::set<int>::iterator itSet;
            for (itSet = verticesToCompare.begin(); itSet != verticesToCompare.end(); itSet++) {
                if (*itSet == currentRule) {
                    std::map<int, std::set<int>>::iterator itFind = reverseAdjacencyList.find(currentRule);
                    if (itFind == reverseAdjacencyList.end()) {
                        std::set<int> setToInsert = {it2->first};
                        reverseAdjacencyList.insert({currentRule, setToInsert});
                    }
                    else {
                        itFind->second.insert(it2->first);
                    }
                }
            }
        }
    }
    for (size_t i = 0; i < rules.size(); i++) {
        if (reverseAdjacencyList.find(i) == reverseAdjacencyList.end()) {
            reverseAdjacencyList[i];
        }
    }
}

std::string Graph::graphToString() {
    std::string output = "Dependency Graph\n";
    std::map<int, std::set<int>>::iterator it;
    for (it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        output.append("R");
        output.append(std::to_string(it->first));
        output.append(":");
        std::set<int> setToPrint = it->second;
        std::set<int>::iterator itSet;
        for (itSet = setToPrint.begin(); itSet != setToPrint.end(); itSet++) {
            if ((itSet) != setToPrint.begin()) {
                output.append(",");
            }
            output.append("R");
            output.append(std::to_string(*itSet));
        }
        output.append("\n");
    }
    return output;
}

std::string Graph::reverseGraphToString() {
    std::string output = "Reverse Dependency Graph\n";
    std::map<int, std::set<int>>::iterator it;
    for (it = reverseAdjacencyList.begin(); it != reverseAdjacencyList.end(); it++) {
        output.append(std::to_string(it->first));
        output.append(":");
        std::set<int> setToPrint = it->second;
        std::set<int>::iterator itSet;
        for (itSet = setToPrint.begin(); itSet != setToPrint.end(); itSet++) {
            if ((itSet) != setToPrint.begin()) {
                output.append(",");
            }
            output.append(std::to_string(*itSet));
        }
        output.append("\n");
    }
    return output;
}

void Graph::DFSForest() {
    for (size_t i = 0; i < adjacencyList.size(); i++) {
        visited[i] = false;
    }

    for (size_t i = 0; i < adjacencyList.size(); i++) {
        if (!(visited.at(i))) {
            std::vector<int> tree;
            DFS(i, tree);
            forest.push_back(tree);
        }
    }
}

void Graph::DFS(int v, std::vector<int> &tree) {
    visited.at(v) = true;
    tree.push_back(v);
    std::map<int, std::set<int>>::iterator it = adjacencyList.find(v);
    std::set<int> vAdjacentVertices = it->second;
    std::set<int>::iterator itSet;
    for (itSet = vAdjacentVertices.begin(); itSet != vAdjacentVertices.end(); itSet++) {
        if (!(visited.at(*itSet))) {
            DFS(*itSet, tree);
        }
    }
    postorder.push_back(v);
}

std::vector<int> Graph::getReversePostorder() {
//    std::vector<int> reversePostorder;
//    for (size_t i = 0; i < forest.size(); i++) {
//        for (size_t j = forest.at(i).size(); j --> 0;) {
//            reversePostorder.push_back(forest.at(i).at(j));
//        }
//    }
    std::vector<int> reversePostorder = postorder;
    std::reverse(reversePostorder.begin(), reversePostorder.end());
    return reversePostorder;
}

void Graph::DFSForestPostorder(std::vector<int> postorder) {
    for (size_t i = 0; i < adjacencyList.size(); i++) {
        visited[postorder.at(i)] = false;
    }

    for (size_t i = 0; i < adjacencyList.size(); i++) {
        if(!(visited.at(postorder.at(i)))) {
            std::vector<int> tree;
            DFS(postorder.at(i), tree);
            forest.push_back(tree);
        }
    }
}

std::vector<std::vector<int>> Graph::getForest() {
    return forest;
}