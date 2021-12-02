#ifndef DATABASE_H
#define DATABASE_H

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

#endif
