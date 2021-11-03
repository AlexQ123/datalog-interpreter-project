#include "Tuple.h"

Tuple::Tuple(std::vector<std::string> values) {
    this->values = values;
}

Tuple::~Tuple() {

}

const std::vector<std::string>& Tuple::getValues() {
    return values;
}