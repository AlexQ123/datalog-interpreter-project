#include "Interpreter.h"

Interpreter::Interpreter(DatalogProgram *datalogProgram) {
    this->datalogProgram = datalogProgram;
}

Interpreter::~Interpreter() {

}

Relation Interpreter::evaluatePredicate(Predicate p) {
    //create the relation that we eventually want to return, completely empty
    Header dummyHeader;
    std::vector<std::string> emptyAttributes;
    dummyHeader.setAttributes(emptyAttributes);
    Relation myRelation("", dummyHeader);
    //get the relation with the same name as the current query
    std::map<std::string, Relation*> tablesToCheck = database.getTables();
    std::map<std::string, Relation*>::iterator it;
    for (it = tablesToCheck.begin(); it != tablesToCheck.end(); it++) {
        if (it->first == p.getName()) {
            myRelation = *(it->second);
        }
    }

    std::vector<Parameter*> currentParameters = p.getParameters();
    std::set<std::string> alreadySeen;
    std::vector<int> variableColumns;
    std::vector<int> selectVariableColumns;
    std::vector<std::string> renameAttributes;
    for (size_t i = 0; i < currentParameters.size(); i++) {
        std::string currentParameter = currentParameters.at(i)->toString();
        //select for each constant
        if (currentParameter[0] == '\'') {
            myRelation = myRelation.select(i, currentParameter);
        }
        //select type 2
        else {
            variableColumns.push_back(i);
            renameAttributes.push_back(currentParameter);
            if (alreadySeen.find(currentParameter) != alreadySeen.end()) {
                selectVariableColumns.push_back(i);
                myRelation = myRelation.select(selectVariableColumns);
            }
            else {
                alreadySeen.insert(currentParameter);
                selectVariableColumns.push_back(i);
            }
        }
    }

    //project
    myRelation = myRelation.project(variableColumns);

    //rename
    myRelation = myRelation.rename(renameAttributes);

    return myRelation;
}

std::string Interpreter::Interpret() {
    //creating a new relation from each scheme
    std::vector<Predicate*> schemes = datalogProgram->getSchemes();
    for (size_t i = 0; i < schemes.size(); i++) {
        std::string newName = schemes.at(i)->getName();
        Header newHeader;
        std::vector<std::string> newAttributes;
        std::vector<Parameter*> currentParameters = schemes.at(i)->getParameters();
        for (size_t i = 0; i < currentParameters.size(); i++) {
            std::string currentAttribute = currentParameters.at(i)->toString();
            newAttributes.push_back(currentAttribute);
        }
        newHeader.setAttributes(newAttributes);
        Relation* newRelation = new Relation(newName, newHeader);
        database.addTable(newName, newRelation);
    }

    //make a tuple for each fact and add it to the corresponding relation
    std::vector<Predicate*> facts = datalogProgram->getFacts();
    for (size_t i = 0; i < facts.size(); i++) {
        std::vector<std::string> newValues;
        std::vector<Parameter*> currentParameters = facts.at(i)->getParameters();
        for (size_t i = 0; i < currentParameters.size(); i++) {
            std::string currentValue = currentParameters.at(i)->toString();
            newValues.push_back(currentValue);
        }
        Tuple newTuple(newValues);
        std::map<std::string, Relation*> tablesToCheck = database.getTables();
        std::map<std::string, Relation*>::iterator it;
        for (it = tablesToCheck.begin(); it != tablesToCheck.end(); it++) {
            if (it->first == facts.at(i)->getName()) {
                it->second->addTuple(newTuple);
            }
        }
    }

    //evaluate each query and tostring for output
    std::string output = "";
    std::vector<Predicate*> queries = datalogProgram->getQueries();
    for (size_t i = 0; i < queries.size(); i++) {
        output.append(queries.at(i)->toString());
        output.append("? ");
        Predicate predicateToEvaluate = *queries.at(i);
        Relation resultingRelation = evaluatePredicate(predicateToEvaluate);
        if (resultingRelation.getTuples().size() == 0) {
            output.append("No\n");
        }
        else {
            output.append("Yes(");
            output.append(std::to_string(resultingRelation.getTuples().size()));
            output.append(")\n");
        }
        output.append(resultingRelation.toString());
    }

    return output;
}
