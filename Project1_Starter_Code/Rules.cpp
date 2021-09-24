#include "Rules.h"

Rules::Rules() {

}

Rules::~Rules() {

}

void Rules::setHeadPredicate(Predicate *headPredicate) {
    this->headPredicate = headPredicate;
}

void Rules::setPredicates(std::vector<Predicate *> predicates) {
    this->predicates = predicates;
}

std::string Rules::toString() {
    std::string output = headPredicate->toString();
    output.append(" :- ");
    for (size_t i = 0; i < predicates.size(); i++) {
        if (i == predicates.size() - 1) {
            output.append(predicates.at(i)->toString());
            output.append(".");
        }
        else {
            output.append(predicates.at(i)->toString());
            output.append(",");
        }
    }

    return output;
}