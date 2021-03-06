#ifndef RULES_H
#define RULES_H
#include "Predicate.h"
#include <vector>

class Rules
{
private:
    Predicate* headPredicate;
    std::vector<Predicate*> predicates;

public:
    Rules();
    ~Rules();

    std::string toString();
    void setHeadPredicate(Predicate* headPredicate);
    void setPredicates(std::vector<Predicate*> predicates);
    Predicate* getHeadPredicate();
    std::vector<Predicate*> getPredicates();
};

#endif
