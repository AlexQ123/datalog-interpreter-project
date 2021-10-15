#ifndef PROJECT_1_DATABASE_H
#define PROJECT_1_DATABASE_H

#include "Relation.h"
#include <map>

class Database
{
private:
    std::map<std::string, Relation*> tables;

public:
    Database();
    ~Database();
    void addTable(std::string name, Relation* relation);
    std::string toString();
    std::map<std::string, Relation*> getTables();
};

#endif //PROJECT_1_DATABASE_H