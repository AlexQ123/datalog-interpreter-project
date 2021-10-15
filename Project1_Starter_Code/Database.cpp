#include "Database.h"

Database::Database() {

}

Database::~Database() {

}

void Database::addTable(std::string name, Relation *relation) {
    tables[name] = relation;
}

std::string Database::toString() {
    std::string output = "";
    std::map<std::string, Relation*>::iterator it;
    for (it = tables.begin(); it != tables.end(); it++) {
        output.append(it->first);
        output.append(":\n");
        output.append(it->second->toString());
        output.append("\n");
    }
    return output;
}

std::map<std::string, Relation *> Database::getTables() {
    return tables;
}