#ifndef PREDICATE_H
#define PREDICATE_H
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
    std::string getName();
};

#endif
