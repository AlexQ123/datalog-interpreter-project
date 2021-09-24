#include "Predicate.h"

Predicate::Predicate(std::string name) {
    this->name = name;
}

Predicate::~Predicate() {

}

void Predicate::setParameters(std::vector<Parameter *> parameters) {
    this->parameters = parameters;
}

std::vector<Parameter*> Predicate::getParameters() {
    return parameters;
}

std::string Predicate::toString() {
    std::string output = name + "(";
    for (size_t i = 0; i < parameters.size(); i++) {
        if (i == parameters.size() - 1) {
            output.append(parameters.at(i)->toString());
        }
        else {
            output.append(parameters.at(i)->toString());
            output.append(",");
        }
    }
    output.append(")");
    return output;
}

