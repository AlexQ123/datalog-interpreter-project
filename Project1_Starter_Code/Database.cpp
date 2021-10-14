#include "Database.h"

Database::Database() {

}

Database::~Database() {

}

void Database::addTable(std::string name, Relation *relation) {
    tables[name] = relation;
}