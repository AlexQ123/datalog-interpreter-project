#ifndef PARAMETER_H
#define PARAMETER_H
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

#endif
