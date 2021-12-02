#ifndef PROJECT_1_PARAMETER_H
#define PROJECT_1_PARAMETER_H
#include "Token.h"

class Parameter
{
private:
    Token* token;

public:
    Parameter(Token* token);
    ~Parameter();

    std::string toString();
};

#endif //PROJECT_1_PARAMETER_H
