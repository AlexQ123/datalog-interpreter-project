#include "Relation.h"
#include <iostream>

Relation::Relation(std::string name, Header header) {
    this->name = name;
    this->header = header;
}

Relation::~Relation() {

}

std::string Relation::toString() {
    std::string output = "";
    std::vector<std::string> attributesToPrint = this->header.getAttributes();
    std::set<Tuple>::iterator it;
    for (it = tuples.begin(); it != tuples.end(); it++) {
        Tuple currentTuple = *it;
        output.append("  ");
        for (size_t i = 0; i < attributesToPrint.size(); i++) {
            // output.append("  ");
            if (i == attributesToPrint.size() - 1) {
                output.append(attributesToPrint.at(i));
                output.append("=");
                output.append(currentTuple.getValues().at(i));
                output.append("\n");
            }
            else {
                output.append(attributesToPrint.at(i));
                output.append("=");
                output.append(currentTuple.getValues().at(i));
                output.append(", ");
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
        for (size_t i = 0; i < indices.size(); i++) {
            std::string newString = currentTupleValues.at(indices.at(i));
            newValues.push_back(newString);
        }

        Tuple newTuple(newValues);

        tuplesToAdd.insert(newTuple);
    }

    newRelation.setTuples(tuplesToAdd);
    return newRelation;
}

Relation Relation::rename(std::vector<std::string> newAttributes) {
    Header newHeader;
    newHeader.setAttributes(newAttributes);

    Relation newRelation(this->name, newHeader);
    newRelation.setTuples(this->tuples);

    return newRelation;
}

Relation Relation::join(Relation r2) {
    //create the new header
    Header newHeader;
    std::vector<std::string> r1attributes = header.getAttributes();
    std::vector<std::string> r2attributes = r2.getHeader().getAttributes();
    std::vector<std::string> newAttributes = r1attributes;
    std::vector<int> r1MatchingIndices;
    std::vector<int> r2MatchingIndices;
    std::vector<int> r2UniqueIndices;
    for (size_t i = 0; i < r2attributes.size(); i++) {
        bool isUnique = true;
        for (size_t j = 0; j < newAttributes.size(); j++) {
            if (r2attributes.at(i) == newAttributes.at(j)) {
                isUnique = false;
                r1MatchingIndices.push_back(j);
            }
        }
        if (isUnique) {
            newAttributes.push_back(r2attributes.at(i));
            r2UniqueIndices.push_back(i);
        }
        else {
            r2MatchingIndices.push_back(i);
        }
    }
    newHeader.setAttributes(newAttributes);

    //create empty relation using the new header
    std::string tempName = name + "+" + r2.getName();
    Relation newRelation(tempName, newHeader);

    //combine tuples
    std::set<Tuple>::iterator it1;
    std::set<Tuple>::iterator it2;
    for (it1 = tuples.begin(); it1 != tuples.end(); it1++) {
        for (it2 = r2.getTuples().begin(); it2 != r2.getTuples().end(); it2++) {
            bool joinable = isJoinable(*it1, *it2, r1MatchingIndices, r2MatchingIndices);
            if (joinable) {
                Tuple newTuple = combineTuples(*it1, *it2, r2UniqueIndices);
                newRelation.addTuple(newTuple);
            }
        }
    }

    return newRelation;
}

bool Relation::isJoinable(Tuple t1, Tuple t2, const std::vector<int>& t1indices, const std::vector<int>& t2indices) {
    bool joinable = true;
    for (size_t i = 0; i < t1indices.size(); i++) {
        if (t1.getValues().at(t1indices.at(i)) != t2.getValues().at(t2indices.at(i))) {
            joinable = false;
        }
    }
    return joinable;
}

Tuple Relation::combineTuples(Tuple t1, Tuple t2, const std::vector<int>& t2Indices) {
    std::vector<std::string> newValues = t1.getValues();
    for (size_t i = 0; i < t2Indices.size(); i++) {
        newValues.push_back(t2.getValues().at(t2Indices.at(i)));
    }
    Tuple newTuple(newValues);
    return newTuple;
}

bool Relation::unionRelations(Relation r) {
    bool added = false;
    std::set<Tuple>::iterator it;
    Relation uniqueRelation("", r.getHeader());
    for (it = r.getTuples().begin(); it != r.getTuples().end(); it++) {
        if (tuples.insert(*it).second) {
            added = true;
            uniqueRelation.addTuple(*it);
        }
    }
    std::cout << uniqueRelation.toString();
    return added;
}

void Relation::setTuples(std::set<Tuple> tuples) {
    this->tuples = tuples;
}

void Relation::addTuple(Tuple tuple) {
    this->tuples.insert(tuple);
}

const std::set<Tuple>& Relation::getTuples() {
    return tuples;
}

Header Relation::getHeader() {
    return header;
}

void Relation::setName(std::string name) {
    this->name = name;
}

std::string Relation::getName() {
    return name;
}
