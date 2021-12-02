#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "DatalogProgram.h"
#include "Database.h"
#include "Graph.h"

class Interpreter
{
private:
    DatalogProgram* datalogProgram;
    Database database;
    Relation evaluatePredicate(Predicate p);

public:
    Interpreter(DatalogProgram* datalogProgram);
    ~Interpreter();
    std::string Interpret();
};

#endif
