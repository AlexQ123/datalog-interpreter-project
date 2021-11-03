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
    void addTuple(Tuple tuple);
    std::string toString();
    Relation select(int index, std::string value);
    Relation select(std::vector<int> indices);
    Relation project(std::vector<int> indices);
    Relation rename(std::vector<std::string> newAttributes);
    Relation join(Relation r2);
    bool isJoinable(Tuple t1, Tuple t2, const std::vector<int>& t1indices, const std::vector<int>& t2indices);
    Tuple combineTuples(Tuple t1, Tuple t2, const std::vector<int>& t2Indices);
    const std::set<Tuple>& getTuples();
    Header getHeader();
    void setName(std::string name);
    std::string getName();
};

#endif //PROJECT_1_RELATION_H
