#ifndef PROJECT_1_PREDICATE_H
#define PROJECT_1_PREDICATE_H
#include "Parameter.h"
#include <vector>

class Predicate
{
private:
    std::string name = "";
    std::vector<Parameter*> parameters;

public:
    Predicate(std::string name);
    ~Predicate();

    void setParameters(std::vector<Parameter*> parameters);
    std::vector<Parameter*> getParameters();
    std::string toString();
};

#endif //PROJECT_1_PREDICATE_H
