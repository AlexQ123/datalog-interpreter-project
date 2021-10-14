#ifndef PROJECT_1_RELATION_H
#define PROJECT_1_RELATION_H

#include "Tuple.h"
#include "Header.h"
#include <string>
#include <set>

class Relation
{
private:
    std::string name;
    Header header;
    std::set<Tuple> tuples;

public:
    Relation(std::string name, Header header);
    ~Relation();
    void setTuples(std::set<Tuple> tuples);
    std::string toString();
    Relation select(int index, std::string value);
    Relation select(std::vector<int> indices);
    Relation project(std::vector<int> indices);
    Relation rename(std::vector<std::string> newAttributes);
};

#endif //PROJECT_1_RELATION_H
