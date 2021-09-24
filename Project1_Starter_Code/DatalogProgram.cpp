#include "DatalogProgram.h"

DatalogProgram::DatalogProgram(std::vector<Predicate *> schemes, std::vector<Predicate *> facts,
                               std::vector<Predicate *> queries, std::vector<Rules *> rules) {
    this->schemes = schemes;
    this->facts = facts;
    this->queries = queries;
    this->rules = rules;
}

DatalogProgram::~DatalogProgram() {

}

void DatalogProgram::convertFactsParameters() {
    for (size_t i = 0; i < facts.size(); i++) {
        Predicate* currPredicate = facts.at(i);
        std::vector<Parameter*> currParameters = currPredicate->getParameters();
        for (size_t i = 0; i < currParameters.size(); i++) {
            std::string converted = "";
            converted = currParameters.at(i)->toString();
            domainOutput.insert(converted);
        }
    }
}

std::string DatalogProgram::toString() {
    std::string output = "Schemes(";
    output.append(std::to_string(schemes.size()));
    output.append("):\n");
    for (size_t i = 0; i < schemes.size(); i++) {
        output.append("  ");
        output.append(schemes.at(i)->toString());
        output.append("\n");
    }

    output.append("Facts(");
    output.append(std::to_string(facts.size()));
    output.append("):\n");
    for (size_t i = 0; i < facts.size(); i++) {
        output.append("  ");
        output.append(facts.at(i)->toString());
        output.append(".\n");
    }

    output.append("Rules(");
    output.append(std::to_string(rules.size()));
    output.append("):\n");
    for (size_t i = 0; i < rules.size(); i++) {
        output.append("  ");
        output.append(rules.at(i)->toString());
        output.append(".\n");
    }

    output.append("Queries(");
    output.append(std::to_string(queries.size()));
    output.append("):\n");
    for (size_t i = 0; i < queries.size(); i++) {
        output.append("  ");
        output.append(queries.at(i)->toString());
        output.append("?\n");
    }

    convertFactsParameters();
    output.append("Domain(");
    output.append(std::to_string(domainOutput.size()));
    output.append("):");
    std::set<std::string>::iterator it;
    for (it = domainOutput.begin(); it != domainOutput.end(); it++) {
        output.append("\n");
        output.append("  ");
        output.append(*it);
    }

    return output;

}
