#ifndef PROJECT_1_DATALOGPROGRAM_H
#define PROJECT_1_DATALOGPROGRAM_H
#include "Predicate.h"
#include "Rules.h"
#include <set>

class DatalogProgram
{
private:
    std::set<std::string> domainOutput;
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Predicate*> queries;
    std::vector<Rules*> rules;

public:
    DatalogProgram(std::vector<Predicate*> schemes, std::vector<Predicate*> facts, std::vector<Predicate*> queries, std::vector<Rules*> rules);
    ~DatalogProgram();

    std::string toString();
    void convertFactsParameters();
};

#endif //PROJECT_1_DATALOGPROGRAM_H
