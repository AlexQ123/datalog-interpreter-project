#include "Relation.h"

Relation::Relation(std::string name, Header header) {
    this->name = name;
    this->header = header;
}

Relation::~Relation() {

}

void Relation::setTuples(std::set<Tuple> tuples) {
    this->tuples = tuples;
}

std::string Relation::toString() {
    std::string output = "";
    std::vector<std::string> attributesToPrint = this->header.getAttributes();
    std::set<Tuple>::iterator it;
    for (it = tuples.begin(); it != tuples.end(); it++) {
        Tuple currentTuple = *it;
        for (size_t i = 0; i < attributesToPrint.size(); i++) {
            if (i == attributesToPrint.size() - 1) {
                output.append(attributesToPrint.at(i));
                output.append("='");
                output.append(currentTuple.getValues().at(i));
                output.append("'\n");
            }
            else {
                output.append(attributesToPrint.at(i));
                output.append("='");
                output.append(currentTuple.getValues().at(i));
                output.append("', ");
            }
        }
    }
    return output;
}

Relation Relation::select(int index, std::string value) {
    Relation newRelation(this->name, this->header);
    std::set<Tuple> tuplesToAdd;

    std::set<Tuple>::iterator it;
    for (it = tuples.begin(); it != tuples.end(); it++) {
        Tuple currentTuple = *it;
        if (currentTuple.getValues().at(index) == value) {
            tuplesToAdd.insert(currentTuple);
        }
    }

    newRelation.setTuples(tuplesToAdd);
    return newRelation;
}

Relation Relation::select(std::vector<int> indices) {
    Relation newRelation(this->name, this->header);
    std::set<Tuple> tuplesToAdd;

    std::set<Tuple>::iterator it;
    for (it = tuples.begin(); it != tuples.end(); it++) {
        Tuple currentTuple = *it;
        bool isAllEqual = true;
        for (size_t i = 0; i < indices.size(); i++) {
            if (currentTuple.getValues().at(indices.at(i)) != currentTuple.getValues().at(indices.at(0))) {
                isAllEqual = false;
            }
        }
        if (isAllEqual) {
            tuplesToAdd.insert(currentTuple);
        }
    }

    newRelation.setTuples(tuplesToAdd);
    return newRelation;
}

Relation Relation::project(std::vector<int> indices) {
    Header newHeader;
    std::vector<std::string> newAttributes;
    for (size_t i = 0; i < indices.size(); i++) {
        std::string newString = this->header.getAttributes().at(indices.at(i));
        newAttributes.push_back(newString);
    }
    newHeader.setAttributes(newAttributes);

    Relation newRelation(this->name, newHeader);

    std::set<Tuple> tuplesToAdd;
    std::set<Tuple>::iterator it;
    for (it = tuples.begin(); it != tuples.end(); it++) {
        Tuple currentTuple = *it;
        std::vector<std::string> newValues;

        std::vector<std::string> currentTupleValues = currentTuple.getValues();
        for (size_t i = 0; i < currentTupleValues.size(); i++) {
            std::string newString = currentTuple.getValues().at(indices.at(i));
            newValues.push_back(newString);
        }

        Tuple newTuple(newValues);

        tuplesToAdd.insert(newTuple);
    }

    newRelation.setTuples(tuplesToAdd);
    return newRelation;
}


