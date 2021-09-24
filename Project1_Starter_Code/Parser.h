#ifndef PROJECT_1_PARSER_H
#define PROJECT_1_PARSER_H
#include "Token.h"
#include "Parameter.h"
#include "Predicate.h"
#include "Rules.h"
#include "DatalogProgram.h"
#include <vector>
#include <iostream>

class Parser
{
private:
    int index = 0;

    void ParseDatalogProgram(std::vector<Token*>& tokens);
    void ParseSCHEMES(std::vector<Token*>& tokens);
    void ParseCOLON(std::vector<Token*>& tokens);
    void ParseScheme(std::vector<Token*>& tokens);
    void ParseSchemeList(std::vector<Token*>& tokens);
    void ParseFACTS(std::vector<Token*>& tokens);
    void ParseFactList(std::vector<Token*>& tokens);
    void ParseRULES(std::vector<Token*>& tokens);
    void ParseRuleList(std::vector<Token*>& tokens);
    void ParseQUERIES(std::vector<Token*>& tokens);
    void ParseQuery(std::vector<Token*>& tokens);
    void ParseQueryList(std::vector<Token*>& tokens);
    void ParseEOF(std::vector<Token*>& tokens);
    void ParseFact(std::vector<Token*>& tokens);
    void ParseRule(std::vector<Token*>& tokens);
    void ParseID(std::vector<Token*>& tokens);
    void ParseLEFTPAREN(std::vector<Token*>& tokens);
    void ParseIdList(std::vector<Token*>& tokens, bool isFromScheme);
    void ParseRIGHTPAREN(std::vector<Token*>& tokens);
    void ParseSTRING(std::vector<Token*>& tokens);
    void ParseStringList(std::vector<Token*>& tokens);
    void ParsePERIOD(std::vector<Token*>& tokens);
    void ParseHeadPredicate(std::vector<Token*>& tokens, Rules* rule);
    void ParseCOLONDASH(std::vector<Token*>& tokens);
    void ParsePredicate(std::vector<Token*>& tokens, bool isFromQuery);
    void ParsePredicateList(std::vector<Token*>& tokens, bool isFromQuery);
    void ParseQMARK(std::vector<Token*>& tokens);
    void ParseParameter(std::vector<Token*>& tokens);
    void ParseParameterList(std::vector<Token*>& tokens, bool isFromQuery);
    void ParseCOMMA(std::vector<Token*>& tokens);

    std::vector<Parameter*> schemesParameters;
    std::vector<Parameter*> factsParameters;
    std::vector<Parameter*> queriesParameters;
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Predicate*> queries;
    std::vector<Parameter*> headParameters;
    std::vector<Parameter*> bodyParameters;
    std::vector<Predicate*> rulesPredicates;
    std::vector<Rules*> rules;

    DatalogProgram* datalogProgram;

public:
    Parser();
    ~Parser();

    void Parse(std::vector<Token*>& tokens);

    void printDatalogProgram() {
        std::cout << datalogProgram->toString();
    }

};

#endif //PROJECT_1_PARSER_H
