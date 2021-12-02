#ifndef PROJECT_1_INTERPRETER_H
#define PROJECT_1_INTERPRETER_H

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

#endif //PROJECT_1_INTERPRETER_H
