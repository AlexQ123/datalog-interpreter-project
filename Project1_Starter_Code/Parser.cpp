#include "Parser.h"

Parser::Parser() {

}

Parser::~Parser() {

}

void Parser::Parse(std::vector<Token *> &tokens) {
    ParseDatalogProgram(tokens);
}

void Parser::ParseDatalogProgram(std::vector<Token *> &tokens) {
    //Production: datalogProgram -> SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
    if (tokens.at(index)->getType() == TokenType::SCHEMES){
        ParseSCHEMES(tokens);
        ParseCOLON(tokens);
        ParseScheme(tokens);
        ParseSchemeList(tokens);
        ParseFACTS(tokens);
        ParseCOLON(tokens);
        ParseFactList(tokens);
        ParseRULES(tokens);
        ParseCOLON(tokens);
        ParseRuleList(tokens);
        ParseQUERIES(tokens);
        ParseCOLON(tokens);
        ParseQuery(tokens);
        ParseQueryList(tokens);
        ParseEOF(tokens);
        datalogProgram = new DatalogProgram(schemes, facts, queries, rules);
    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseSCHEMES(std::vector<Token *> &tokens) {
    if (tokens.at(index)->getType() == TokenType::SCHEMES) {
        index++;
    }
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseCOLON(std::vector<Token *> &tokens) {
    if (tokens.at(index)->getType() == TokenType::COLON) {
        index++;
    }
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseScheme(std::vector<Token *> &tokens) {
    //Production: scheme -> ID LEFT_PAREN ID idList RIGHT_PAREN
    if (tokens.at(index)->getType() == TokenType::ID) {
        //create and set the name of schemePredicate
        Predicate* schemePredicate = new Predicate(tokens.at(index)->getDescription());
        ParseID(tokens);
        ParseLEFTPAREN(tokens);
        //create a parameter and add it to vector of schemeParameters
        Parameter* parameter = new Parameter(tokens.at(index));
        schemesParameters.push_back(parameter);
        ParseID(tokens);
        bool isFromScheme = true;
        ParseIdList(tokens, isFromScheme);
        //after you're done parsing all of the IDs that are parameters, set parameters of schemePredicate
        schemePredicate->setParameters(schemesParameters);
        schemesParameters.clear();
        //then, add schemePredicate to the vector of schemes
        schemes.push_back(schemePredicate);
        ParseRIGHTPAREN(tokens);
    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseSchemeList(std::vector<Token *> &tokens) {
    //Production: schemeList ->	scheme schemeList
    if (tokens.at(index)->getType() == TokenType::ID) {
        ParseScheme(tokens);
        ParseSchemeList(tokens);
    }
    //Production: schemeList -> lambda
    else if (tokens.at(index)->getType() == TokenType::FACTS) {

    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseFACTS(std::vector<Token *> &tokens) {
    if (tokens.at(index)->getType() == TokenType::FACTS) {
        index++;
    }
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseFactList(std::vector<Token *> &tokens) {
    //Production: factList -> fact factList
    if (tokens.at(index)->getType() == TokenType::ID) {
        ParseFact(tokens);
        ParseFactList(tokens);
    }
    //Production: factList -> lambda
    else if (tokens.at(index)->getType() == TokenType::RULES) {

    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseRULES(std::vector<Token *> &tokens) {
    if (tokens.at(index)->getType() == TokenType::RULES) {
        index++;
    }
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseRuleList(std::vector<Token *> &tokens) {
    //Production: ruleList -> rule ruleList
    if (tokens.at(index)->getType() == TokenType::ID) {
        ParseRule(tokens);
        ParseRuleList(tokens);
    }
    //Production: ruleList -> lambda
    else if (tokens.at(index)->getType() == TokenType::QUERIES) {

    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseQUERIES(std::vector<Token *> &tokens) {
    if (tokens.at(index)->getType() == TokenType::QUERIES) {
        index++;
    }
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseQuery(std::vector<Token *> &tokens) {
    //Production: query -> predicate Q_MARK
    if (tokens.at(index)->getType() == TokenType::ID) {
        bool isFromQuery = true;
        ParsePredicate(tokens, isFromQuery);
        ParseQMARK(tokens);
    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseQueryList(std::vector<Token *> &tokens) {
    //Production: queryList -> query queryList
    if (tokens.at(index)->getType() == TokenType::ID) {
        ParseQuery(tokens);
        ParseQueryList(tokens);
    }
    //Production: queryList -> lambda
    else if (tokens.at(index)->getType() == TokenType::END_FILE) {

    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseEOF(std::vector<Token *> &tokens) {
    if (tokens.at(index)->getType() == TokenType::END_FILE) {
        index++;
    }
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseFact(std::vector<Token *> &tokens) {
    //Production: fact -> ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    if (tokens.at(index)->getType() == TokenType::ID) {
        //create and set name of factPredicate
        Predicate* factPredicate = new Predicate(tokens.at(index)->getDescription());
        ParseID(tokens);
        ParseLEFTPAREN(tokens);
        //create a parameter and add it to vector of factsParameters
        Parameter* parameter = new Parameter(tokens.at(index));
        factsParameters.push_back(parameter);
        ParseSTRING(tokens);
        ParseStringList(tokens);
        //after you're done parsing all of the STRINGS that are parameters, set parameters of factPredicate
        factPredicate->setParameters(factsParameters);
        factsParameters.clear();
        //then, add factPredicate to the vector of facts
        facts.push_back(factPredicate);
        ParseRIGHTPAREN(tokens);
        ParsePERIOD(tokens);
    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseRule(std::vector<Token *> &tokens) {
    //Production: rule -> headPredicate COLON_DASH predicate predicateList PERIOD
    if (tokens.at(index)->getType() == TokenType::ID) {
        //create a rule
        Rules* rule = new Rules();
        ParseHeadPredicate(tokens, rule);
        ParseCOLONDASH(tokens);
        bool isFromQuery = false;
        ParsePredicate(tokens, isFromQuery);
        ParsePredicateList(tokens, isFromQuery);
        //set bodyPredicates for rule
        rule->setPredicates(rulesPredicates);
        rules.push_back(rule);
        ParsePERIOD(tokens);
    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseID(std::vector<Token *> &tokens) {
    if (tokens.at(index)->getType() == TokenType::ID) {
        index++;
    }
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseLEFTPAREN(std::vector<Token *> &tokens) {
    if (tokens.at(index)->getType() == TokenType::LEFT_PAREN) {
        index++;
    }
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseIdList(std::vector<Token *> &tokens, bool isFromScheme) {
    //Production: idList -> COMMA ID IDList
    if (tokens.at(index)->getType() == TokenType::COMMA) {
        ParseCOMMA(tokens);
        if (isFromScheme) {
            //create a parameter and add it to vector of schemeParameters
            Parameter* parameter = new Parameter(tokens.at(index));
            schemesParameters.push_back(parameter);
        }
        else {
            //create a parameter and add it to vector of parameters for the headPredicate
            Parameter* parameter = new Parameter(tokens.at(index));
            headParameters.push_back(parameter);
        }
        ParseID(tokens);
        ParseIdList(tokens, isFromScheme);
    }
    //Production: idList -> lambda
    else if (tokens.at(index)->getType() == TokenType::RIGHT_PAREN) {

    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseRIGHTPAREN(std::vector<Token *> &tokens) {
    if (tokens.at(index)->getType() == TokenType::RIGHT_PAREN) {
        index++;
    }
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseSTRING(std::vector<Token *> &tokens) {
    if (tokens.at(index)->getType() == TokenType::STRING) {
        index++;
    }
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseStringList(std::vector<Token *> &tokens) {
    //Production: stringList -> COMMA STRING stringList
    if (tokens.at(index)->getType() == TokenType::COMMA) {
        ParseCOMMA(tokens);
        //create a parameter and add it to vector of factsParameters
        Parameter* parameter = new Parameter(tokens.at(index));
        factsParameters.push_back(parameter);
        ParseSTRING(tokens);
        ParseStringList(tokens);
    }
    //Production: stringList -> lambda
    else if (tokens.at(index)->getType() == TokenType::RIGHT_PAREN) {

    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParsePERIOD(std::vector<Token *> &tokens) {
    if (tokens.at(index)->getType() == TokenType::PERIOD) {
        index++;
    }
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseHeadPredicate(std::vector<Token *> &tokens, Rules* rule) {
    //Production: headPredicate -> ID LEFT_PAREN ID idList RIGHT_PAREN
    if (tokens.at(index)->getType() == TokenType::ID) {
        //create and set the name of headPredicate
        Predicate* headPredicate = new Predicate(tokens.at(index)->getDescription());
        ParseID(tokens);
        ParseLEFTPAREN(tokens);
        //create a parameter and add it to vector of parameters for the headPredicate
        Parameter* parameter = new Parameter(tokens.at(index));
        headParameters.push_back(parameter);
        ParseID(tokens);
        bool isFromScheme = false;
        ParseIdList(tokens, isFromScheme);
        //after you're done parsing all of the IDs that are parameters, set parameters for headParameters
        headPredicate->setParameters(headParameters);
        headParameters.clear();
        rule->setHeadPredicate(headPredicate);
        ParseRIGHTPAREN(tokens);
    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseCOLONDASH(std::vector<Token *> &tokens) {
    if (tokens.at(index)->getType() == TokenType::COLON_DASH) {
        index++;
    }
    else {
        throw tokens.at(index);
    }
}

void Parser::ParsePredicate(std::vector<Token *> &tokens, bool isFromQuery) {
    //Production: predicate -> ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    if (tokens.at(index)->getType() == TokenType::ID) {
        if (isFromQuery) {
            //create and set the name of queryPredicate
            Predicate* queryPredicate = new Predicate(tokens.at(index)->getDescription());
            ParseID(tokens);
            ParseLEFTPAREN(tokens);
            //create a parameter and add it to vector of queryParameters
            Parameter* parameter = new Parameter(tokens.at(index));
            queriesParameters.push_back(parameter);
            ParseParameter(tokens);
            ParseParameterList(tokens, isFromQuery);
            //after you're done parsing all of the Parameters that are parameters, set parameters of queryPredicate
            queryPredicate->setParameters(queriesParameters);
            queriesParameters.clear();
            //then, add queryPredicate to the vector of queries
            queries.push_back(queryPredicate);
            ParseRIGHTPAREN(tokens);
        }
        else {
            //create and set the name of bodyPredicate
            Predicate* bodyPredicate = new Predicate(tokens.at(index)->getDescription());
            ParseID(tokens);
            ParseLEFTPAREN(tokens);
            //create a parameter and add it to vector of bodyParameters
            Parameter* parameter = new Parameter(tokens.at(index));
            bodyParameters.push_back(parameter);
            ParseParameter(tokens);
            ParseParameterList(tokens, isFromQuery);
            //after you're done parsing all of the Parameters that are parameters, set parameters of queryPredicate
            bodyPredicate->setParameters(bodyParameters);
            bodyParameters.clear();
            //then, add bodyPredicate to the vector of rulesPredicates
            rulesPredicates.push_back(bodyPredicate);
            ParseRIGHTPAREN(tokens);
        }
    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParsePredicateList(std::vector<Token *> &tokens, bool isFromQuery) {
    //Production: predicateList -> COMMA predicate predicateList
    if (tokens.at(index)->getType() == TokenType::COMMA) {
        ParseCOMMA(tokens);
        ParsePredicate(tokens, isFromQuery);
        ParsePredicateList(tokens, isFromQuery);
    }
    //Production: predicateList -> lambda
    else if (tokens.at(index)->getType() == TokenType::PERIOD) {

    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseQMARK(std::vector<Token *> &tokens) {
    if (tokens.at(index)->getType() == TokenType::Q_MARK) {
        index++;
    }
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseParameter(std::vector<Token *> &tokens) {
    //Production: parameter -> STRING
    if (tokens.at(index)->getType() == TokenType::STRING) {
        ParseSTRING(tokens);
    }
    //Production: parameter -> ID
    else if (tokens.at(index)->getType() == TokenType::ID) {
        ParseID(tokens);
    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseParameterList(std::vector<Token *> &tokens, bool isFromQuery) {
    //Production: parameterList -> COMMA parameter parameterList
    if (tokens.at(index)->getType() == TokenType::COMMA) {
        ParseCOMMA(tokens);
        if (isFromQuery) {
            //create a parameter and add it to vector of queryParameters
            Parameter* parameter = new Parameter(tokens.at(index));
            queriesParameters.push_back(parameter);
        }
        else {
            //create a parameter and add it to vector of bodyParameters
            Parameter* parameter = new Parameter(tokens.at(index));
            bodyParameters.push_back(parameter);
        }
        ParseParameter(tokens);
        ParseParameterList(tokens, isFromQuery);
    }
    //Production: parameterList -> lambda
    else if (tokens.at(index)->getType() == TokenType::RIGHT_PAREN) {

    }
    //Input does not match any producible terminals
    else {
        throw tokens.at(index);
    }
}

void Parser::ParseCOMMA(std::vector<Token *> &tokens) {
    if (tokens.at(index)->getType() == TokenType::COMMA) {
        index++;
    }
    else {
        throw tokens.at(index);
    }
}


