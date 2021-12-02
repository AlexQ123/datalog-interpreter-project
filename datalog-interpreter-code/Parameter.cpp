#include "Parameter.h"

Parameter::Parameter(Token *token) {
    this->token = token;
}

Parameter::~Parameter() {

}

std::string Parameter::toString() {
    return token->getDescription();
}